#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s;
    char n;
    while (cin >> n && n!='@')
    {
        if (n == '+')
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(a+b);
        }
        else if (n == '-')
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b-a);
        }
        else if (n == '*')
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(a*b);
        }
        else if (n == '/')
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b/a);
        }
        else
        {
            s.push(n-'0');
        }
    }
    cout<<s.top()<<endl;
    return 0;
}