#include <iostream>
#include <vector>
#include <algorithm>
// 查找跨越中点的最大子数组和
int maxCrossingSum(const std::vector<int>& arr, int low, int mid, int high) {
    // 计算包含中点向左的最大和
    int leftSum = 0;
    int maxLeftSum = -999999;
    for (int i = mid; i >= low; --i) {
        leftSum += arr[i];
        if (leftSum > maxLeftSum) {
            maxLeftSum = leftSum;
        }
    }
    // 计算包含中点向右的最大和
    int rightSum = 0;
    int maxRightSum = -999999;
    for (int i = mid + 1; i <= high; ++i) {
        rightSum += arr[i];
        if (rightSum > maxRightSum) {
            maxRightSum = rightSum;
        }
    }
    return maxLeftSum + maxRightSum;
}
// 分治法求解最大子数组和
int maxSubArraySum(const std::vector<int>& arr, int low, int high) {
    if (low == high) {
        return arr[low];
    }
    int mid = (low + high) / 2;
    // 递归计算左半部分、右半部分和跨越中点的最大子数组和
    int leftMax = maxSubArraySum(arr, low, mid);
    int rightMax = maxSubArraySum(arr, mid + 1, high);
    int crossMax = maxCrossingSum(arr, low, mid, high);
    // 返回三者中的最大值
    return std::max({leftMax, rightMax, crossMax});
}
int main() {
    std::vector<int> arr;
    int n, data;
    std::cin>>n;
    for(int i=0; i<n; i++)
   {
        std::cin>>data;
        arr.push_back(data);
   }
    int maxSum = maxSubArraySum(arr, 0, n);
    std::cout <<  maxSum << std::endl;
    return 0;
} 
