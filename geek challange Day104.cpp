#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility>
using namespace std;
class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
class BinaryTree
{
private:
    Node* rootNode;
    void inorderTraversal(Node* currentNode)
    {
        if(currentNode == nullptr)
        {
            return;
        }
        inorderTraversal(currentNode->left);
        cout << currentNode->data << " ";
        inorderTraversal(currentNode->right);
    }
    int calculateHeight(Node* currentNode)
    {
        if(currentNode == nullptr)
        {
            return 0;
        }
        int leftHeight = calculateHeight(currentNode->left);
        int rightHeight = calculateHeight(currentNode->right);
        if(leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }
        else
        {
            return rightHeight + 1;
        }
    }

    int countTotalNodes(Node* currentNode)
    {
        if(currentNode == nullptr)
        {
            return 0;
        }
        int leftNodes = countTotalNodes(currentNode->left);
        int rightNodes = countTotalNodes(currentNode->right);
        return leftNodes + rightNodes + 1;
    }

public:
    BinaryTree()
    {
        rootNode = nullptr;
    }
    Node* getRootNode()
    {
        return rootNode;
    }
    void createSampleTree()
    {
        rootNode = new Node(1);
        rootNode->left = new Node(2);
        rootNode->right = new Node(3);
        rootNode->left->left = new Node(4);
        rootNode->left->right = new Node(5);
        rootNode->left->right->right = new Node(6);
        rootNode->right->right = new Node(7);
    }

    void displayInorderTraversal()
    {
        inorderTraversal(rootNode);
        cout << endl;
    }
    int getTreeHeight()
    {
        return calculateHeight(rootNode);
    }
    int getTotalNodeCount()
    {
        return countTotalNodes(rootNode);
    }
};

class VerticalSumCalculator
{
private:
    map<int,int> verticalLineSumCollection;
    void performVerticalSumComputation(Node* rootNode)
    {
        if(rootNode == nullptr)
        {
            return;
        }
        queue<pair<Node*,int>> nodeProcessingQueue;
        nodeProcessingQueue.push(make_pair(rootNode,0));
        while(nodeProcessingQueue.empty() == false)
        {
            pair<Node*,int> currentPair = nodeProcessingQueue.front();
            nodeProcessingQueue.pop();
            Node* currentNode = currentPair.first;
            int horizontalDistance = currentPair.second;
            if(verticalLineSumCollection.find(horizontalDistance) == verticalLineSumCollection.end())
            {
                verticalLineSumCollection.insert(make_pair(horizontalDistance,currentNode->data));
            }
            else
            {
                verticalLineSumCollection[horizontalDistance] =
                verticalLineSumCollection[horizontalDistance] + currentNode->data;
            }
            if(currentNode->left != nullptr)
            {
                nodeProcessingQueue.push(make_pair(currentNode->left,horizontalDistance - 1));
            }
            if(currentNode->right != nullptr)
            {
                nodeProcessingQueue.push(make_pair(currentNode->right,horizontalDistance + 1));
            }
        }
    }
public:
    vector<int> getVerticalSumValues(Node* rootNode)
    {
        verticalLineSumCollection.clear();
        performVerticalSumComputation(rootNode);
        vector<int> resultVector;
        map<int,int>::iterator iteratorValue;
        for(iteratorValue = verticalLineSumCollection.begin();
            iteratorValue != verticalLineSumCollection.end();
            iteratorValue++)
        {
            resultVector.push_back(iteratorValue->second);
        }
        return resultVector;
    }
    void printVerticalSums(vector<int> verticalSums)
    {
        cout << "Vertical Sum Values Of Binary Tree Are :" << endl;
        for(unsigned long long indexValue = 0;
            indexValue < verticalSums.size();
            indexValue++)
        {
            cout << verticalSums[indexValue] << " ";
        }
        cout << endl;
    }
};
int main()
{
    BinaryTree binaryTreeObject;
    binaryTreeObject.createSampleTree();
    cout << "Inorder Traversal Of Constructed Binary Tree :" << endl;
    binaryTreeObject.displayInorderTraversal();

    cout << "Total Number Of Nodes Present In Tree :" << endl;
    cout << binaryTreeObject.getTotalNodeCount() << endl;
    cout << "Height Of Binary Tree :" << endl;
    cout << binaryTreeObject.getTreeHeight() << endl;
    VerticalSumCalculator calculatorObject;
    vector<int> computedVerticalSums =
    calculatorObject.getVerticalSumValues(binaryTreeObject.getRootNode());
    calculatorObject.printVerticalSums(computedVerticalSums);
    return 0;
}