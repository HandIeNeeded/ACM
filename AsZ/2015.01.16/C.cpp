#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define MAXN 212345

using namespace std;
int a[MAXN * 4], g[MAXN * 4], nxt[MAXN * 4], fir[MAXN * 4];
int n;

int main() {
	//ios :: sync_with_stdio(0);
	freopen("crossword.in", "r", stdin);
    scanf("%d", &n);
    MST(nxt, 0);
    MST(fir, 0);
    REPP(i, 1, n) scanf("%d", &a[i]);
    {
		int L = n + 10;
		int R = L - 1;
		int ptr = 2;
        g[++R] = a[1];
        fir[R] = a[1];
        for (;ptr <= n && a[ptr] > a[ptr - 1]; ++ptr)
		{
			g[++R] = a[ptr];
			fir[R] = a[ptr];
		}


		for (int i = ptr; i <= n; )
		{
            int j = i;
			int tL = L;
            for (;a[j] < g[L] && j <= n; ++j);
            for (int k = j - 1; k >= i; --k)
            {
				g[--L] = a[k];
				fir[L] = a[k];
			}
			if (j > n) break;
			{
				int l = tL, r = R;
				for (; l < r; )
				{
					int mid = (l + r  + 1) >> 1;
					if (a[j] - 1 >= g[mid]) l = mid;
					else r = mid - 1;
				}
				tL = l;
			}
			for (; j <= n && a[j] - 1 == g[tL] && tL <= R;)
            {
				nxt[g[tL]] = a[j];
				g[tL] = a[j];
                ++j, ++tL;
            }
            if (j > n) break;
            if (tL > R)
				for (;j <= n && a[j] > a[j - 1]; ++j)
				{
                    g[++R] = a[j];
                    fir[R] = a[j];
				}
            i = j;
		}

        int ans = 0, tans = 0;
        REPP(i, L, R)
        {
			int tmp = 0;
			for (int p = fir[i]; p; p = nxt[p])
				++tmp;
			if (tmp > ans)
			{
				ans = tmp;
				tans = i;
			}
        }
        printf("%d\n", ans);
        int flag = 1;
		for (int p = fir[tans]; p; p = nxt[p])
		{
			if (!flag)
			{
                printf(" ");
			} else flag = 0;
			printf("%d", p);
		}
		printf("\n");
    }
	return 0;
}
