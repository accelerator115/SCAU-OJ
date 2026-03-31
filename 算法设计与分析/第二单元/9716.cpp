#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Rect {
    double x1, y1, x2, y2;
};

int main() {
    int n;
    cin >> n;
    vector<Rect> rects(n);
    vector<double> xs, ys;
    for (int i = 0; i < n; i++) {
        cin >> rects[i].x1 >> rects[i].y1 >> rects[i].x2 >> rects[i].y2;
        xs.push_back(rects[i].x1);
        xs.push_back(rects[i].x2);
        ys.push_back(rects[i].y1);
        ys.push_back(rects[i].y2);
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    double area = 0.0;
    for (int i = 0; i < xs.size() - 1; i++) {
        for (int j = 0; j < ys.size() - 1; j++) {
            double x_left = xs[i];
            double x_right = xs[i+1];
            double y_bottom = ys[j];
            double y_top = ys[j+1];
            double cx = (x_left + x_right) / 2.0;
            double cy = (y_bottom + y_top) / 2.0;
            bool covered = false;
            for (const Rect& r : rects) {
                if (cx >= r.x1 && cx <= r.x2 && cy >= r.y1 && cy <= r.y2) {
                    covered = true;
                    break;
                }
            }
            if (covered) {
                area += (x_right - x_left) * (y_top - y_bottom);
            }
        }
    }
    printf("%.2f\n", area);
    return 0;
}
