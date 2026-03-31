#include <iostream>
#include <vector>

using namespace std;

long long mergeCount(vector<int>& arr, int l, int mid, int r) {
    vector<int> tmp;
    int i = l, j = mid + 1;
    long long cnt = 0;
    
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            tmp.push_back(arr[i]);
            i++;
        } else {
            tmp.push_back(arr[j]);
            cnt += (mid - i + 1);
            j++;
        }
    }
    
    while (i <= mid) {
        tmp.push_back(arr[i]);
        i++;
    }
    
    while (j <= r) {
        tmp.push_back(arr[j]);
        j++;
    }
    
    for (int k = 0; k < tmp.size(); k++) {
        arr[l + k] = tmp[k];
    }
    
    return cnt;
}

long long mergeSort(vector<int>& arr, int l, int r) {
    long long cnt = 0;
    if (l < r) {
        int mid = l + (r - l) / 2;
        cnt += mergeSort(arr, l, mid);
        cnt += mergeSort(arr, mid + 1, r);
        cnt += mergeCount(arr, l, mid, r);
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    long long result = mergeSort(arr, 0, n - 1);
    cout << result << endl;
    
    return 0;
}
