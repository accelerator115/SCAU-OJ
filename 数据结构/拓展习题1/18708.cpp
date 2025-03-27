#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int max_sum = -10001; 
    int current_sum = 0;  

    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        current_sum = max(num, current_sum + num);
        max_sum = max(max_sum, current_sum);
    }

    printf("%d\n", max_sum);

    return 0;
}