#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Triple {
public:
    int row;
    int col;
    int value;
    
    Triple(int r = 0, int c = 0, int v = 0) : row(r), col(c), value(v) {}
    
    void transpose() {
        swap(row, col);
    }
    
    bool operator<(const Triple& other) const {
        if (row != other.row) {
            return row < other.row;
        }
        return col < other.col;
    }
    
    void display() const {
        cout << row << " " << col << " " << value << endl;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<Triple> triples(k);
    for (int i = 0; i < k; i++) {
        int r, c, v;
        cin >> r >> c >> v;
        triples[i] = Triple(r, c, v);
    }
    
    for (int i = 0; i < k; i++) {
        triples[i].transpose();
    }
    
    sort(triples.begin(), triples.end());

    for (int i = 0; i < k; i++) {
        triples[i].display();
    }
    
    return 0;
}
