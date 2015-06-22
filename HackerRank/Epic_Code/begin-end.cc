#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

string s;
int cnt[26];

int main() {
    ios :: sync_with_stdio(0);
	int n;
	cin >> n >> s;
	REP(i, n) {
		cnt[s[i] - 'a']++;
	}
	LL ans = n;
	REP(i, 26) {
		ans += 1LL * cnt[i] * (cnt[i] - 1) >> 1;
	}
	cout << ans << endl;

    return 0;
}

