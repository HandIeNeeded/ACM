#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define MAXN 512

using namespace std;

int a[MAXN][MAXN], row[MAXN][MAXN], col[MAXN][MAXN], b[MAXN];

int abs(int x)
{return x < 0 ? -x : x;}
long long calc(int n)
{
    int sum = 0;
	REPP(i, 1, n)
		sum += b[i];
    sum /= 2;
    int tmp = 0;
    long long tmpAns = 0;

    REPP(i, 1, n)
    {
		tmp += b[i];
		if (tmp >= sum)
		{
			tmp = i;
			break;
		}
	}
	REPP(i, 1, n)
		tmpAns += 1LL * abs(i - tmp) * b[i];
	return tmpAns;
}

int main() {
	//freopen("B.in", "r", stdin);
	int task;
	scanf("%d", &task);
	REPP(t, 1, task)
	{
		int r, c, q;
		printf("Test Case %d:\n", t);
		scanf("%d%d%d", &r, &c, &q);
		REPP(i, 1, r)
			REPP(j, 1, c)
				scanf("%d", &a[i][j]);
		REPP(i, 1, r)
		{
			row[i][0] = 0;
			REPP(j, 1, c)
				row[i][j] = row[i][j - 1] + a[i][j];
		}
		REPP(i, 1, c)
		{
			col[i][0] = 0;
			REPP(j, 1, r)
				col[i][j] = col[i][j - 1] + a[j][i];
		}
		REPP(i, 1, q)
		{
			int r1, c1, r2, c2;
			scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
			if (r1 > r2) swap(r1, r2);
			if (c1 > c2) swap(c1, c2);
            REPP(j, r1, r2)
				b[j - r1 + 1] = row[j][c2] - row[j][c1 - 1];
			long long ans = calc(r2 - r1 + 1);

			REPP(j, c1, c2)
				b[j - c1 + 1] = col[j][r2] - col[j][r1 - 1];
			ans += calc(c2 - c1 + 1);


            printf("%d %lld\n", i, ans);
		}
		printf("\n");
	}


	return 0;
}

