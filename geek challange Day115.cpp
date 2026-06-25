#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
class Solution {
private:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
public:
    Node* compute(Node* head) {
        if (!head || !head->next)
            return head;
        head = reverseList(head);
        int maxSoFar = head->data;
        Node* curr = head;
        while (curr && curr->next) {
            if (curr->next->data < maxSoFar) {
                Node* temp = curr->next;
                curr->next = temp->next;
                delete temp;
            } else {
                curr = curr->next;
                maxSoFar = curr->data;
            }
        }

        // Reverse back
        return reverseList(head);
    }
};

// Function to insert a node at the end
void insert(Node*& head, int data) {
    Node* newNode = new Node(data);

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

// Function to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    Node* head = nullptr;
    int arr[] = {12, 15, 10, 11, 5, 6, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        insert(head, arr[i]);
    cout << "Original List: ";
    printList(head);
    Solution obj;
    head = obj.compute(head);
    cout << "Modified List: ";
    printList(head);
    return 0;
}