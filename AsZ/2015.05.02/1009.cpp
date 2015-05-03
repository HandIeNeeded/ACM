#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MAXN 3123456

using namespace std;
typedef int arrayN[MAXN];

int num;
arrayN fir, f, e, nxt, kind, slack, dfn, low, inS, belong;

int getfa(int x)
{
	return f[x] == x ? x : (f[x] = getfa(f[x]));
}

void link(int u, int v, int kin)
{
	e[++num] = v, nxt[num] = fir[u];
	fir[u] = num, kind[num] = kin;
}

int now, cnt, top;

void tarjan(int x)
{
	low[x] = dfn[x] = ++now;
	slack[++top] = x;
	for (int p = fir[x]; p; p = nxt[p])
		if (inS[e[p]] == 0)
			if (!dfn[e[p]])
			{
				tarjan(e[p]);
				low[x] = min(low[x], low[e[p]]);
			}
			else low[x] = min(low[x], dfn[e[p]]);
	if (low[x] == dfn[x])
	{
        belong[x] = ++cnt;
        inS[x] = 1;
        for (; low[slack[top]] != dfn[slack[top]]; --top)
        {
			belong[slack[top]] = cnt;
			inS[slack[top]] = 1;
		}
		--top;
	}
}

int random(int x)
{
	return abs(rand() * rand()) % x + 1;
}
int main() {
	ios :: sync_with_stdio(0);
	//freopen("1009.in", "r", stdin);
	//srand(time(0) % clock());
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca)
    {
		int N, M1, M2;
		now = 0;
		scanf("%d%d%d", &N, &M1, &M2);
		//cin >> N >> M1 >> M2;
       /* {
			N = 1000000;
			M1 = 0;
			M2 = 1000000;
		}*/
		num = 0;
		top = 0;
		cnt = 0;
		for (int i = 1; i <= N; ++i)
		{
			fir[i] = 0;
            f[i] = i;
            low[i] = dfn[i] = 0;
            inS[i] = 0;
            belong[i] = 0;
		}
		int ans = 0;
		for (int i = 1; i <= M1; ++i)
		{
            int u, v;
            scanf("%d%d", &u, &v);
		/*	{
				u = random(N);
				v = random(N);
                for (;v == u; v = random(N));
			}*/
            link(u, v, 0);
            link(v, u, 0);
			int fu = getfa(u);
			int fv = getfa(v);
			if (fu == fv) ans = 1;
			else f[fu] = fv;
		}
		for (int i = 1; i <= M2; ++i)
		{
			int u, v;
			//cin >> u >> v;
			scanf("%d%d", &u, &v);

		/*	{
				u = random(N);
				v = random(N);
                for (;v == u; v = random(N));
			}*/

            link(u, v, 1);
		}

        for (int i = 1; i <= N && !ans; ++i)
			if (!dfn[i]) tarjan(i);
		for (int i = 1; i <= N && !ans; ++i)
			for (int p = fir[i]; p && !ans; p = nxt[p])
				if (kind[p])
				{
                    if (belong[i] == belong[e[p]])
						ans = 1;
				}
		printf(ans ? "YES\n" : "NO\n");
    }
	return 0;
}

