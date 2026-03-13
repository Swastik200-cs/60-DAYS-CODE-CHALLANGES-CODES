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
        left = right = NULL;
    }
};
class Solution {
public:
    vector<int> topView(Node* root) {
        map<int,int> m;
        queue<pair<Node*,int>> q;
        vector<int> ans;
        if(!root) return ans;
        q.push({root,0});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            Node* n = temp.first;
            int d = temp.second;
            if(!m.count(d))
                m[d] = n->data;
            if(n->left)
                q.push({n->left,d-1});
            if(n->right)
                q.push({n->right,d+1});
        }
        for(auto &i : m)
            ans.push_back(i.second);
        return ans;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    Solution obj;
    vector<int> result = obj.topView(root);
    cout << "Top View: ";
    for(int x : result)
        cout << x << " ";
    return 0;
}