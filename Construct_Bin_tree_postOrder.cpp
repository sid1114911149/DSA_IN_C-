#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

// Function to search for an element in inorder traversal
int search(const vector<int> &inorder, int start, int end, int target) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == target) {
            return i;
        }
    }
    return -1;
}

// Function to construct a binary tree from postorder and inorder traversals
Node* construct(vector<int> &postorder, vector<int> &inorder, int start, int end, int &idx) {
    if (start > end) {
        return NULL;
    }

    int curr = postorder[idx--];
    Node* root = new Node{curr, NULL, NULL};

    if (start == end) {
        return root;
    }

    int pos = search(inorder, start, end, curr);
    root->right = construct(postorder, inorder, pos + 1, end, idx);
    root->left = construct(postorder, inorder, start, pos - 1, idx);
    return root;
}

// Function to print inorder traversal of the tree
void inOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Function to delete tree and free memory
void deleteTree(Node* root) {
    if (root == NULL) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
int height(Node *temp){
    if(temp==NULL){
        return 0;
    }
    int lheight=height(temp->left);
    int rheight=height(temp->left);
    return max(lheight,rheight)+1;
}
int main() {
    vector<int> inorder = {4, 2, 5, 1, 3, 6};
    vector<int> postorder = {4,5,2,6,3,1};
    int idx = inorder.size()-1;  // Reset index for recursive calls
    Node* root = construct(postorder, inorder, 0, inorder.size() - 1, idx);

    cout << "Inorder Traversal of Constructed Tree: ";
    inOrder(root);
    cout << endl;
    cout<<"Height of Givven Binary Tree is:"<<height(root)<<endl;
    // Free allocated memory
    deleteTree(root);

    return 0;
}
