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
    void Heapify(int sidx,int idx){
        if(idx==-1){
            return ;
        }
        int lchild=2*sidx+1;
        int rchild=2*sidx+2;
        int largest=sidx;
        while(lchild<=idx && rchild<=idx){
           largest=arr[lchild]>arr[rchild]?lchild:rchild;
           largest=arr[sidx]>arr[largest]?sidx:largest;
           if(largest==sidx){
                return ;
           }
           swap(&arr[largest],&arr[sidx]);
           sidx=largest;
           lchild=2*sidx+1;
           rchild=2*sidx+2;
        }
        return ;
    }
    void HeapSort(){
        if(size==-1){
            cout<<"Heap is Empty..\n";
            return ;
        }
        int idx=size;
        while(idx>0){
            swap(&arr[idx],&arr[0]);
            idx--;
            Heapify(0,idx);
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
    cout<<"Heap before Sorting:";
    H.print();
    H.HeapSort();
    cout<<"Heap After Sorting:";
    H.print();
    return 0;
}