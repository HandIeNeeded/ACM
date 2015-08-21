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

void tarjan1(int x)
{
	low1[x] = dfn1[x] = ++now1;
	sta.push_back(x);
	for (int p = fir1[x]; p; p = nxt1[p])
		if (inS1[e1[p]] == 0)
			if (!dfn1[e1[p]])
			{
				tarjan1(e1[p]);
				low1[x] = min(low1[x], low1[e1[p]]);
			} else low1[x] = min(low1[x], dfn1[e1[p]]);
	if (low1[x] == dfn1[x])
	{
        tot1[x] = 0;
        for (;;)
        {
            int tmp = sta.back();
            sta.pop_back();
            belong1[tmp] = x;
			tot1[x]++;
			inS1[tmp] = 1;
            if (tmp == x) break;
        }
	}
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

void getDAG()
{
	sta.clear();
	now1 = 0;
	MST(dfn1, 0);
    MST(inS1, 0);
	REPP(i, 1, n)
		if (!dfn1[i])
            tarjan1(i);
}

void findWayPre()
{
	MST(pre, 0);
    REPP(i, 1, n)
        canTrue[i] = (belong1[i] == i && tot1[i] == 1);
	canTrue[s] = canTrue[t] = 0;
    sta.clear();
    MST(vis, 0);
    s = belong1[s];
    t = belong1[t];
    sta.push_back(s);
    vis[s] = 1;
    for (;!sta.empty();)
    {
        int tmp = sta.back();
        sta.pop_back();
        if (tmp == t) break;
        for (int p = fir1[tmp]; p; p = nxt1[p])
        {
			int q = belong1[e1[p]];
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
	{
		inPath[tmp] = 1;
		link2(tmp + n, tmp);
	}
	REPP(i, 1, n)
		for (int p = fir1[i]; p; p = nxt1[p])
		{
			int u = belong1[i];
			int v = belong1[e1[p]];
            if (pre[v] == u)
				link2(v, u + n);
			else
			{
                if (inPath[u]) u += n;
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
    REPP(i, 1, n)
		if (belong1[i] == i)
		{
			if (!dfn2[i]) tarjan2(i);
			if (inPath[i] && !dfn2[i + n]) tarjan2(i + n);
		}
    ans[0] = 0;
    REPP(i, 1, n)
		if (inPath[i] && canTrue[i] && (belong2[i] != belong2[i + n]) && i != s && i != t - n)
            ans[++ans[0]] = i;
	printf("%d\n", ans[0]);
    REPP(i, 1, ans[0])
		printf("%d%c", ans[i], " \n"[i == ans[0]]);
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("assassination1.in", "r", stdin);
	scanf("%d%d%d%d", &n, &m, &s, &t);
	num1 = 0;
	MST(fir1, 0);
	REP(i, m)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		link1(u, v);
	}


    getDAG();
    findWayPre();
    getNewG();
    findAns();

	return 0;
}
