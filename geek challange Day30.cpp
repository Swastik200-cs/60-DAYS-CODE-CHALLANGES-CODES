#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class Solution {
public:
    vector<vector<int>> verticalOrder(Node* root) {
        map<int, vector<int>> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* node = temp.first;
            int hd = temp.second;
            mp[hd].push_back(node->data);
            if (node->left)
                q.push({node->left, hd - 1});

            if (node->right)
                q.push({node->right, hd + 1});
        }
        vector<vector<int>> ans;
        for (auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Solution obj;
    vector<vector<int>> result = obj.verticalOrder(root);
    for (auto col : result) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}