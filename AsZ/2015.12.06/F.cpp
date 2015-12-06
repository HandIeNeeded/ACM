#include <bits/stdc++.h>
#define MAXN 1123
#define ll long long

using namespace std;

struct point {
    double x, y;
    point(double x = 0, double y = 0) : x(x), y(y) {};
} g[MAXN], pre[MAXN * 2], ans;

const double esp = 1e-3;

int sta[MAXN * 2], vis[MAXN * 2];
int w;

double ffabs(double x) {
    return x < 0 ? -x : x;
}

int cmp(double u, double v) {
    if (ffabs(u - v) <= esp) return 0;
    if (u < v) return -1;
    return 1;
}

int calc(int x, int y, int n) {
    int tmp = x;
    if (y == 1) tmp += n;
    return tmp;
}

void recover(int u, int n, int &pos, int &ifStone) {
    pos = u;
    ifStone = 0;
    if (u > n) {
        pos -= n;
        ifStone = 1;
    }
}

point midPoint(point A, point B) {
    return point ((A.x + B.x) / 2.0, (A.y + B.y) / 2.0);
}

double sqr(double x) {
    return x * x;
}
double dist(point A, point B) {
    return sqrt(sqr(A.x - B.x) + sqr(A.y - B.y));
}

int flag = 0;
int check(double lim, int n) {
    ans = point(-1, -1);
    if (cmp(1.0 * w, lim) <= 0) return 1;
    if (cmp(1.0 * w / 2.0, lim) <= 0) {
        ans = point(1.0 * w / 2, 1);
        return 1;
    }

    for (int i = 1; i <= n; ++i) {
        vis[i] = vis[i + n] = 0;
        pre[i] = pre[i + n] = point(-1, -1);
    }

    int l = 1, r = 0;
    for (int i = 1; i <= n; ++i) {
        if (cmp(g[i].x, lim) <= 0) {
            int u = calc(i, 0, n);
            vis[u] = 1;
            sta[++r] = u;
        } else if (cmp(g[i].x / 2, lim) <= 0) {
            int u = calc(i, 1, n);
            vis[u] = 1;
            sta[++r] = u;
            pre[u] = point(g[i].x / 2.0, g[i].y);
        }
    }

    for (; l <= r; ++l) {
        int u = sta[l];
        int pos, ifStone;
        recover(u, n, pos, ifStone);
        if (flag) {
            printf("%d %d\n", pos, ifStone);
            printf("%.3lf %.3lf\n", pre[u].x, pre[u].y);
        }
        if (cmp(w - g[pos].x, lim) <= 0) {
            ans = pre[u];
            return 1;
        }

        if (!ifStone && cmp((w - g[pos].x)/ 2.0, lim) <= 0) {
            ans = point((w + g[pos].x) / 2.0, g[pos].y);
            return 1;
        }

        for (int i = 1; i <= n; ++i) {
            if (ifStone == 0) {
                if (!vis[i] && cmp(dist(g[pos], g[i]), lim) <= 0) {
                    int v = i;
                    vis[v] = 1;
                    sta[++r] = v;
                    pre[v] = pre[u];
                }
                if (!vis[i + n] && cmp(dist(g[pos], g[i]) / 2, lim) <= 0) {
                    int v = i + n;
                    vis[v] = 1;
                    sta[++r] = v;
                    pre[v] = midPoint(g[pos], g[i]);
                }
            } else {
                if (!vis[i + n] && cmp(dist(g[pos], g[i]), lim) <= 0) {
                    int v = i + n;
                    vis[v] = 1;
                    sta[++r] = v;
                    pre[v] = pre[u];
                }
            }
        }
    }
    return 0;
}

int main() {
#ifndef HOME
    freopen("froggy.out", "w", stdout);
#endif
    freopen("froggy.in", "r", stdin);
    int n;
    scanf("%d%d", &w, &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf%lf", &g[i].x, &g[i].y);
    }
    double l = 0, r = w;
    int divideCnt = 100;
    for (; divideCnt; --divideCnt) {
     //for (; ffabs(r - l) <= esp; ) {
        double mid = (l + r) / 2;
        if (check(mid, n)) r = mid;
        else l = mid;
    }
    flag = 0;
    check(r, n);
   // printf("%.3f\n", l);
    if (ans.x < 0) {
        printf("0.1 0.1\n");
    } else {
        printf("%.5f %.5f\n", ans.x, ans.y);
    }
    return 0;
}
