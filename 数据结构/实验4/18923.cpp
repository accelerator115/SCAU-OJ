#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int diameter = 0;
int depth(TreeNode *node)
{
    if (!node)
        return 0;

    int leftDepth = depth(node->left);
    int rightDepth = depth(node->right);
    diameter = max(diameter, leftDepth + rightDepth);
    return max(leftDepth, rightDepth) + 1;
}
int diameterOfBinaryTree(TreeNode *root)
{
    diameter = 0;
    depth(root);
    return diameter;
}

int main()
{
    int n;
    cin >> n;

    TreeNode **nodes = new TreeNode *[n + 1];
    for (int i = 1; i <= n; i++)
    {
        nodes[i] = new TreeNode(i);
    }

    bool *hasLeft = new bool[n + 1]();

    for (int i = 0; i < n - 1; i++)
    {
        int parent, child;
        cin >> parent >> child;

        if (!hasLeft[parent])
        {
            nodes[parent]->left = nodes[child];
            hasLeft[parent] = true;
        }
        else
        {
            nodes[parent]->right = nodes[child];
        }
    }

    cout << diameterOfBinaryTree(nodes[1]) << endl;
    return 0;
}