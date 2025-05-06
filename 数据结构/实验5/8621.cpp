#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int key;
    cin>>key;
    if(!binary_search(a.begin(),a.end(),key))
    {
        cout<<"The element is not exist."<<endl;
        return 0;
    }
    cout<<"The element position is "<<(lower_bound(a.begin(),a.end(),key)-a.begin())<<"."<<endl;
    return 0;
}