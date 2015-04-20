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

int main() {
	ios :: sync_with_stdio(0);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		int n;
		scanf("%d", &n);
		int ans = 1;
		for (int i = 1; i <= n; ++i)
		{
			int x;
			scanf("%d", &x);
			if (x % 3 != 0) ans = 0;
		}
		printf("Case #%d: ", t);
		if (ans) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

