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

const int N = 2005;
int a[N][N], vis[N];

int main() {
	int t;
	scanf("%d", &t);
	int flag = 0;
	while (t--) {
		if (flag++) puts("");
		int n;
		scanf("%d", &n);
		REPP(i, 1, n) vis[i] = 0;
		REPP(i, 1, n) {
			REPP(j, 1, n) {
				scanf("%d", &a[i][j]);
			}
		}
		vector<pair<int, int> > ans;
		vis[1] = 1;
		REPP(i, 2, n) {
			int x = a[1][i];
			REPP(j, 1, n) {
				if (vis[a[x][j]]) {
					ans.push_back({x, a[x][j]});
					vis[x] = 1;
					break;
				}
			}
		}
		for (auto now: ans) {
			printf("%d %d\n", now.first, now.second);
		}
	}


	return 0;
}

