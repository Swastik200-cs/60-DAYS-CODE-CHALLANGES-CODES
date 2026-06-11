#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
class Solution {
public:
    int solve(Node* root) {
        if (root == nullptr)
            return 0;
        int oldValue = root->data;
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);
        root->data = leftSum + rightSum;
        return root->data + oldValue;
    }
    void toSumTree(Node* root) {
        solve(root);
    }
};
void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);
    Solution obj;
    obj.toSumTree(root);
    cout << "Inorder Traversal of Sum Tree:\n";
    inorder(root);
    return 0;
}