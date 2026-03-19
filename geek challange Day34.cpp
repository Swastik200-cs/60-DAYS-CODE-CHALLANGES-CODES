#include <bits/stdc++.h>
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
    int largest = 0;  
    struct Info {
        int s, m, n;
        bool b;
    };   
    Info solve(Node* root) {
        if (!root) return {0, INT_MAX, INT_MIN, true};     
        Info l = solve(root->left);
        Info r = solve(root->right);  
        Info curr;
        curr.s = l.s + r.s + 1;   
        if (l.b && r.b && root->data > l.n && root->data < r.m) {
            curr.b = true;
            curr.m = min(root->data, l.m);
            curr.n = max(root->data, r.n);
            largest = max(largest, curr.s);
        } else {
            curr.b = false;
        }  
        return curr;
    }
    int largestBst(Node *root) {
        largest = 0;
        solve(root);
        return largest;
    }
};
Node* buildTree(vector<string> &nodes) {
    if (nodes.size() == 0 || nodes[0] == "N") return NULL;
    Node* root = new Node(stoi(nodes[0]));
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        Node* curr = q.front();
        q.pop();
        if (nodes[i] != "N") {
            curr->left = new Node(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != "N") {
            curr->right = new Node(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
int main() {
    cout << "Enter tree in level order (use N for NULL):\n"; 
    string input;
    getline(cin, input); 
    stringstream ss(input);
    vector<string> nodes;
    string temp;  
    while (ss >> temp) {
        nodes.push_back(temp);
    }   
    Node* root = buildTree(nodes);   
    Solution obj;
    cout << "Largest BST size: " << obj.largestBst(root) << endl;  
    return 0;
}