#include <iostream>
#include <stack>
#include <string>
using namespace std;
string reverse(string str){
    int n=str.size();
    for(int i=0;i<n/2;i++){
        char ch=str[i];
        str[i]=str[n-1-i];
        str[n-1-i]=ch;
    }
    return str;
}
string format(string str){
    int n=str.size();
    for(int i=0;i<n;i++){
        if(str[i]=='('){
            str[i]=')';
        }else if(str[i]==')'){
            str[i]='(';
        }
    }
    return str;
}
string infix_to_prefix(string str)
{
    str=reverse(str);
    str=format(str);
    string newstr = "";
    stack<char> stk;
    for (int i = 0; i < str.size(); i++)
    {
        while (!stk.empty() && stk.top() == str[i] && str[i]!='(')
        {
            newstr = newstr + stk.top();
            stk.pop();
        }
        switch (str[i])
        {
        case '(':
            stk.push(str[i]);
            break;
        case '^':
            stk.push(str[i]);
            break;
        case '*':
            if ((stk.empty() || stk.top() == '('))
            {
                stk.push(str[i]);
            }
            else
            {
                while (!stk.empty() && (stk.top() == '/' || stk.top()=='^') && stk.top() != '(')
                {
                    newstr += stk.top();
                    stk.pop();
                }
                stk.push(str[i]);
            }
            break;
        case '/':
            if ((stk.empty() || stk.top() == '('))
            {
                stk.push(str[i]);
            }
            else
            {
                while (!stk.empty() && (stk.top() == '*' || stk.top()=='^') && stk.top() != '(')
                {
                    newstr += stk.top();
                    stk.pop();
                }
                stk.push(str[i]);
            }
            break;
        case '+':
            if ((stk.empty() || stk.top() == '('))
            {
                stk.push(str[i]);
            }
            else
            {
                while (!stk.empty() && stk.top() != '(')
                {
                    newstr += stk.top();
                    stk.pop();
                }
                stk.push(str[i]);
            }
            break;
        case '-':
            if ((stk.empty() || stk.top() == '('))
            {
                stk.push(str[i]);
            }
            else
            {
                while (!stk.empty() && stk.top() != '(')
                {
                    newstr += stk.top();
                    stk.pop();
                }
                stk.push(str[i]);
            }
            break;
        case ')':
            while (!stk.empty() && stk.top() != '(')
            {
                newstr += stk.top();
                stk.pop();
            }
            stk.pop();
            break;
        default:
            newstr+=str[i];
            break;    
        }
    }
    newstr=reverse(newstr);
    return newstr;
}
int main()
{
    string str="((a+b-c*d)/(c*d-a/c))";
    cout<<"Postfix Expression for "<<str<<" is :"<<infix_to_prefix(str)<<endl;
    return 0;
}