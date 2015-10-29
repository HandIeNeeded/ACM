#include <bits/stdc++.h>

#define LL unsigned long long
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

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif
    prime();
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        LL sqr = 1, cnt = 1;
        int tmp = n;
        for (int i = 0; i < tot && p[i] * p[i] <= tmp; i++) {
            if (tmp % p[i] == 0) {
                int num = 0;
                LL now = 1, sum = 1;
                while (tmp % p[i] == 0) {
                    num++;
                    now *= p[i];
                    sum += now * now;
                    tmp /= p[i];
                }
                sqr *= sum;
                cnt *= num + 1;
            }
        }
        if (tmp > 1) {
            sqr *= (1 + 1ULL * tmp * tmp);
            cnt *= 2;
        }
        cnt *= n;
        printf("%llu\n", sqr - cnt);
    }

    return 0;
}


