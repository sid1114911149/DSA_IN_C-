#include<iostream>
#include<string>
using namespace std;
void permutations(string str,string newstr,int idx){
    if(idx==str.size()){
        cout<<newstr<<endl;
        return ;
    }
    char ch=str[idx];
    int ch2=(int)ch;
    string ch3=to_string(ch2);
    permutations(str,newstr,idx+1);
    permutations(str,newstr+ch,idx+1);
    permutations(str,newstr+ch3,idx+1);
    return ;
}
int main(){
    permutations("AB","",0);
    return 0;
}
