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

const int N = 1e7 + 5;
int cnt[N], num[N];
int n, k, s, a, b, m;

void add(int &x, int y) {
	x += y;
	if (x >= m) x -= m;
}

void gen(int n) {
	num[0] = s;
	REPP(i, 1, n - 1) {
		num[i] = 1LL * a * num[i - 1] % m;
		add(num[i], b);
	}
}

int main() {
	ios :: sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k >> s >> a >> b >> m;
		REP(i, m) cnt[i] = 0;
		gen(n);
		REP(i, n) cnt[num[i]]++;
		int now = 0;
		while(k) {
			int kk = min(k, cnt[now]);
			REP(j, kk) {
				k--;
				cout << now << " \n"[k == 0];
			}
			now++;
		}
	}

	return 0;
}

