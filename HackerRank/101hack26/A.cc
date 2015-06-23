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

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

int cnt[26];

int main() {
    ios :: sync_with_stdio(0);
	string s;
	cin >> s;
	REP(i, s.size()) {
		cnt[s[i] - 'a']++;
	}
	int mx = 0, mi = 1e6;
	REP(i, 26) if (cnt[i]) {
		mi = min(mi, cnt[i]);
		mx = max(mx, cnt[i]);
	}
	if (mx == mi) {
		cout << "YES" << endl;
	}
	else {
		int tmp = 0;
		int now = 0;
		REP(i, 26) if (cnt[i] == mx) tmp++;
		REP(i, 26) if (cnt[i] == mi) now++;
		if (now == 1 && mi == 1) {
			int bad = 0;
			REP(i, 26) if (cnt[i] && cnt[i] != mx && cnt[i] != mi) {
				cout << "NO" << endl;
				bad = 1;
				break;
			}
			if (!bad) {
				cout << "YES" << endl;
			}
		}
		else {
			if (tmp > 1 || mx > mi + 1) {
				cout << "NO" << endl;
			}
			else {
				cout << "YES" << endl;
			}
		}
	}

    return 0;
}

