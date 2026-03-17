#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node* buildTree(vector<string> nodes) {
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
        if (i >= nodes.size()) break;
        if (nodes[i] != "N") {
            curr->right = new Node(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
class Solution {
  public:
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent;
        queue<Node*> q;
        q.push(root);
        Node* targetNode = NULL;
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if (curr->data==target) targetNode = curr;
            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        if (targetNode == NULL) return 0;
        unordered_map<Node*, bool> visited;
        queue<Node*>burnQ;
        burnQ.push(targetNode);
        visited[targetNode]=true;
        int time = 0;
        while (!burnQ.empty()) {
            int size = burnQ.size();
            bool spread = false;
            for (int i = 0; i < size; i++) {
                Node* curr = burnQ.front();
                burnQ.pop();
                
                if (curr->left && !visited[curr->left]) {
                    visited[curr->left] = true;
                    burnQ.push(curr->left);
                    spread = true;
                }
                
                if (curr->right && !visited[curr->right]) {
                    visited[curr->right] = true;
                    burnQ.push(curr->right);
                    spread = true;
                }
                
                if (parent.find(curr) != parent.end() && !visited[parent[curr]]) {
                    visited[parent[curr]] = true;
                    burnQ.push(parent[curr]);
                    spread = true;
                }
            }
            if (spread) time++;
        }
        return time;
    }
};