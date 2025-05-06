
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> res;

void dfs(string& s,int idx,int cnt,string path)
{
    if(cnt>4) return ;
    if(idx==s.size()&&cnt==4)
    {
        res.push_back(path);
        return ;
    }
    for(int l=1;l<=3;l++)
    {
        if(idx+l>s.size()) break;
        string temp = s.substr(idx,l);
        int num = stoi(temp);
        if((temp[0]=='0'&&temp.size()>1)||num>255) continue;
        dfs(s,idx+l,cnt+1,path+(path.empty()?"":".")+temp);
    }
}

int main()
{
    string s;
    cin>>s;
    dfs(s,0,0,"");
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    return 0;
}