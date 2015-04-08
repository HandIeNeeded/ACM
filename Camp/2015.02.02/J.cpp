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

const int N = 1005;
const int M = 1000000;
int mp[N][N], n;
pair<int, int> ans[N];
bool vis[N], settle[N];

pair<int, int> calc(pair<int, int> a, int common, bool dir) {
	pair<int, int> res;
	if (dir) {
		res.first = a.second - common;
		res.second = res.first + M;
	}
	else {
		res.second = a.first + common;
		res.first = res.second - M;
	}
	return res;
}

int getcommon(pair<int, int> a, pair<int, int> b) {
	if (a.second <= b.second) {
		return a.second - b.first;
	}
	else {
		return b.second - a.first;
	}
}

void dfs(int x, vector<int> &a) {
	a.push_back(x);
	REPP(i, 1, n) {
		if (mp[x][i] > 0 && !vis[i]) {
			dfs(i, a);
		}
	}
}

bool go(int y, int x, vector<int> &a) {
	bool ans = 0;
	for (auto z: a) {
		if (mp[x][z] > 0 && !settle[z]) {
			ans[z] = calc(ans[x], mp[x][z], 0);
			if (getcommon(ans[y], ans[z]) == mp[y][z]) {
				settle[z] = 1;
				return go(x, z, a);
			}
			else {
				settle[z] = 1;
			}
		}
	}

}

int main() {
	scanf("%d", &n);
	REPP(i, 1, n) {
		REPP(j, 1, n) {
			scanf("%d", &dp[i][j]);
		}
	}
	int bad = 0;
	REPP(i, 1, n) if (!vis[i]) {
		vector<int> candidate;
		dfs(i, candidate);
		if ((int) candidate.size() <= 2) {
			REP(i, candidate.size()) {
				settle[candidate[i]] = 1;
			}
		}
		else {
			ans[candidate[0]] = {0, 0};
			ans[candidate[1]] = calc(ans[candidate[0]], mp[candidate[0]][candidate[1]], 0);
			settle[candidate[0]] = settle[candidate[1]] = 1;
			if (go(candidate[0], candidate[1])) {
				continue;
			}
			else {
				ans[candidate[1]] = calc(ans[candidate[0]], mp[candidate[0]][candidate[1]], 1);
				if(go(candidate[0], candidate[1])) {
					continue;
				}
			}
			bad = 1;
		}
		if (bad) break;
	}
	cout << (bad ? "No" : "Yes") << endl;

	return 0;
}

