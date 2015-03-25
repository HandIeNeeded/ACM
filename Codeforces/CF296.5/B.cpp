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
pair<int, int> p[N];
int b[N];

int main() {
	ios :: sync_with_stdio(0);
	int n;
	cin >> n;
	REPP(i, 1, n) {
		cin >> p[i].first >> p[i].second;
	}
	int ans = 2e9;
	REPP(i, 1, 1000) {
		int cnt = 0, h = 0, w = 0, now = 0;
		REPP(j, 1, n) {
			if (p[j].second > i) {
				cnt++;
				h = max(h, p[j].first);
				w += p[j].second;
			}
			else {
				if (p[j].first > p[j].second && p[j].first <= i) {
					b[now++] = p[j].first - p[j].second;
				}
				w += p[j].first;
			}
		}
		if (h > i) continue;
		if (cnt <= n / 2) {
			int r = n / 2 - cnt;
			sort(b, b + now);
			r = min(now, r);
			for (int i = 0, j = now - 1; i < r; i++, j--) {
				w -= b[j];
			}
			ans = min(ans, i * w);
		}
	}
	cout << ans << endl;
	
	return 0;
}
