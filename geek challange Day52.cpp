#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  struct Node {
      int freq;
      char ch;
      Node *left, *right;
      Node(int f,char c) {
            freq=f;
            ch=c;
            left=right= NULL;
        }
    };
    struct cmp {
        bool operator()(Node*a,Node*b) {
            return a->freq > b->freq;
        }
    };
     void preorder(Node* root,string code,vector<string> &ans) {
        if (!root) return;
        if (!root->left && !root->right) {
            ans.push_back(code);
            return;
        }
        preorder(root->left, code + "0", ans);
        preorder(root->right, code + "1", ans);
    }
    vector<string> huffmanCodes(string &s, vector<int> f) {
        // Code here
        priority_queue<Node*,vector<Node*>,cmp> pq;
        // creating the nodes here 
        for (int i=0;i<s.size();i++) {
            pq.push(new Node(f[i], s[i]));
        }
        while (pq.size() > 1) {
            Node* left=pq.top(); pq.pop();
            Node* right=pq.top(); pq.pop();
            Node* newNode = new Node(left->freq + right->freq, '$');
            newNode->left=left;
            newNode->right=right;
            pq.push(newNode);
        }
        Node* root = pq.top();
        vector<string> ans;
        preorder(root, "", ans);
        return ans;
        
    }
};

int main() {
    Solution obj;
    string s = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
    vector<string> result = obj.huffmanCodes(s, f);
    cout << "Huffman Codes:\n";
    for (auto code : result) {
        cout << code << " ";
    }
    return 0;
}