#include<iostream>
#include<string>
using namespace std;
void permutations(string str,string newstr){
    if(str.size()==0){
        cout<<newstr<<endl;
        return ;
    }
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        string temp=str.substr(0,i)+str.substr(i+1,str.size());
        permutations(temp,newstr+ch);
    }
    return ;
}
int main(){
    permutations("abcd","");
    return 0;
}