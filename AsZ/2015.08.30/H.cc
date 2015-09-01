#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int MO = 12 * 60 * 60;

int main() {
#ifdef HOME
    freopen("H.in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, c;
        scanf("%d:%d:%d", &a, &b, &c);
        if (a >= 12) a -= 12;
        int A = a * 60 * 60 + b * 60  + c;
        int B = b * 60 + c;
        int C = c;
        int ax = A - 12 * B, ay = 120;
        ax = abs(ax), ay = abs(ay);
        if (ay * 180 < ax) {
            ax = 360 * ay - ax;
        }
        if (ax % ay == 0) {
            printf("%d ", ax / ay);
        }
        else {
            int d = __gcd(ax, ay);
            printf("%d/%d ", ax / d, ay / d);
        }
        int cx = A - 720 * C, cy = 120;
        cx = abs(cx), cy = abs(cy);
        if (cy * 180 < cx) {
            cx = 360 * cy - cx;
        }
        if (cx % cy == 0) {
            printf("%d ", cx / cy);
        }
        else {
            int d = __gcd(cx, cy);
            printf("%d/%d ", cx / d, cy / d);
        }
        int bx = B - 60 * C, by = 10;
        bx = abs(bx), by = abs(by);
        if (by * 180 < bx) {
            bx = 360 * by - bx;
        }
        if (bx % by == 0) {
            printf("%d \n", bx / by);
        }
        else {
            int d = __gcd(bx, by);
            printf("%d/%d \n", bx / d, by / d);
        }
    }

    return 0;
}

