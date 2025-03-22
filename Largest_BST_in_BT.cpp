#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node *create(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

class BT {
public:
    Node *root;

    BT() {
        root = NULL;
        cout << "Binary Tree is Created Successfully..\n";
    }

    void inorder(Node *temp) {
        if (temp == NULL) {
            return;
        }
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }

    struct Info {
        int size;      // Size of the subtree
        int min;       // Min value in the subtree
        int max;       // Max value in the subtree
        int maxBSTSize; // Size of the largest BST
        bool isBST;    // Is the subtree a BST?
    };

    Info findLargestBST(Node *temp) {
        if (temp == NULL)
            return {0, INT_MAX, INT_MIN, 0, true};

        // Recursively get info about left and right subtrees
        Info leftInfo = findLargestBST(temp->left);
        Info rightInfo = findLargestBST(temp->right);

        Info current;
        current.size = leftInfo.size + rightInfo.size + 1;

        // Check if the current subtree is a BST
        if (leftInfo.isBST && rightInfo.isBST &&
            temp->data > leftInfo.max && temp->data < rightInfo.min) {
            
            current.min = min(temp->data, leftInfo.min);
            current.max = max(temp->data, rightInfo.max);
            current.maxBSTSize = current.size;
            current.isBST = true;
            
            return current;
        }

        // If not a BST, return the largest BST found so far
        current.isBST = false;
        current.maxBSTSize = max(leftInfo.maxBSTSize, rightInfo.maxBSTSize);
        return current;
    }

    int largestBST() {
        return findLargestBST(root).maxBSTSize;
    }
};

int main() {
    BT B;
    
    // Constructing a binary tree (not necessarily a BST)
    B.root = create(10);
    B.root->left = create(5);
    B.root->right = create(15);
    B.root->left->left = create(1);
    B.root->left->right = create(8);
    B.root->right->right = create(7); // This node makes it not a BST

    cout << "Largest BST size in the tree: " << B.largestBST() << endl;

    return 0;
}
