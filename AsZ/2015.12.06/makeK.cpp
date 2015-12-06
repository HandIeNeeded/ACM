#include <bits/stdc++.h>

using namespace std;

int random(int x) {
    return rand() % x + 1;
}

int main() {
#ifndef HOME
    //freopen(".out", "w", stdout);
#endif
    freopen("king.in", "w", stdout);
    srand(time(0) % clock());
    int n = 20, m = n + 20;
    printf("%d %d\n", n, m);
    for (int i = 1; i <= m; ++i) {
        printf("%d %d\n", random(n), random(n));
    }
    return 0;
}
