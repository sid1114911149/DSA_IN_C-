#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main(){
    srand(time(NULL));
    int n;
    cout<<"Enter the Dimension of the matrix:";
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=rand()%1000;
        }
    }
    cout<<"GIVEN ARRAY:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
           int t=arr[i][j];
           arr[i][j]=arr[j][i];
           arr[j][i]=t;
        }
    }
    cout<<"TRANSPOSE OF GIVEN ARRAY:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}