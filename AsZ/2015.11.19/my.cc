#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;

int vis[N], ans[N], val[N], pos[N], pre[N];

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        REPP(i, 1, n) vis[i] = ans[i] = 0, pre[i] = i;
        REPP(i, 1, n) scanf("%d", val + i), pos[val[i]] = i;
        val[n + 1] = 0;
        vis[0] = 1;
        REPP(i, 1, n) {
            if (ans[i]) continue;
            int p = pos[i];
            if (pre[i] == i) {
                int mx = 0, np = 0, now = p;
                while (now >= 1 && !vis[val[now]]) {
                    if (val[now] > mx) {
                        mx = val[now];
                        np = now;
                    }
                    now--;
                }
                if (val[p + 1] < mx || vis[val[p + 1]]) {
                    REPP(j, np, p) {
                        if (j < p) ans[val[j]] = val[j + 1];
                        else ans[val[j]] = val[np];
                        vis[val[j]] = 1;
                    }
                }
                else {
                    ans[i] = val[p + 1];
                    vis[val[p + 1]] = 1;
                    pre[val[p + 1]] = i;
                }
            }
            else {
               int mx = pre[i];
               if (val[p + 1] < mx || vis[val[p + 1]]) {
                   ans[i] = pre[pre[i]];
                   vis[pre[i]] = 1;
               }
               else {
                   ans[i] = val[p + 1];
                   vis[val[p + 1]] = 1;
                   pre[val[p + 1]] = pre[i];
               }
            }
        }
        REPP(i, 1, n) printf("%d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}
