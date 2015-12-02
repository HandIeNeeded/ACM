#include <bits/stdc++.h>

using namespace std;

int random(int mo) {
    return rand() % mo + 1;
}

int main() {
#ifdef HOME
    freopen("I.in", "w", stdout);
#endif // HOME
    srand(time(0) % clock());
    int T = 3;
    printf("%d\n", T);
    int lim = 1000000000;
    for (int i = 1; i <= T; ++i) {
        //int n = 6, m = 6;
        int limN = 10;
        int n = random(limN);
        int m = random(limN);
        printf("%d %d\n", n, m);
        for (int i = 1; i <= n + m; ++i) {
            printf("%d %d\n", random(lim), random(lim));
        }
    }
    return 0;
}
