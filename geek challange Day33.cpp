#include <iostream>
#include <cmath>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
class Solution {
public:
    int dfs(Node* node, int &moves) {
        if (!node) return 0;
        int left = dfs(node->left, moves);
        int right = dfs(node->right, moves);
        moves += abs(left) + abs(right);
        return node->data + left + right - 1;
    }
    int distCandy(Node* root) {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }
};
int main() {
    Node* root = new Node(5);
    root->left = new Node(0);
    root->right = new Node(0);
    root->right->left = new Node(0);
    root->right->right = new Node(0);
    Solution obj;
    cout << "Minimum moves required: " << obj.distCandy(root) << endl;
    return 0;
}