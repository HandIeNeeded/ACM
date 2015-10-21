#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("hack.in", "r", stdin);

#ifndef HOME
    freopen("hack.out", "w", stdout);
#endif
    scanf("%d", &n);
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] ^ a[i];
    }

    return 0;
}
