#include<iostream>
#include<vector>
#include<map>
#include<stdlib.h>
using namespace std;
struct Node{
    int data;
    struct Node *left,*right;
};
Node * Newnode(int data){
    Node *temp=new Node;
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
void VerticalTraversal(map<int,vector<int>> &M,Node *temp,int idx){
    if(temp==NULL){
        return ;
    }
    M[idx].push_back(temp->data);
    VerticalTraversal(M,temp->left,idx-1);
    VerticalTraversal(M,temp->right,idx+1);
}
int main(){
    Node *root=Newnode(1);
    root->left=Newnode(2);
    root->right=Newnode(3);
    root->left->left=Newnode(4);
    root->left->right=Newnode(5);
    root->right->left=Newnode(6);
    root->right->right=Newnode(7);
    map<int,vector<int>> M;
    int idx=0;
    VerticalTraversal(M,root,idx);
    for(auto it:M){
        for(int i=0;i<it.second.size();i++){
            cout<<it.second[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}