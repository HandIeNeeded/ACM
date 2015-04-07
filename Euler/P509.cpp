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

const int N = 105;
const int MO = 1234567890;
long long M = 123456787654321;
int sg[N] = {0, 0}, vis[N];//sg = i's zeroes in the tail.
long long cnt[N];

int main() {
	ios :: sync_with_stdio(0);
	REPP(i, 2, 100) {
		MST(vis, 0);
		for (int j = 1; j < i; j++) {
			if (i % j == 0) {
				vis[sg[i - j]] = 1;
			}
		}
		int &ans = sg[i];
		ans = 0;
		while (vis[ans]) ans++;
	}
	REPP(i, 1, 100) {
		cout << i << ' ' << sg[i] << endl;
	}
	long long now = 1, sum = 0;
	REP(i, 60) {
		cnt[i] = M / now - M / (now << 1);
		now <<= 1;
		sum += cnt[i];
	}
	REP(i, 60) {
		cout << i << ' ' << cnt[i] << endl;
	}
	cout << sum << endl;
	REP(i, 60) cnt[i] %= MO;
	long long ans = 0;
	REPP(i, 0, 50) {
		REPP(j, 0, 50) {
			ans += cnt[i] * cnt[j] % MO * cnt[i ^ j] % MO;
			if (ans >= MO) ans -= MO;
		}
	}
	M %= MO;
	long long tot = M * M % MO * M % MO;
	cout << tot - ans << endl;

	return 0;
}

