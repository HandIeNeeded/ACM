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

const int N = 2e5 + 5;
int val[N], ans[N];
int cnt[N], n;

void bfs(int size) {
	queue<int> q;
	q.push(1);
	int now = 2;
	while (q.size()) {
		if (now > n) break;
		int x = q.front(); q.pop();
		REP(i, size) {
			if (val[now] < val[x]) {
				ans[size]++;
			}
			if (now <= n) q.push(now++);
			if (now > n) break;
		}
	}
}

int main() {
	ios :: sync_with_stdio(0);
	cin >> n;
	REPP(i, 1, n) cin >> val[i];
	int K = int(sqrt(n)) + 1;
	REPP(i, 1, K) bfs(i);
	REPP(i, 1, K) {
		REPP(j, 1, n) {
			cnt[j] = cnt[j - 1] + (val[j] < val[i]);
		}
		if (i == 1) {
			REPP(j, K + 1, n - 1) ans[j] += cnt[j + 1] - cnt[1];
		}
		else {
			REPP(j, K + 1, n - 1) {
				if ((j + 1) + (i - 2) * j < n) {
					int up = min(j + 1 + (i - 1) * j, n);
					ans[j] += cnt[up] - cnt[(j + 1) + (i - 2) * j];
				}
				else break;
			}
		}
	}
	REPP(i, 1, n - 1) {
		cout << ans[i] << endl;
	}
	return 0;
}

