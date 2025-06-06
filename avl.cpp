#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
    
    AVLNode(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;
    
    // 获取节点高度
    int getHeight(AVLNode* node) {
        return node ? node->height : 0;
    }
    
    // 更新节点高度
    void updateHeight(AVLNode* node) {
        if (node) {
            node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        }
    }
    
    // 获取平衡因子
    int getBalance(AVLNode* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }
    
    // 右旋转
    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;
        
        x->right = y;
        y->left = T2;
        
        updateHeight(y);
        updateHeight(x);
        
        return x;
    }
    
    // 左旋转
    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;
        
        y->left = x;
        x->right = T2;
        
        updateHeight(x);
        updateHeight(y);
        
        return y;
    }
    
    // 插入节点
    AVLNode* insert(AVLNode* node, int data) {
        // 1. 正常BST插入
        if (!node) return new AVLNode(data);
        
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        } else {
            return node; // 重复值不插入
        }
        
        // 2. 更新高度
        updateHeight(node);
        
        // 3. 获取平衡因子
        int balance = getBalance(node);
        
        // 4. 进行旋转调整
        // Left Left Case
        if (balance > 1 && data < node->left->data) {
            return rotateRight(node);
        }
        
        // Right Right Case
        if (balance < -1 && data > node->right->data) {
            return rotateLeft(node);
        }
        
        // Left Right Case
        if (balance > 1 && data > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        
        // Right Left Case
        if (balance < -1 && data < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        
        return node;
    }
    
    // 找到最小值节点
    AVLNode* findMin(AVLNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }
    
    // 删除节点
    AVLNode* deleteNode(AVLNode* node, int data) {
        // 1. 正常BST删除
        if (!node) return node;
        
        if (data < node->data) {
            node->left = deleteNode(node->left, data);
        } else if (data > node->data) {
            node->right = deleteNode(node->right, data);
        } else {
            if (!node->left || !node->right) {
                AVLNode* temp = node->left ? node->left : node->right;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                AVLNode* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        
        if (!node) return node;
        
        // 2. 更新高度
        updateHeight(node);
        
        // 3. 获取平衡因子
        int balance = getBalance(node);
        
        // 4. 进行旋转调整
        // Left Left Case
        if (balance > 1 && getBalance(node->left) >= 0) {
            return rotateRight(node);
        }
        
        // Left Right Case
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        
        // Right Right Case
        if (balance < -1 && getBalance(node->right) <= 0) {
            return rotateLeft(node);
        }
        
        // Right Left Case
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        
        return node;
    }
    
    // 查找节点
    bool search(AVLNode* node, int data) {
        if (!node) return false;
        if (data == node->data) return true;
        if (data < node->data) return search(node->left, data);
        return search(node->right, data);
    }
    
    // 中序遍历
    void inorder(AVLNode* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
    
    // 前序遍历
    void preorder(AVLNode* node) {
        if (node) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }
    
    // 后序遍历
    void postorder(AVLNode* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }
    
    // 销毁树
    void destroy(AVLNode* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }
    
public:
    AVLTree() : root(nullptr) {}
    
    ~AVLTree() {
        destroy(root);
    }
    
    void insert(int data) {
        root = insert(root, data);
    }
    
    void remove(int data) {
        root = deleteNode(root, data);
    }
    
    bool search(int data) {
        return search(root, data);
    }
    
    void inorderTraversal() {
        cout << "中序遍历: ";
        inorder(root);
        cout << endl;
    }
    
    void preorderTraversal() {
        cout << "前序遍历: ";
        preorder(root);
        cout << endl;
    }
    
    void postorderTraversal() {
        cout << "后序遍历: ";
        postorder(root);
        cout << endl;
    }
    
    // 层序遍历
    void levelOrder() {
        if (!root) return;
        queue<AVLNode*> q;
        q.push(root);
        cout << "层序遍历: ";
        while (!q.empty()) {
            AVLNode* curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl;
    }
    
    int getTreeHeight() {
        return getHeight(root);
    }
    
    bool isEmpty() {
        return root == nullptr;
    }
};

// 测试代码
int main() {
    AVLTree avl;
    
    // 插入测试
    cout << "=== AVL树操作测试 ===" << endl;
    int values[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(values) / sizeof(values[0]);
    
    cout << "插入元素: ";
    for (int i = 0; i < n; i++) {
        cout << values[i] << " ";
        avl.insert(values[i]);
    }
    cout << endl;
    
    // 遍历测试
    avl.inorderTraversal();
    avl.preorderTraversal();
    avl.postorderTraversal();
    avl.levelOrder();
    
    cout << "树的高度: " << avl.getTreeHeight() << endl;
    
    // 查找测试
    cout << "\n=== 查找测试 ===" << endl;
    int searchValues[] = {25, 35, 10};
    for (int val : searchValues) {
        cout << "查找 " << val << ": " << (avl.search(val) ? "找到" : "未找到") << endl;
    }
    
    // 删除测试
    cout << "\n=== 删除测试 ===" << endl;
    cout << "删除 30" << endl;
    avl.remove(30);
    avl.inorderTraversal();
    
    cout << "删除 20" << endl;
    avl.remove(20);
    avl.inorderTraversal();
    
    cout << "最终树的高度: " << avl.getTreeHeight() << endl;
    
    return 0;
}
