#include <bits/stdc++.h>

using namespace std;

int random(int x) {
    return rand() % x + 1;
}
int main() {
    freopen("K.in", "w", stdout);
    int T = 10;
    srand(time(0) % clock());

    printf("%d\n", T);
    for (; T; --T) {
        int N = 4000;
        printf("%d\n", N);
        int lim = 1000000000;
        for (int i = 1; i <= N; ++i) {
            printf("%d %d\n", random(lim), random(lim));
        }
    }
    return 0;
}
