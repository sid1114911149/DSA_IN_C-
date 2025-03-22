#include <iostream>
#include <list>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

// Function to create a new node
Node* create(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

class Btree {
public:
    Node* root;

    // Constructor initializes root to NULL
    Btree() {
        root = NULL;
        cout << "Binary Tree created successfully..\n";
    }

    // Function to find the nearest common ancestor (LCA)
    Node* find_nearest_common_ancestor(Node* temp, int n1, int n2) {
        if (temp == NULL) return NULL;

        // If the current node is one of n1 or n2, return it
        if (temp->data == n1 || temp->data == n2) {
            return temp;
        }

        // Search for n1 and n2 in left and right subtrees
        Node* left_lca = find_nearest_common_ancestor(temp->left, n1, n2);
        Node* right_lca = find_nearest_common_ancestor(temp->right, n1, n2);

        // If n1 is found in one subtree and n2 in the other, this node is LCA
        if (left_lca && right_lca) {
            return temp;
        }

        // Otherwise, return the non-null result
        return (left_lca != NULL) ? left_lca : right_lca;
    }

    // Preorder traversal of the binary tree
    void preorder(Node* temp) {
        if (temp == NULL) return;
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
};

int main() {
    Btree B;
    B.root = create(1);
    B.root->left = create(2);
    B.root->right = create(3);
    B.root->left->left = create(4);
    B.root->left->right = create(5);
    B.root->right->left = create(6);
    B.root->right->right = create(7);

    cout << "Preorder traversal: ";
    B.preorder(B.root);
    cout << endl;

    int n1 = 4, n2 = 5;
    Node* lca = B.find_nearest_common_ancestor(B.root, n1, n2);

    if (lca) {
        cout << "Nearest common ancestor of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    } else {
        cout << "Nodes not found in the tree.\n";
    }

    return 0;
}
