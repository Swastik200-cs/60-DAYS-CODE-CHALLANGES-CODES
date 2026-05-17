#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    bool isIdentical(Node* root1, Node* root2) {

        // If both nodes are NULL
        if (root1 == NULL && root2 == NULL)
            return true;

        // If one is NULL and the other is not
        if (root1 == NULL || root2 == NULL)
            return false;

        // Check current node data and subtrees
        return (root1->data == root2->data) &&
               isIdentical(root1->left, root2->left) &&
               isIdentical(root1->right, root2->right);
    }

    // Function to check if root2 is subtree of root1
    bool isSubTree(Node* root1, Node* root2) {

        if (root2 == NULL)
            return true;

        if (root1 == NULL)
            return false;

        if (isIdentical(root1, root2))
            return true;

        return isSubTree(root1->left, root2) ||
               isSubTree(root1->right, root2);
    }
};

int main() {

    /*
            Tree T
                1
               / \
              2   3
                 /
                4

            Tree S
                3
               /
              4
    */


    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->right->left = new Node(4);

    Node* root2 = new Node(3);
    root2->left = new Node(4);

    Solution obj;


    if (obj.isSubTree(root1, root2))
        cout << "True -> root2 is a subtree of root1" << endl;
    else
        cout << "False -> root2 is NOT a subtree of root1" << endl;

    return 0;
}