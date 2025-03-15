#include<iostream>
using namespace std;
void sub_array(int arr[],int n,int sum){
    if(n==0){
        return ;
    }
    int i=0,j=0,st=0,end=0,currsum=0;
    if(sum==currsum){
        cout<<i+1<< " " <<j<< endl;
    }
    while(j<n){
        currsum+=arr[j];
        while(currsum>sum){
            currsum-=arr[i];
            i++;
        }
        if(currsum==sum){
            st=i+1;
            end=j+1;
            break;
        }
        j++;
    }
    cout<<"SUBARRAY IS:"<<st<<" to "<<end<<endl;
}
int main(){
    int n,sum;
    cout<<"Enter size of the array:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter Sum:";
    cin>>sum;
    sub_array(arr,n,sum);
    return 0;
}
