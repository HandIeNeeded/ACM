#include <bits/stdc++.h>

#define LL long long
#define PB push_back
#define FI first
#define SE second

#define ALL(a) (a).begin(), (a).end()
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e6 + 5;
int a[N], dp[N], cnt[N];

int p[N], vis[N] = {0, 1}, tot;

void prime() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) p[tot++] = i, vis[i] = i;
        for (int j = 0; j < tot && i * p[j] < N; j++) {
            vis[i * p[j]] = p[j];
            if (i % p[j] == 0) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    prime();
    int n;
    cin >> n;
    REPP(i, 1, n) cin >> a[i], cnt[a[i]]++;
    int mx = a[n];
    dp[1] = cnt[1];
    REPP(i, 1, mx) {
        for (int j = i + i; j <= mx; j += i) {
            dp[j] = max(dp[j], dp[i] + cnt[j]);
        }
    }
    int ans = 0;
    REPP(i, 1, mx) ans = max(ans, dp[i]);
    cout << ans << endl;

    return 0;
}
