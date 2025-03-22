#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<time.h>
using namespace std;

struct Node{
    int data, height;
    struct Node *right, *left;
};

struct Node *create(int data){
    struct Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->height = 1;
    return temp;
}

int get_height(Node *temp){
    if(temp == NULL) return 0;
    int lheight = get_height(temp->left);
    int rheight = get_height(temp->right);
    return max(lheight, rheight) + 1;
}

int get_Balance_factor(Node *temp){
    if(temp == NULL) return 0;
    return get_height(temp->left) - get_height(temp->right);
}

struct Node *Left_rotate(struct Node *temp){
    if(temp == NULL) return NULL;
    struct Node *temp2 = temp->right;
    temp->right = temp2->left;
    temp2->left = temp;
    temp->height = get_height(temp);
    temp2->height = get_height(temp2);
    return temp2;
}

struct Node *Right_rotate(struct Node *temp){
    if(temp == NULL) return NULL;
    struct Node *temp2 = temp->left;
    temp->left = temp2->right;
    temp2->right = temp;
    temp->height = get_height(temp);
    temp2->height = get_height(temp2);
    return temp2;
}
Node *get_succ(Node *temp){
    temp=temp->right;
    while(temp!=NULL && temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

class HBST{
public:
    Node *root;
    HBST(){
        root = NULL;
    }
    Node *insert(Node *temp, int data){
        if(root == NULL){
            root = create(data);
            return root;
        }
        if(temp == NULL){
            temp = create(data);
        } else if(temp->data > data){
            temp->left = insert(temp->left, data);
        } else {
            temp->right = insert(temp->right, data);
        }
        temp->height = get_height(temp);
        int bf = get_Balance_factor(temp);
        if(bf > 1 && data < temp->left->data){
            temp = Right_rotate(temp);
        }
        if(bf > 1 && data > temp->left->data){
            temp->left = Left_rotate(temp->left);
            temp = Right_rotate(temp);
        }
        if(bf < -1 && data > temp->right->data){
            temp = Left_rotate(temp);
        }
        if(bf < -1 && data < temp->right->data){
            temp->right = Right_rotate(temp->right);
            temp = Left_rotate(temp);
        }
        return temp;
    }
    void search(Node *temp,int data){
        if(temp==NULL){
            cout<<"Data Not Found in the Given Tree..\n";
            return ;
        }
        if(temp->data==data){
            cout<<"Data Found in the Tree..\n";
            return ;
        }else if(temp->data<data){
            return search(temp->right,data);
        }else{
            return search(temp->left,data);
        }
    }
    Node *Delete(Node *temp,int data){
        if(temp==NULL){
            cout<<"Data Not Found in the GIven Tree..\n";
            return NULL;
        }
        if(temp->data>data){
            temp->left=Delete(temp->left,data);
        }else if(temp->data<data){
            temp->right=Delete(temp->right,data);
        }else{
            if(temp->left==NULL && temp->right==NULL){
                delete temp;
                return NULL;
            }else if(temp->left==NULL && temp->right!=NULL){
                Node *temp2=temp->right;
                delete temp;
                return temp2;
            }else if(temp->left!=NULL && temp->right==NULL){
                Node *temp2=temp->left;
                delete temp;
                return temp2;
            }else{
                Node *succ=get_succ(temp);
                temp->data=succ->data;
                temp->right=Delete(temp->right,succ->data);
            }
        }
        int bf=get_Balance_factor(temp);
        if(bf>1 && get_Balance_factor(temp->left)>=0){
            temp=Right_rotate(temp);
        }
        if(bf>1 && get_Balance_factor(temp->left)<0){
            Node *temp2=Left_rotate(temp->left);
            temp=Right_rotate(temp);
        }
        if(bf<-1 && get_Balance_factor(temp->right)<=0){
            temp=Left_rotate(temp);
        }
        if(bf<-1 && get_Balance_factor(temp->right)>0){
            Node *temp=Right_rotate(temp->right);
            temp=Left_rotate(temp);
        }
        return temp;
    }
    void preorder(Node *temp){
        if(temp == NULL) return;
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
    void inorder(Node *temp){
        if(temp == NULL) return;
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
    void postorder(Node *temp){
        if(temp == NULL) return;
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
};

int main(){
    srand(time(NULL));
    HBST T;
    T.root=T.insert(T.root, 10);
    T.root=T.insert(T.root, 28);
    T.root=T.insert(T.root, 30);
    T.root=T.insert(T.root, 97);
    T.root=T.insert(T.root, 63);
    T.root=T.insert(T.root, 6);
    T.root=T.insert(T.root, 3);
    T.root=T.insert(T.root, 44);
    T.root=T.insert(T.root, 49);
    T.root=T.insert(T.root, 18);
    cout << "Preorder: ";
    T.preorder(T.root);
    cout << endl;
    cout << "Inorder: ";
    T.inorder(T.root);
    cout << endl;
    cout << "Postorder: ";
    T.postorder(T.root);
    cout << endl<<endl;
    T.root=T.Delete(T.root,63);
    cout << "Preorder: ";
    T.preorder(T.root);
    cout << endl;
    cout << "Inorder: ";
    T.inorder(T.root);
    cout << endl;
    cout << "Postorder: ";
    T.postorder(T.root);
    cout << endl<<endl;
    T.root=T.Delete(T.root,97);
    cout << "Preorder: ";
    T.preorder(T.root);
    cout << endl;
    cout << "Inorder: ";
    T.inorder(T.root);
    cout << endl;
    cout << "Postorder: ";
    T.postorder(T.root);
    cout << endl<<endl;
    T.root=T.Delete(T.root,0);
    cout << "Preorder: ";
    T.preorder(T.root);
    cout << endl;
    cout << "Inorder: ";
    T.inorder(T.root);
    cout << endl;
    cout << "Postorder: ";
    T.postorder(T.root);
    cout << endl;
    return 0;
}
