#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define MAXN 612345

using namespace std;
typedef int arrayN[MAXN];

int N, A, B, num;
arrayN fir, fa, e, nxt, sta, d1, fd, d2, ans;
vector<int> g[MAXN];

void link(int u, int v)
{
	e[++num] = v;
	nxt[num] = fir[u];
	fir[u] = num;
}

void bfs(int s)
{
	int l = 1, r = 1;
	sta[l] = s;
	for (; l <= r; ++l)
	{
		int u = sta[l];
		for (int p = fir[u]; p; p = nxt[p])
			if (e[p] != fa[u])
			{
				int v = e[p];
				fa[v] = u;
				sta[++r] = v;
			}
	}
}

void getMaxD()
{
    for (int i = N; i >= 1; --i)
    {
		int u = sta[i];
		d1[u] = d2[u] = -1;
		int lab = -1;
		for (int p = fir[u]; p; p = nxt[p])
            if (e[p] != fa[u] && d1[e[p]] + 1 > d1[u])
            {
				d1[u] = d1[e[p]] + 1;
				lab = e[p];
			}
		if (d1[u] == -1) d1[u] = 0;
		for (int p = fir[u]; p; p = nxt[p])
			if (e[p] != fa[u] && e[p] != lab && d1[e[p]] + 1 > d2[u])
				d2[u] = d1[e[p]] + 1;
    }
}

void getMaxFd()
{
    fd[1] = 0;
	REPP(i, 2, N)
	{
        int u = sta[i];
        int fath = fa[u];
        fd[u] = fd[fath] + 1;
        int t1 = d1[fath];
        int t2 = d2[fath];
        if (t1 == d1[u] + 1)
			fd[u] = max(fd[u], t2 + 1);
		else fd[u] = max(fd[u], t1 + 1);
	}
}

void getVec()
{
	MST(ans, 0);
    REPP(i, 1, N)
    {
        for (int p = fir[i]; p; p = nxt[p])
			if (e[p] != fa[i])
                g[i].push_back(d1[e[p]] + 1);
		if (i != 1)
		{
            g[i].push_back(fd[i]);
		}
		sort(g[i].begin(), g[i].end());
        REP(j, g[i].size())
			ans[g[i][j]] = max(ans[g[i][j]], (int)g[i].size() - j);
    }
    for (int i = N - 1; i >= 1; --i)
		ans[i] = max(ans[i + 1], ans[i]);
}

int main() {
	//ios :: sync_with_stdio(0);
	freopen("amoeba.in", "r", stdin);
	freopen("amoeba.out", "w", stdout);
	scanf("%d%d%d", &N, &A, &B);
	num = 0;
	MST(fir, 0);
	REPP(i, 1, N - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		link(u, v);
		link(v, u);
	}
	bfs(1);
	getMaxD();
	getMaxFd();
	getVec();
	//REPP(i, 1, N) printf("%d: %d %d %d\n", i, d1[i], d2[i], fd[i]);
    REPP(i, A, B)
		printf("%d\n", ans[i]);
	return 0;
}
