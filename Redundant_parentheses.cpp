#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool check_balanced(string str){
    stack<char> stk;
    for(int i=0;i<str.size();i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            stk.push(str[i]);
        }else if(str[i]==']'){
            if(!stk.empty() && stk.top()=='['){
                stk.pop();
            }else{
                return false;
            }
        }else if(str[i]==')'){
            if(!stk.empty() && stk.top()=='('){
                stk.pop();
            }else{
                return false;
            }
        }else if(str[i]=='}'){
            if(!stk.empty() && stk.top()=='{'){
                stk.pop();
            }else{
                return false;
            }
        }
    }
    if(stk.empty()){
        return true;
    }
    return false;
}
bool check_redundancy(string str){
    if(!check_balanced(str)){
        cout<<"Given String "<<str<<" is NOT Balanced..\n";
        return true;
    }
    int n=str.size();
    stack<char> optr,par;
    for(int i=0;i<n;i++){
        if(str[i]!=')' && str[i]!=']' && str[i]!='}'){
            par.push(str[i]);
        }else{
            if(par.top()!='+' && par.top()!='-' && par.top()!='*' && par.top()!='/' && par.top()!='^'){
                return true;
            }
            else if(str[i]==')'){
                while(!par.empty() && par.top()!='('){
                    par.pop();
                }
                par.pop();
            }else if(str[i]==']'){
                while(!par.empty() && par.top()!='['){
                    par.pop();
                }
                par.pop();
            }else if(str[i]=='}'){
                while(!par.empty() && par.top()!='{'){
                    par.pop();
                }
                par.pop();
            }
        }
    }
    return false;
}
int main(){
    string str="(a+b+((c*d))";
    if(check_redundancy(str)){
        cout<<"Given string "<<str<<" has Redundancy\n";
    }else{
        cout<<"Given string "<<str<<" has NO Redundancy\n";
    }
    return 0;
}