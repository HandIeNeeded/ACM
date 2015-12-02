#include <bits/stdc++.h>
//#define MAXN 1123456
#define MAXM 4123456

using namespace std;

typedef int arrayM[MAXM];

struct point {
    point (int x = 0, int y = 0) : x(x), y(y) {}
    int x, y;
};

const int gx[] = {-1, 0, 1, 0};
const int gy[] = {0, 1, 0, -1};

arrayM sum;
long long g[MAXM];

int getPos(int x, int y, int n, int m) {
    return x * (m + 1) + y;
}

void link(int pos, int s) {
    sum[pos] += s;
}

long long sqr(int x) {
    return 1LL * x * x;
}

int main() {
#ifdef HOME
    freopen("B.in", "r", stdin);
#endif // HOME
    int T;
    scanf("%d\n", &T);
    for (int ca = 1; ca <= T; ++ca) {
        int n, m, k;
        scanf("%d %d %d\n", &n, &m, &k);
        point now = point(0, 0);
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j) {
                int pos = getPos(i, j, n, m);
                sum[pos] = 0;
            }
        for (int i = 1; i <= k; ++i) {
            string st = "URDL";
            int step;
            char ch;
            scanf("%c %d\n", &ch, &step);
            int p = 0;
            for (p = 0; p < 4; ++p) {
                if (ch == st[p]) break;
            }
            point newNow = point(now.x + gx[p] * step, now.y + gy[p] * step);
            if (p == 1 || p == 3) {
                link(getPos(now.x, now.y, n, m), 1);
                link(getPos(newNow.x, newNow.y, n, m), -1);
            } //else if (p == 3) {
                //link(getPos(now.x, now.y, n, m), -1);
                //link(getPos(newNow.x, newNow.y, n, m), 1);
            //}
            now = newNow;
        }

        long long ans = 0;
        for (int i = 0; i < m; ++i)
            g[i] = 0;
        for (int i = 0; i < n; ++i) {
            int tmp = 0;
            for (int j = 0; j < m; ++j) {
                tmp += sum[getPos(i, j, n, m)];
                g[j] += tmp;
                ans += sqr(g[j]);
            }
        }
        printf("Case #%d: %lld\n", ca, ans);
    }
    return 0;
}
