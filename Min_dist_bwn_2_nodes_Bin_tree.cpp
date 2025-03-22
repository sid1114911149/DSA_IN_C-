#include<iostream>
#include<stdlib.h>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
struct Node {
    int data;
    struct Node *right,*left;
};
Node *create(int data){
    Node *temp=new Node;
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
class Btree{
    public:
    Node *root;
    Btree(){
        root=new Node;
        cout<<"Binary Tree created Successfully..\n";
    }
    Node *insert(Node *temp,int data){
        if(root==NULL){
            root=create(data);
            return temp;
        }
        if(temp==NULL){
            temp=create(data);
        }
        return temp;
    }
    int find_min_dist(Node *root,int target){
        if(root==NULL){
            return -1;
        }
        if(root->data==target){
            return 0;
        }
        return max(find_min_dist(root->left,target),find_min_dist(root->right,target))+1;
    }
};
int main(){
    Btree B;
    B.root=create(1);
    B.root->left=create(2);
    B.root->right=create(3);
    B.root->left->left=create(4);
    B.root->left->right=create(5);
    B.root->right->left=create(6);
    B.root->right->right=create(7);
    cout<<B.find_min_dist(B.root,5)<<endl;
    return 0;
}