#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
struct node{
    int data;
    struct node *next,*prev;
}*temp;
struct node *newnode(int data){
    struct node *temp=new struct node ;
    temp->data=data;
    temp->next=temp->prev=NULL;
    return temp;
}
class List{
    public:
    node *head;
    List(){
        head=NULL;
        cout<<"Doubly Linked List is created Successfully..\n";
    }
    ~List() {
        node* current = head;
        while (current != NULL) {
            node* next = current->next;
            delete current;
            current = next;
        }
    }
    
    void insert(int data){
        if(head==NULL){
            head=newnode(data);
        }
        else{
            struct node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            struct node *temp2=newnode(data);
            temp->next=temp2;
            temp2->prev=temp;
        }
    }
    void deletion(int data){
        if(head==NULL){
            cout<<"List is empty..\n";
            return ;
        }
        struct node *temp=head;
        if(head->data==data){
            temp=temp->next;
            temp->prev=NULL;
            delete(head);
            head=temp;
            return ;
        }else{
            while(temp->next->data!=data){
                temp=temp->next;
            }
            struct node *temp2=temp->next;
            temp->next=temp2->next;
            struct node *temp3=temp2->next;
            temp3->prev=temp;
            delete(temp2);
            return ;
        }
        cout<<data<<" is NOT FOUND in the given List..\n";
        return ;
    }
    void search(int data){
        if(head==NULL){
            cout<<"List is empty..\n";
            return ;
        }
        struct node *temp=head;
        while(temp!=NULL){
            if(temp->data=data){
                cout<<data<<" is FOUND in the goiven List..\n";
                return ;
            }
            temp=temp->next;
        }
        cout<<data<<" is NOT FOUND in the given List..\n";
        return ;
    }
    void reversal(){
        struct node *curr=head;
        struct node *prev=NULL,*curr2=NULL;
        while(curr!=NULL){
            curr2=curr->next;
            curr->next=prev;
            prev=curr;
            curr=curr2;
            prev->prev=curr;
        }
        head=prev;
    }
    node* reverse_k_nodes(node* head, int k) {
        if (!head) return NULL;
        node* current = head;
        node* next = NULL;
        node* prev = NULL;
        int count = 0;
    
        // Reverse first k nodes
        while (current != NULL && count < k) {
            next = current->next;
            current->next = prev;
            current->prev = next;
            prev = current;
            current = next;
            count++;
        }
    
        if (next != NULL) {
            head->next = reverse_k_nodes(next, k);
            if (head->next != NULL) {
                head->next->prev = head;
            }
        }
    
        return prev;
    }    
    void make_cycle(int pos){
        node *temp=head;
        int count=0;
        while(temp!=NULL and count<pos-1){
            temp=temp->next;
            count++;
        }
        node *temp2=head;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp2->next=temp;
    }
    bool detect_and_remove_cycle(){
        node * slow=head;
        node *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                fast=head;
                while(fast->next!=slow->next){
                    fast=fast->next;
                    slow=slow->next;
                }
                slow->next=NULL;
                return true;
            }
        }
        return false;
    }
    void append_last_k_nodes(int k){
        if(k==0){
            return ;
        }
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        node *temp2=temp;
        for(int i=0;i<k;i++){
            temp=temp->prev;
        }
        node *temp3=temp->next;
        temp->next=NULL;
        temp3->prev=NULL;
        temp2->next=head;
        head->prev=temp2;
        head=temp3;
    }
    void print(){
        struct node *temp=head;
        while(temp!=NULL){
            cout<<temp->data;
            temp=temp->next;
            if(temp!=NULL)
                cout<<"->";
        }
        cout<<endl;
        return ;
    }
};
int main(){
    List l1;
    for(int i=0;i<10;i++){
        l1.insert(rand()%100);
    }
    l1.print();
    l1.reversal();
    l1.print();
    l1.deletion(69);
    cout<<"after deletion of 69:\n";
    l1.print();
    l1.head=l1.reverse_k_nodes(l1.head,2);
    l1.print();
    l1.make_cycle(3);
    cout<<"Print 1 if Cycle Exists Else 0:"<<l1.detect_and_remove_cycle()<<endl;
    l1.print();
    l1.append_last_k_nodes(4);
    l1.print();
    return 0;
}