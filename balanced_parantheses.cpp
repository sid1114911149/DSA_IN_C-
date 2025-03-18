#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool check(string str){
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
int main(){
    string str="({[a*b+({b-c+{{a*()}}+c*d})]})";
    string str2="({[a*b+({b-c+{{a*(}}+c*d})]})";
    if(check(str)){
        cout<<str<<" is Balanced in Parentheses..\n";
    }else{
        cout<<str<<" is NOT Balanced in Parentheses..\n";
    }
    if(check(str2)){
        cout<<str2<<" is Balanced in Parentheses..\n";
    }else{
        cout<<str2<<" is NOT Balanced in Parentheses..\n";
    }
    return 0;
}