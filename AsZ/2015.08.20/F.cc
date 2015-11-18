#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
const int MO = 258280327;
int cnt[N], cof[N], fac[N], ans[N];

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int main() {
#ifdef HOME
    freopen("F.in", "r", stdin);
#endif

    fac[0] = 1;
    REPP(i, 1, N - 1) fac[i] = 1LL * fac[i - 1] * i % MO;

    int n;
    while (scanf("%d", &n) > 0) {
        memset(ans, 0, sizeof(ans));
        memset(cnt, 0, sizeof(cnt));
        REPP(i, 1, n) {
            int x;
            scanf("%d", &x);
            cnt[x]++;
        }
        int A = 0, B = 0;
        REPP(i, 1, n) {
            cof[i] = 1LL * (n - i + 1) * fac[i] % MO * fac[n - i] % MO;
            add(cof[i], cof[i - 1]);
        }
        REPP(i, 1, n) {
            cout << cof[i] << ' ';
        }
        cout << endl;
        for (int i = 1; i < N; i++) {
            for (int j = i + i; j < N; j += i) {
                cnt[i] += cnt[j];
            }
        }
        REPP(i, 1, 10) {
            cout << cnt[i] << ' ';
        }
        cout << endl;
        for (int i = N - 1; i >= 1; i--) {
            ans[i] = cof[cnt[i]];
            cout << i << ' ' << ans[i] << endl;
            for (int j = i + i; j < N; j += i) {
                add(ans[i], MO - ans[j]);
            }
        }
        REPP(i, 1, 10) {
            cout << ans[i] << ' ';
        }
        cout << endl;
        REPP(i, 1, N - 1) add(A, 1LL * i * ans[i] % MO);
        printf("%d\n", A);
    }


    return 0;
}

