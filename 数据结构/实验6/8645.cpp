#include <stdio.h>
#include <stdlib.h>


void merge(int arr[], int left, int mid, int right, int temp[]) {
    int i = left;          
    int j = mid + 1;      
    int k = left;         

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int m = left; m <= right; m++) {
        arr[m] = temp[m];
    }
}

void mergeSort(int arr[], int n) {
    int* temp = (int*)malloc(n * sizeof(int));
    if (!temp) exit(-1);
    for (int step = 1; step < n; step *= 2) {
        for (int left = 0; left < n; left += 2 * step) {
            int mid = left + step - 1; 
            int right = mid + step;    
            if (mid + 1 < n) {         
                merge(arr, left, mid, right < n ? right : n - 1, temp);
            }
        }

        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    free(temp); 
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, n);

    delete[] arr;
    return 0;
}
