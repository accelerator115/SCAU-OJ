#include <iostream>
using namespace std;

void binaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int left = 0;
        int right = i - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > key) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        int j = i - 1;
        while (j >= left) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[left] = key;
        for (int k = 0; k < n; k++) {
            cout << arr[k];
            if (k < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    binaryInsertionSort(arr, n);
    delete[] arr;
    return 0;
}