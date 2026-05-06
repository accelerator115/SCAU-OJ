#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt[10] = {0};
    for (char c : s) {
        cnt[c - '0']++;
    }

    if (cnt[0] == 0 && cnt[5] == 0) {
        cout << "impossible" << endl;
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += i * cnt[i];
    }
    
    int rem = sum % 3;
    
    if (rem == 1) {
        bool d = false;
        for (int i = 1; i < 10; i += 3) { 
            if (cnt[i] > 0) {
                cnt[i]--;
                d = true;
                break;
            }
        }
        if (!d) {
            int dcnt = 2;
            for (int i = 2; i < 10 && dcnt > 0; i += 3) {  
                while (cnt[i] > 0 && dcnt > 0) {
                    if (i == 5 && cnt[5] == 1 && cnt[0] == 0) break;
                    cnt[i]--;
                    dcnt--;
                }
            }
            if (dcnt > 0) {
                cout << "impossible" << endl;
                return 0;
            }
        }
    } else if (rem == 2) {
        bool d = false;
        for (int i = 2; i < 10; i += 3) { 
            if (i == 5 && cnt[5] == 1 && cnt[0] == 0) continue;
            if (cnt[i] > 0) {
                cnt[i]--;
                d = true;
                break;
            }
        }
        if (!d) {
            int dcnt = 2;
            for (int i = 1; i < 10 && dcnt > 0; i += 3) {  
                while (cnt[i] > 0 && dcnt > 0) {
                    cnt[i]--;
                    dcnt--;
                }
            }
            if (dcnt > 0) {
                cout << "impossible" << endl;
                return 0;
            }
        }
    }
    
    if (cnt[0] == 0 && cnt[5] == 0) {
        cout << "impossible" << endl;
        return 0;
    }

    int total = 0;
    for (int i = 0; i < 10; i++) {
        total += cnt[i];
    }
    
    if (total == 0) {
        cout << "impossible" << endl;
        return 0;
    }

    if (total == cnt[0]) {
        cout << "0" << endl;
        return 0;
    }

    int l = -1;
    if (cnt[0] > 0) l = 0;
    else l = 5;

    cnt[l]--;

    int rem_total = 0;
    for (int i = 0; i < 10; i++) rem_total += cnt[i];

    if (rem_total == 0) {
        cout << (char)('0' + l) << endl;
        return 0;
    }

    string result = "";
    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < cnt[i]; j++) result += (char)('0' + i);
    }

    result += (char)('0' + l);
    cout << result << endl;
    
    return 0;
}
