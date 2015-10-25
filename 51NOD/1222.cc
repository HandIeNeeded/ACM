#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e6 + 5;

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

int lcm(int a, int b) {
    return a * b / __gcd(a, b);
}
int cnt[N];

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif


    prime();
    REPP(i, 1, 40) {
        REPP(j, 1, 40) {
            cnt[lcm(i, j)]++;
        }
    }
    REPP(i, 1, 40) {
        cout << i << ' ' << cnt[i] << endl;
    }


    return 0;
}


