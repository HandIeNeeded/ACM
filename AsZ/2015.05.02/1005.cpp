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

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

bool f[2][210];

int main() {
	ios :: sync_with_stdio(0);

	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		vector<int> a;
		for (int i = 0; i < m; i++)
		{
			int x;
			scanf("%d", &x);
			a.push_back(x);
		}
		memset(f[0], 0, sizeof(f[0]));
		f[0][0] = 1;
		int now = 0, pre = 1;
		for (int k = 2; k <= n; k++)
		{
			pre = now, now ^= 1;
			memset(f[now], 0, sizeof(f[now]));
			for (int i = 0; i < m; i++)
			{
				int x = a[i] % k;
				for (int j = 0; j < k - 1; j++)
					if (f[pre][j])
						f[now][(j + x) % k] = 1;
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (f[now][i])
				cnt++;
		printf("%d\n", cnt);
		for (int i = 0; i < n; i++)
			if (f[now][i])
				printf("%d%c", i + 1, " \n"[cnt-- == 1]);
	}

	return 0;
}

