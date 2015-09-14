#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

#define N 100100
#define MOD 880803841

using namespace std;

int cnt[N << 2], flag[N << 2];

int S[N];

inline int add(int x, int y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
	return x;
}

inline int mul(int x, int y)
{
	return (1LL * x * y) % MOD;
}

int vis[N];

int main() {
//ifdef HOME
   freopen("tmp.in", "r", stdin);
//#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, d;
        scanf("%d%d%d", &n, &m, &d);
        MST(S, 0);
        S[1] = 1;
        for (int k = 2; k <= n; k++)
            for (int i = k; i > 0; i--)
                S[i] = add(S[i - 1], mul(S[i], i));
        REPP(i, 1, m) vis[i] = 1;
        while (d--) {
            int x, y;
            scanf("%d%d", &x, &y);
            REPP(i, x, y) vis[i] ^= 1;
            int cnt = 0;
            REPP(i, 1, m) if (vis[i]) cnt++;
            printf("%d\n", S[cnt]);
        }
    }



    return 0;
}

