#include <iostream>
#include <vector>
#include<queue>
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

// Function to construct a binary tree from preorder and inorder traversals
Node* construct(vector<int> &preorder, vector<int> &inorder, int start, int end, int &idx) {
    if (start > end) {
        return NULL;
    }

    int curr = preorder[idx++];
    Node* root = new Node{curr, NULL, NULL};

    if (start == end) {
        return root;
    }

    int pos = search(inorder, start, end, curr);
    root->left = construct(preorder, inorder, start, pos - 1, idx);
    root->right = construct(preorder, inorder, pos + 1, end, idx);

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
int level_order(Node *root){
    queue<Node*> q;
    int count=0;
    q.push(root);
    q.push(NULL);
    while(!q.empty() && q.front()!=NULL ){
        if(q.front()!=NULL){
            cout<<q.front()->data<<" ";
            count++;
        }    
        Node *temp=q.front();
        q.pop();
        if(temp->left!=NULL){
            q.push(temp->left);
        }    
        if(temp->right!=NULL){
            q.push(temp->right);
        }
        if(q.front()==NULL){
            q.push(NULL);
            q.pop();
        }
    }
    cout<<endl;
    return count;
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
    vector<int> preorder = {1, 2, 4, 5, 3, 6};
    
    int idx = 0;  // Reset index for recursive calls
    Node* root = construct(preorder, inorder, 0, inorder.size() - 1, idx);
    cout<<"Level Order Traversal of the Given Binary Tree is:";
    cout<<"Total No of Nodes in the Given Binary Tree is:"<<level_order(root)<<endl;
    // Free allocated memory
    deleteTree(root);

    return 0;
}
