#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define MAXN 212345
#define MAXM 612345

using namespace std;
typedef int arrayN[MAXN], arrayM[MAXM];

int n, m, s, now1, now2, t, num1, num2;
arrayN fir1, fir2, pre, canTrue, vis, inPath, low1, low2, dfn1, dfn2, inS1, inS2, tot1, belong1, belong2, ans;
arrayM nxt1, nxt2, e1, e2;
vector <int> sta;

void link1(int u, int v)
{
	e1[++num1] = v, nxt1[num1] = fir1[u];
	fir1[u] = num1;
}

void tarjan2(int x)
{
	low2[x] = dfn2[x] = ++now2;
	sta.push_back(x);
	for (int p = fir2[x]; p; p = nxt2[p])
		if (inS2[e2[p]] == 0)
			if (!dfn2[e2[p]])
			{
				tarjan2(e2[p]);
				low2[x] = min(low2[x], low2[e2[p]]);
			} else low2[x] = min(low2[x], dfn2[e2[p]]);
	if (low2[x] == dfn2[x])
	{
        for (;;)
        {
            int tmp = sta.back();
            sta.pop_back();
            belong2[tmp] = x;
			inS2[tmp] = 1;
            if (tmp == x) break;
        }
	}
}

void findWayPre()
{
	MST(pre, 0);
    sta.clear();
    MST(vis, 0);
    s = s, t = t + n;
    sta.push_back(s);
    vis[s] = 1;
    for (;!sta.empty();)
    {
        int tmp = sta.back();
        sta.pop_back();
        if (tmp == t) break;
        for (int p = fir1[tmp]; p; p = nxt1[p])
        {
			int q = e1[p];
			if (!vis[q])
			{
				vis[q] = 1;
				sta.push_back(q);
				pre[q] = tmp;
			}
		}
    }
}

void link2(int u, int v)
{
	e2[++num2] = v, nxt2[num2] = fir2[u];
	fir2[u] = num2;
}

void getNewG()
{
	num2 = 0;
	MST(fir2, 0);
	MST(inPath, 0);
    for (int tmp = pre[t]; tmp != s; tmp = pre[tmp])
		inPath[tmp] = 1;
	REPP(i, 1, n * 2)
		for (int p = fir1[i]; p; p = nxt1[p])
		{
			int u = i;
			int v = e1[p];
            if (pre[v] == u && inPath[u] && inPath[v])
				link2(v, u);
			else
			{
				link2(u, v);
			}
		}
}

void findAns()
{
    MST(inS2, 0);
    MST(dfn2, 0);
    sta.clear();
    now2 = 0;
    REPP(i, 1, n * 2)
	{
			if (!dfn2[i]) tarjan2(i);
	}

	/*REPP(i, 1, n * 2)
		for (int p = fir2[i]; p; p = nxt2[p])
			printf("%d ---> %d\n", i, e2[p]);
*/
    ans[0] = 0;
    REPP(i, 1, n)
		if (inPath[i] && (belong2[i] != belong2[i + n]) && i != s && i != t - n)
            ans[++ans[0]] = i;
	printf("%d\n", ans[0]);
    REPP(i, 1, ans[0])
		printf("%d%c", ans[i], " \n"[i == ans[0]]);
}

int main() {
	//ios :: sync_with_stdio(0);
	freopen("assassination.in", "r", stdin);
	scanf("%d%d%d%d", &n, &m, &s, &t);
	num1 = 0;
	MST(fir1, 0);
    REPP(i, 1, n)
		link1(i, i + n);
	REP(i, m)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		link1(u + n, v);
	}


   // getDAG();
    findWayPre();
    getNewG();
    findAns();

	return 0;
}
