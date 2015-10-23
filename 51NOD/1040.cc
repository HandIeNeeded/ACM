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

int phi(int x) {
    int ans = 1;
    for (int i = 0; i < tot && p[i] * p[i] <= x; i++) {
        if (x % p[i] == 0) {
            x /= p[i];
            ans *= p[i] - 1;
            while (x % p[i] == 0) {
                x /= p[i];
                ans *= p[i];
            }
        }
    }
    if (x > 1) ans *= x - 1;
    return ans;
}

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif
    prime();

    int n;
    cin >> n;
    LL ans = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans += 1LL * i * phi(n / i);
            if (i * i != n) {
                ans += 1LL * n / i * phi(i);
            }
        }
    }
    cout << ans << endl;

    return 0;
}

