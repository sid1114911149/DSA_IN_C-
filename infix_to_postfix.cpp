#include <iostream>
#include <stack>
#include <string>
using namespace std;
string infix_to_postfix(string str)
{
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
    }return newstr;
}
int main()
{
    string str="((a+b-c*d)/(c*d-a/c))";
    cout<<"Postfix Expression for "<<str<<" is :"<<infix_to_postfix(str)<<endl;
    return 0;
}