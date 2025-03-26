#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define Max 100
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
class Heap{
    public:
    int arr[Max],size;
    Heap(){
        size=-1;
        cout<<"Heap is createdd Successfully\n";
    }
    void insert(int data){
        if(size==-1){
            size++;
            arr[size]=data;
            return ;
        }
        size++;
        arr[size]=data;
        int child=size;
        int parent=(child-1)/2;
        while(parent>=0 && arr[parent]<arr[child]){
            swap(&arr[parent],&arr[child]);
            child=parent;
            parent=(child-1)/2;
        }
        return ;
    }
    void deletion(int target){
        if(size==-1){
            cout<<" No Elements to Delete..\n";
            return ;
        }
        int idx=-1;
        for(int i=0;i<=size;i++){
            if(arr[i]==target){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            cout<<target<<" Not Found in the Given Heap..\n";
            return ;
        }
        arr[idx]=arr[size];
        delete(&arr[size]);
        size--;
        int lchild=2*idx+1;
        int rchild=2*idx+2;
        int largest=idx;
        while(lchild<=size && rchild<=size){
           largest=arr[lchild]>arr[rchild]?lchild:rchild;
           largest=arr[idx]>arr[largest]?idx:largest;
           if(largest==idx){
                return ;
           }
           swap(&arr[largest],&arr[idx]);
           idx=largest;
           lchild=2*idx+1;
           rchild=2*idx+2;
        }
        return ;
    }
    void print(){
        if(size==-1){
            cout<<"Heap is Empty..\n";
            return ;
        }
        for(int i=0;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
        return ;
    }
};
int main(){
    Heap H;
    for(int i=0;i<=10;i++){
        H.insert(i);
    }
    H.print();
    H.deletion(10);
    H.print();
    return 0;
}