#include "stdlib.h"
#include <iostream>

using namespace std;

const int SIZE = 10001;
int a[SIZE];

void Insert(int p, int q) {
  int key = a[q], i = q - 1;
  while (i >= p && a[i] > key) {
    a[i + 1] = a[i];
    --i;
  }
  a[i + 1] = key;
}

void RecurInsertionSort(int p, int q) {
  if (q - p + 1 > 1) {
    RecurInsertionSort(p, q - 1);
    Insert(p, q);
  }
}

void Merge(int l, int m, int r, int temp[]) {
  int i = l, j = m + 1, k = l;
  while (i <= m && j <= r) {
    if (a[i] <= a[j])
      temp[k++] = a[i++];
    else
      temp[k++] = a[j++];
  }
  while (i <= m)
    temp[k++] = a[i++];
  while (j <= r)
    temp[k++] = a[j++];
  for (int t = l; t <= r; ++t)
    a[t] = temp[t];
}

void NaturalMergeSort(int n) {
  int temp[SIZE];
  while (true) {
    int i = 0, cnt = 0;
    while (i < n) {
      int l = i;
      while (i + 1 < n && a[i] <= a[i + 1])
        ++i;
      int m = i++;
      if (i >= n)
        break;
      int r = i;
      while (i + 1 < n && a[i] <= a[i + 1])
        ++i;
      r = i++;
      Merge(l, m, r, temp);
      ++cnt;
    }
    if (cnt == 0)
      break;
  }
}

int Partition(int x, int p, int q) {
  swap(a[x], a[q]);
  int pivot = a[q], i = p - 1;
  for (int j = p; j < q; ++j) {
    if (a[j] <= pivot) {
      ++i;
      swap(a[i], a[j]);
    }
  }
  swap(a[i + 1], a[q]);
  return i + 1;
}

int RandomizedSelect(int p, int q, int k) {
  if (p == q)
    return p;
  int idx = p + rand() % (q - p + 1);
  int pivotIdx = Partition(idx, p, q);
  int leftLen = pivotIdx - p + 1;
  if (k == leftLen)
    return pivotIdx;
  else if (k < leftLen)
    return RandomizedSelect(p, pivotIdx - 1, k);
  else
    return RandomizedSelect(pivotIdx + 1, q, k - leftLen);
}

int median(int p, int q) {
  int len = q - p + 1;
  int k = (len + 1) / 2;
  return RandomizedSelect(p, q, k);
}

void QuickSort(int p, int q) {
  if (p >= q)
    return;
  int x = median(p, q);
  int i = Partition(x, p, q);
  QuickSort(p, i - 1);
  QuickSort(i + 1, q);
}

int main() {
  int i, n;
  cin >> n;

  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  RecurInsertionSort(0, n - 1);
  cout << "Insert sort: ";
  for (i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }

  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  NaturalMergeSort(n);
  cout << "\nNatural merge sort: ";
  for (i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }

  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  QuickSort(0, n - 1);
  cout << "\nQuick sort: ";
  for (i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }

  return 0;
}