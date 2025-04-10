#include <iostream>
#include <string>
using namespace std;

void buildPostorder(const string& preorder, const string& inorder, string& postorder) {
    int n = preorder.length();
    if (n == 0) return;
    char root = preorder[0];
    int rootPos = inorder.find(root);
    int leftSize = rootPos;
    buildPostorder(preorder.substr(1, leftSize), inorder.substr(0, leftSize), postorder);
    buildPostorder(preorder.substr(leftSize + 1), inorder.substr(leftSize + 1), postorder);
    postorder += root;
}

int main() {
    string preorder, inorder, postorder;
    cin >> preorder >> inorder;
    buildPostorder(preorder, inorder, postorder);
    cout << postorder << endl;
    return 0;
}
