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
    Node *get_left_min(Node *temp){
        if(temp==NULL){
            return temp;
        }
        temp=temp->left;
        while(temp->right!=NULL && temp!=NULL){
            temp=temp->right;
        }
        return temp;
    }
    Node *flatten(Node *temp){
        if(temp->left==NULL && temp->right==NULL){
            return temp;
        }
        if(temp->left==NULL){
            flatten(temp->right);
        }else{
            Node *temp2=get_left_min(temp);
            temp2->right=temp->right;
            temp->right=temp->left;
            temp->left=NULL;
            flatten(temp->right);
        }
        return temp;
    }
    void preorder(Node *temp){
        if(temp==NULL){
            return ;
        }
        cout<<temp->data<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }
    void Print_List(Node *temp){
        if(temp==NULL){
            return ;
        }
        cout<<temp->data<<" ";
        Print_List(temp->right);
        return ;
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
    cout<<"Before Flattening the Tree Preorder Traversal:";
    B.preorder(B.root);
    cout<<endl;
    cout<<"After Flattening the Tree to Doubly Linked List:";
    B.root=B.flatten(B.root);
    B.Print_List(B.root);
    return 0;
}