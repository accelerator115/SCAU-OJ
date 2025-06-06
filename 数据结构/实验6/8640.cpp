#include <iostream>
using namespace std;

void shellSort(int arr[], int n)
{
    for (int d = n / 2; d > 0; d /= 2)
    {
        for (int i = d; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= d && arr[j - d] > temp; j -= d)
            {
                arr[j] = arr[j - d];
            }
            arr[j] = temp;
        }
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    shellSort(arr, n);
    delete[] arr;
    return 0;
}