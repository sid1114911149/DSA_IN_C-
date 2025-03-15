#include<iostream>
#include<string>
using namespace std;
string values[10]={"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void combinations(string str,int idx,string newstr){
    if(idx==str.size()){
        cout<<newstr<<endl;
        return ;
    }
    int i=str[idx]-'0';
    string temp=values[i];
    for(int i=0;i<temp.size();i++){
        combinations(str,idx+1,newstr+temp[i]);
    }
    return ;
}
int main(){
    combinations("236",0,"");
    return 0;
}