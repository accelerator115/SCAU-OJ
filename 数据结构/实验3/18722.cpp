#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Triple {
public:
    int row;
    int col;
    int value;
};

bool compareTriples(const Triple& a, const Triple& b) {
    if (a.row != b.row) {
        return a.row < b.row;
    }
    return a.col < b.col;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<Triple> triples(k);
    for (int i = 0; i < k; i++) {
        cin >> triples[i].row >> triples[i].col >> triples[i].value;
    }
    
    for (int i = 0; i < k; i++) {
        swap(triples[i].row, triples[i].col);
    }
    
    sort(triples.begin(), triples.end(), compareTriples);

    for (int i = 0; i < k; i++) {
        cout << triples[i].row << " " << triples[i].col << " " << triples[i].value << endl;
    }
    
    return 0;
}
