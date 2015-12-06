#include <bits/stdc++.h>

using namespace std;

int g[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int prt(int x) {
    if (x < 10) printf("0");
    printf("%d", x);
}

int check(int x) {
    return g[x % 10] + g[x / 10];
}
int main() {
    freopen("alarm.in", "r", stdin);
#ifndef HOME
    freopen("alarm.out", "w", stdout);
#endif // HOME
    int n;
    scanf("%d", &n);
    for (int hh = 0; hh < 24; ++hh)
        for (int mm = 0; mm < 60; ++mm)
            if (check(hh) + check(mm) == n) {
                prt(hh);
                printf(":");
                prt(mm);
                printf("\n");
                return 0;
            }
    printf("Impossible\n");
    return 0;
}
