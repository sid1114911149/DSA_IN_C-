#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
int  evaluate_postfix(string str)
{
    stack<int> stk;
    int o1,o2;
    for (int i = 0; i < str.size(); )
    {
        switch (str[i])
        {
        case '^':
            o1 = stk.top();
            stk.pop();
            o2 = stk.top();
            stk.pop();
            stk.push(pow(o2, o1));
            break;
        case '*':
            o1 = stk.top();
            stk.pop();
            o2 = stk.top();
            stk.pop();
            stk.push(o2 * o1);
            break;
        case '/':
            o1 = stk.top();
            stk.pop();
            o2 = stk.top();
            stk.pop();
            stk.push(o2 / o1);
            break;
        case '+':
            o1 = stk.top();
            stk.pop();
            o2 = stk.top();
            stk.pop();
            stk.push(o2 + o1);
            break;
        case '-':
            o1 = stk.top();
            stk.pop();
            o2 = stk.top();
            stk.pop();
            stk.push(o2-o1);
            break;
        default:
            stk.push(str[i]-'0');
            break;
        }
        i+=1;
        while(str[i]!=' '){
            int a=(stk.top())*10;
            a+=str[i]-'0';
            stk.pop();
            stk.push(a);
            i++;
        }
        i+=1;
        cout<<stk.top()<<endl;
    }
    return stk.top();
}
int main()
{
    string str = "5 6 2 + * 12 4 / - ";
    cout << "Postfix Expression for " << str << " is :" << evaluate_postfix(str) << endl;
    return 0;
}