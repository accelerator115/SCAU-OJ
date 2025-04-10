#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int main() {
    int n;
    cin >> n;
    
    TreeNode** nodes = new TreeNode*[n + 1];
    for (int i = 1; i <= n; i++) {
        nodes[i] = new TreeNode(i);
    }
    
    bool* hasLeft = new bool[n + 1];
    for (int i = 1; i <= n; i++) {
        hasLeft[i] = false;
    }
    
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        
        if (!hasLeft[x]) {
            nodes[x]->left = nodes[y];
            hasLeft[x] = true;
        } else {
            nodes[x]->right = nodes[y];
        }
    }

    queue<TreeNode*> q;
    q.push(nodes[1]);
    
    int maxWidth = 0;
    
    while (!q.empty()) {
        int size = q.size();
        if (size > maxWidth) {
            maxWidth = size;
        }
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    
    cout << maxWidth << endl;
    return 0;
}