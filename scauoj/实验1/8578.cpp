#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("The List is:");
    for(int i:a) printf("%d ",i);
    printf("\n");
    printf("The turned List is:");
    for(auto it=a.rbegin();it!=a.rend();++it) {
        printf("%d ",*it);
    }
    printf("\n");
    return 0;
}