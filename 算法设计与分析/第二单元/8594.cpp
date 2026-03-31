#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int total = 0;

bool find(char list[], int k, int i) {
    for (int j = k; j < i; j++) {
        if (list[j] == list[i]) {
            return true;
        }
    }
    return false;
}

void perm(char list[], int k, int m) {
    if (k == m) {
        for (int i = 0; i <= m; i++) {
            cout << list[i];
        }
        cout << endl;
        total++;
    } else {
        for (int i = k; i <= m; i++) {
            if (find(list, k, i)) {
                continue;
            }
            swap(list[k], list[i]);
            perm(list, k + 1, m);
            swap(list[k], list[i]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    char* list = new char[n];
    for (int i = 0; i < n; i++) {
        list[i] = s[i];
    }
    
    perm(list, 0, n - 1);
    cout << total << endl;
    
    delete[] list;
    return 0;
}
