#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// 递归函数，解压缩字符串
string decompress(const string& s, int& i) {
    string result;
    
    while (i < s.length()) {
        if (s[i] == '[') {
            i++; // 跳过'['
            
            // 解析重复次数m
            int m = 0;
            while (isdigit(s[i])) {
                m = m * 10 + (s[i] - '0');
                i++;
            }
            
            i++; // 跳过'|'
            
            // 递归解压缩S
            string nested = decompress(s, i);
            
            // 将解压缩后的S重复m次
            for (int j = 0; j < m; j++) {
                result += nested;
            }
            
        } else if (s[i] == ']') {
            i++; // 跳过']'
            return result; // 当前递归层的结束标志
        } else {
            // 普通字符直接添加到结果中
            result += s[i++];
        }
    }
    
    return result;
}

int main() {
    string s;
    cin >> s;
    
    int i = 0;
    string result = decompress(s, i);
    
    cout << result << endl;
    
    return 0;
}
