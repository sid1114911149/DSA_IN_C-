#include<iostream>
using namespace std;
void permutations(string str,string newstr,int idx){
    if(idx==str.size()){
       cout<<newstr<<endl;
       return ;
    }
    char ch=str[idx];
    permutations(str,newstr,idx+1);
    permutations(str,newstr+ch,idx+1);
    return ;
}
int main(){
    permutations("abcd","",0);
    return 0;
}