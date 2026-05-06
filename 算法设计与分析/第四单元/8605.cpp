#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    int k;
    
    while(cin >> a){
        if(a == "0") break;
        cin >> k;
        string result = "";
        for(int i = 0; i < a.length(); i++){
            while(!result.empty() && result.back() > a[i] && k > 0){
                result.pop_back();
                k--;
            }
            result.push_back(a[i]);
        }
        while(k > 0){
            result.pop_back();
            k--;
        }
        
        cout << result << endl;
    }
    
    return 0;
}
