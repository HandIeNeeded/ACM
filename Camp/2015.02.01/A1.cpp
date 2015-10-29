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
#define LL unsigned long long

using namespace std;

const LL MO = 1LL << 32;
const LL step = 1LL << 19;

LL mp[1 << 14];

int main() {
	ios :: sync_with_stdio(0);
	freopen("out", "w", stdout);
	LL ans = 1, now = 0, cnt = 0;
	mp[0] = 1;
	for (LL i = 1; i < MO; i += 2) {
		ans = ans * i % MO;
		cnt++;
		if (cnt == step >> 1) {
			mp[now++] = ans;
			cnt = 0;
		}
	}
	REP(i, now) {
		cout << mp[i] << ',' << " \n"[i % 16 == 15];
	}

	return 0;
}

