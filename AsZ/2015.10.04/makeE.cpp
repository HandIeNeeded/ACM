#include <bits/stdc++.h>
#define MAXN 11234

using namespace std;

double a[MAXN];

double esp = 1e-7;

int random(int x) {
    int sign = 1;
    if (rand() & 1) sign = -1;
    return sign * (abs(rand() * rand() * rand() * rand()) % x);
}

int main() {
    int n;
    n = rand() % 5 + 2;
    srand(clock() % time(0));
    printf("%d\n", n);
    for (int i = 1; i <= n; ++i)
        printf("%.3lf ", random(200) / 100.0);
    return 0;
}
