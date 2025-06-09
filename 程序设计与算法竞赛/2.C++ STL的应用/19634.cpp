#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 计算中位数的函数
double findMedian(const vector<int>& nums) {
    int n = nums.size();
    if (n % 2 == 1) {
        return nums[n / 2];
    } else {
        return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int num;
        cin >> num;
        auto it = lower_bound(sequence.begin(), sequence.end(), num);
        sequence.insert(it, num);
        double median = findMedian(sequence);
        cout << median << endl;
    }

    return 0;
}