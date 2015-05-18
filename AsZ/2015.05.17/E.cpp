#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
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

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MAXN 512
#define MAXM 21234

using namespace std;
typedef int arrayN[MAXN], arrayM[MAXM];

arrayN col, fir, colNum;
arrayM e, nxt;
int num, n, m, vis[MAXN][4];
vector <int> vec;

void link(int u, int v)
{
    e[++num] = v;
    nxt[num] = fir[u];
    fir[u] = num;
}

int ans = 1;
char st[4] = "RGB";

void dye(int u, int color)
{
	col[u] = color;
	for (int p = fir[u]; p && ans; p = nxt[p])
    {
		int q = e[p];
		if (col[q])
		{
            if (col[q] == color) ans = 0;
            continue;
		}
		if (!vis[q][color])
		{
            vis[q][color] = 1;
            ++colNum[q];
            if (colNum[q] == 2)
            {
				for (int i = 1; i <= 3; ++i)
					if (vis[q][i] == 0)
                        col[q] = i;
                vec.push_back(q);
            } else if (colNum[q] >= 3) ans = 0;
		}
	}
}

int main() {
    ios :: sync_with_stdio(0);
	freopen("mayors.in", "r", stdin);
	freopen("mayors.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int u0, v0;
    for (int i = 1; i <= m; ++i)
    {
		int u, v;
		scanf("%d%d", &u, &v);
		link(u, v);
		link(v, u);
		if (i == 1)
		{
			u0 = u, v0 = v;
			col[u] = 1;
			col[v] = 2;
		}
    }
    if (m)
    {
		dye(u0, col[u0]);
		dye(v0, col[v0]);
	}
    for (; ans && !vec.empty(); )
    {
		int tmp = vec.back();
		vec.pop_back();
        dye(tmp, col[tmp]);
    }


	for (int i = 1; i <= n && ans; ++i)
		if (col[i] == 0)
		{
			for (int j = 1; j <= 3 && ans; ++j)
				if (vis[i][j] == 0)
				{
					col[i] = j;
					break;
				}
		}

    for (int i = 1; i <= n && ans; ++i)
		for (int p = fir[i]; p && ans; p = nxt[p])
			if (col[e[p]] == col[i])
                ans = 0;
	if (ans)
	{
		printf("Plan OK\n");
		for (int i = 1; i <= n; ++i)
			printf("%c", st[col[i] - 1]);
		printf("\n");
	} else printf("Plan failed\n");
    return 0;
}


