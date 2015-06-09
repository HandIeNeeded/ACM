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

using namespace std;

const int oo = MAXN * 5;

typedef int arrayN[MAXN];

arrayN rowNeed, colNeed, d, lastCol;
int m, n, h;
char ans[MAXN][MAXN];

int com(int u, int v)
{
	return colNeed[u] > colNeed[v];
}

int main() {
    ios :: sync_with_stdio(0);
	freopen("chip.in", "r", stdin);
	freopen("chip.out", "w", stdout);
	cin >> m >> n >> h;
	for (int i = 0; i < m; ++i)
	{
		int x;
		cin >> x;
		rowNeed[i] = n - x;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> colNeed[i];
        lastCol[i] = -1;
	}
    for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			ans[i][j] = '*';
	int flag = 1;
    for (int i = 0; i < m && flag; ++i)
		if (rowNeed[i] > 0)
		{
			int tot = 0;
            for (int j = 0; j < n && flag; ++j)
                if (lastCol[j] < i && colNeed[j] && i + h - 1 < m)
                    d[++tot] = j;
            if (tot < rowNeed[i]) flag = 0;
			sort(d + 1, d + tot + 1, com);
			tot = rowNeed[i];
			for (int h1 = 1; h1 <= tot; ++h1)
			{
				int j = d[h1];
                ans[i][j] = '+';
                ans[i + h - 1][j] = '+';
                for (int k = i + 1; k < i + h - 1; ++k)
					ans[k][j] = '|';
				for (int k = i; k <= i + h - 1; ++k)
                    rowNeed[k]--;
				colNeed[j]--;
				lastCol[j] = i + h - 1;
			}
		} else if (rowNeed[i] < 0) flag = 0;
	for (int i = 0; i < m; ++i)
		if (rowNeed[i]) flag = 0;
	for (int i = 0; i < n; ++i)
		if (colNeed[i]) flag = 0;
	if (flag)
	{
        for (int i = 0; i < m; ++i)
        {
			for (int j = 0; j < n; ++j)
				cout << ans[i][j];
			cout << endl;
		}
	} else cout << "inconsistent" << endl;
    return 0;
}
