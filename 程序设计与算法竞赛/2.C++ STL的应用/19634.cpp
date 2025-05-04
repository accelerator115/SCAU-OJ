#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    // 创建两个优先队列:
    // maxHeap 存储较小的一半数据，顶部是最大值
    priority_queue<int> maxHeap;
    // minHeap 存储较大的一半数据，顶部是最小值
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // 处理初始的n个数据
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        // 决定将新数据放入哪个堆
        if (maxHeap.empty() || num <= maxHeap.top()) {
            // 如果小于等于maxHeap的顶部，放入maxHeap
            maxHeap.push(num);
        } else {
            // 否则放入minHeap
            minHeap.push(num);
        }
        
        // 平衡两个堆，确保maxHeap的大小等于minHeap或比minHeap多1个元素
        if (maxHeap.size() > minHeap.size() + 1) {
            // 如果maxHeap比minHeap多超过1个元素，将maxHeap的顶部元素移到minHeap
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            // 如果minHeap比maxHeap大，将minHeap的顶部元素移到maxHeap
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    // 读取后续m个数据并计算中位数
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        
        // 与前面相同的逻辑，决定将新数据放入哪个堆
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // 保持两个堆的平衡
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // 计算中位数
        double median;
        if ((maxHeap.size() + minHeap.size()) % 2 == 1) {
            // 如果总元素个数为奇数，中位数是maxHeap的顶部元素
            median = maxHeap.top();
        } else {
            // 如果总元素个数为偶数，中位数是两个堆顶元素的平均值
            median = (maxHeap.top() + minHeap.top()) / 2.0;
        }
        
        // 输出中位数，如果是整数则以整数形式输出
        if (median == static_cast<int>(median)) {
            cout << static_cast<int>(median) << endl;
        } else {
            cout << median << endl;
        }
    }
    
    return 0;
}