#include<iostream>
#include<string>
using namespace std;
void replace_word(string str,int idx,string newstr){
    if(idx>=str.size()){
        str=newstr;
        cout<<str<<endl;
        return ;
    }
    if(idx<str.size()-1)
        if(str[idx]=='p' && str[idx+1]=='i'){
            newstr=newstr+"3.14";
            idx+=2;
        }else{
            newstr=newstr+str[idx];
            idx+=1;
        }
    else{
        newstr=newstr+str[idx];
        idx+=1;
    }    
    replace_word(str,idx,newstr);
    return ;
}
int main(){
    replace_word("pippxxppiixipi",0,"");
    return 0;
}