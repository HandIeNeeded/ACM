#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("grave.in", "r", stdin);
#ifndef HOME
    freopen("grave.out", "w", stdout);
#endif // HOME

    int x1, y1, x2, y2, x3, y3, x4, y4, w, h;
    int W, H, L, R, U, D;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
    scanf("%d %d", &w, &h);
    W = x2 - x1, H = y2 - y1;
    U = y2 - y4, D = y3 - y1;
    L = x3 - x1, R = x2 - x4;
    bool flag = false;
    if ((w <= L || w <= R) && h <= H)
        flag = true;
    if ((h <= U || h <= D) && w <= W)
        flag = true;
    printf("%s\n", flag ? "Yes" : "No");

    return 0;
}

