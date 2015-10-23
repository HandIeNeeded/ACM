#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;

int p[N], vis[N] = {0, 1}, tot;
int mobius[N] = {0, 1};

void prime() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) p[tot++] = vis[i] = i, mobius[i] = -1;
        for (int j = 0; j < tot && i * p[j] < N; j++) {
            vis[i * p[j]] = p[j];
            mobius[i * p[j]] = -mobius[i];
            if (i % p[j] == 0) {
                mobius[i * p[j]] = 0;
                break;
            }
        }
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    prime();
    int sum = 0, ans = 0;
    REPP(i, 2, N - 1) {
        sum += mobius[i];
        cout << i << ' ' << mobius[i] << ' ' << sum << endl;
        ans = max(ans, abs(sum));
    }
    return 0;
}


