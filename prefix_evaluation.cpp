#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
int evaluate(string str)
{
    stack<int> opnd;
    stack<char> optr;
    int n = str.size();
    for (int i = 0; i < n;)
    {
        if (str[i] == '^' || str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')
        {
            optr.push(str[i]);
            i += 2;
        }
        else
        {
            int a = 0;
            opnd.push(str[i]-'0');
            i += 1;
            while (i < n && str[i] != ' ')
            {
                a = opnd.top();
                opnd.pop();
                a = a * 10 + (str[i] - '0');
                opnd.push(a);
                i+=1;
            }
            i += 1;
        }
        if (opnd.size() >= 2 && !optr.empty())
        {
            int op1, op2;
            op1 = opnd.top();
            opnd.pop();
            op2 = opnd.top();
            opnd.pop();
            switch (optr.top())
            {
            case '^':
                opnd.push(pow(op2, op1));
                break;
            case '*':
                opnd.push(op2*op1);
                break;
            case '/':
                opnd.push(op2/op1);
                break;
            case '+':
                opnd.push(op2+op1);
                break;
            case '-':
                opnd.push(op2-op1);
                break;
            default:
                break;
            }
            optr.pop();
        }
        if(!opnd.empty()){
            cout<<opnd.top()<<endl;
        }
    }
    return opnd.top();
}
int main()
{
    string prefix="+ - * 4 5 + 6 3 / 18 2 * + 7 8 - 10 3";
    cout<<"value of the Given Prefix Expression "<<prefix<<" is :"<<evaluate(prefix)<<endl;
    return 0;
}