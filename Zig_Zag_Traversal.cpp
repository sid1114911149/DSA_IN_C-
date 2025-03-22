#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
struct Node{
    int data;
    struct Node *left,*right;
};
Node *create(int data){
    Node *temp=new Node;
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
class BT{
    public:
    Node *root;
    BT(){
        root=NULL;
        cout<<"Binary Tree is Created Successfully..\n";
    }
    void inorder(Node *temp){
        if(temp==NULL){
            return ;
        }
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }
    void Zig_Zag(){
        stack<Node*> currLevel;
        stack<Node *> NextLevel;
        vector<int> v;
        int LtoR=0;
        currLevel.push(root);
        Node*temp;
        while(!NextLevel.empty() || !currLevel.empty()){
            while(!currLevel.empty()){
                temp=currLevel.top();
                v.push_back(temp->data);
                currLevel.pop();
                if(LtoR==1){
                    if(temp->left!=NULL){
                        NextLevel.push(temp->left);
                    }
                    if(temp->right!=NULL){
                        NextLevel.push(temp->right);
                    }
                }else{
                    if(temp->right!=NULL){
                        NextLevel.push(temp->right);
                    }
                    if(temp->left!=NULL){
                        NextLevel.push(temp->left);
                    }
                }
            }
            LtoR=LtoR^1;
            currLevel.swap(NextLevel);
        }
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<' ';
        }cout<<endl;
    }
};
int main(){
    BT B;
    B.root=create(5);
    B.root->left=create(3);
    B.root->right=create(7);
    B.root->left->left=create(2);
    B.root->left->right=create(4);
    B.root->right->left=create(6);
    B.root->right->right=create(8);
    cout<<"Zig-Zag Traversal of Given Btree:";
    B.Zig_Zag();
    return 0;
}
