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

const int N = 1e5 + 5;
int a[N], ty[N], sa, sb;
char s[2];

void add(pair<int, int> &a, int x, int b) {
	if (b) a.second += x;
	else a.first += x;
}

int main() {
	freopen("I.in", "r", stdin);
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int pre = -1, tot = 0, now = 0;
		sa = sb = 0;
		REPP(i, 1, n) {
			int x;
			scanf("%d%s", &x, s);
			if (s[0] == 'B') now = 0;
			else now = 1;
			if (now != pre) {
				a[++tot] = x;
				ty[tot] = now;
				pre = now;
			}
			else {
				a[tot] += x;
			}
		}
		n = tot;
		REPP(i, 1, n) {
			if (ty[i]) sb += a[i];
			else sa += a[i];
		}
		//cout << sa << ' ' << sb << endl;
		//REPP(i, 1, n) {
		//	cout << a[i] << ' ' << ty[i] << endl;
		//}
		if (sa == 0 || sb == 0) {
			printf("%d\n", max(sa, sb));
			continue;
		}
		pair<int, int > tmp;
		tmp = {0, 0};
		int ans = 0;
		REPP(i, 1, n) {
			if (tmp == pair<int, int> {0, 0}) {
				if (ty[i]) tmp.second += a[i];
				else tmp.first += a[i];
				continue;
			}
			int x = tmp.first, y = tmp.second;
			if (ty[i] == 0) {
				if (1LL * sa * y % sb == 0) {
					int need = 1LL * sa * y / sb - x;
					if (a[i] >= need && need >= 0) {
						ans++;
						tmp = {0, 0};
						add(tmp, a[i] - need, ty[i]);
					}
					else {
						add(tmp, a[i], ty[i]);
					}
				}
				else {
					add(tmp, a[i], ty[i]);
				}
			}
			else {
				if (1LL * sb * x % sa == 0) {
					int need = 1LL * sb * x / sa - y;
					if (a[i] >= need && need >= 0) {
						ans++;
						tmp = {0, 0};
						add(tmp, a[i] - need, ty[i]);
					}
					else {
						add(tmp, a[i], ty[i]);
					}
				}
				else {
					add(tmp, a[i], ty[i]);
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
