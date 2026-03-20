#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
// Below Function is used to insert into BST (for testing)..
Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}
class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
         Node* pre=NULL; // here pre refers to the predecessor.
         Node* suc=NULL; // here suc refers to the successor.
         Node* curr=root; // here curr refers to the current nodes.
         while (curr) {
             if (curr->data<key) {
                 pre=curr;  
                 curr=curr->right;
             }
             else if (curr->data>key) {
                 suc=curr;
                 curr=curr->left;
             }
             else{
                 if (curr->left) {    // here we are finding predecessor of the given key.
                    Node* temp=curr->left;
                    while (temp->right) temp=temp->right;
                    pre=temp; // here all temp refers to temporary pointer(helper variable).
                }
                if (curr->right) {  // here we are finding successor of the given key.
                    Node* temp=curr->right;
                    while (temp->left) temp=temp->left;
                    suc=temp;
                }
                break;
             }
         }
         return {pre,suc};
    }
};
int main() {
    Node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr)
        root = insert(root, x);
    int key = 65;
    Solution obj;
    vector<Node*> ans = obj.findPreSuc(root, key);
    cout << "Predecessor: ";
    if (ans[0]) cout << ans[0]->data << endl;
    else cout << "NULL\n";
    cout << "Successor: ";
    if (ans[1]) cout << ans[1]->data << endl;
    else cout << "NULL\n";
    return 0;
}