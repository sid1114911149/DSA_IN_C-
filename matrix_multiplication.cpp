#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main(){
    srand(time(NULL));
    int n;
    cout<<"Enter the Dimension of the matrix:";
    cin>>n;
    int arr1[n][n],arr2[n][n],arr3[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr1[i][j]=rand()%1000;
            arr2[i][j]=rand()%800;
        }
    }
    cout<<"GIVEN ARRAY 1:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"GIVEN ARRAY 2:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr3[i][j]=0;
            for(int k=0;k<n;k++){
                arr3[i][j]+=arr1[j][k]*arr2[k][j];
            }
        }
       
    }
    cout<<"PRODUCT OF GIVEN ARRAYS IS :\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr3[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}