
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;
int main()
{
    cin>>s;
    int lens=s.size();
    for(int i=0;i<s.size();i++)
    {
        string temp=s;
        reverse(temp.begin(),temp.end());
        if(temp==s) break;
        else
            s.insert(s.begin()+lens,s[i]);
    }
    cout<<s;
    return 0;
}