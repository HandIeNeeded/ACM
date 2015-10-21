#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;
const int N = 1e5 + 5;
int p[N], vis[N], tot;

void prime() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) p[tot++] = i;
        for (int j = 0; j < tot && i * p[j] < N; j++) {
            vis[i * p[j]] = p[j];
            if (i % p[j] == 0) break;
        }
    }
}

int fac[20], cnt[20], num, ans;

void dfs(int dep, int now) {
    if (dep == num) {
        ans += (now >> 1 & 1) ? -1 : 1;
    }
    else {
        if (fac[dep] == 2) {
            dfs(dep + 1, now);
        }
        else {
            REP(i, cnt[dep] + 1) {
                dfs(dep + 1, now);
                now *= fac[dep];
            }
        }
    }
}

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif

    prime();
    int n;
    cin >> n;
    for (int i = 0; i < tot && p[i] * p[i] <= n; i++) {
        if (n % p[i] == 0) {
            fac[num] = p[i], cnt[num] = 0;
            while (n % p[i] == 0) {
                cnt[num]++;
                n /= p[i];
            }
            num++;
        }
    }
    if (n > 1) {
        fac[num] = n, cnt[num] = 1;
        num++;
    }
    REP(i, num) cnt[i] <<= 1;
    ans = 0;
    dfs(0, 1);
    cout << 4 * ans << endl;
    return 0;
}


