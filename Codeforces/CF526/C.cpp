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
	long long tot, a, b, ta, tb;
	cin >> tot >> a >> b >> ta >> tb;
	long long ans = 0;
	REPP(i, 0, 10000000) {
		if (i * ta > tot) break;
		int cnt = (tot - i * ta) / tb;
		ans = max(ans, i * a + cnt * b);
	}
	REPP(i, 0, 10000000) {
		if (i * tb > tot) break;
		int cnt = (tot - i * tb) / ta;
		ans = max(ans, i * b + cnt * a);
	}
	cout << ans << endl;

	return 0;
}

