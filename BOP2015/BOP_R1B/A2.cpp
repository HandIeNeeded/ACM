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

string s[10];

bool good(int n) {
	REP(i, n - 1) if (s[i][0] == s[i + 1][0]) return 0;
	return 1;
}

int main() {
	ios :: sync_with_stdio(0);
	int t, ca = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		REP(i, n) cin >> s[i];
		sort(s, s + n);
		int ans = 0;
		do {
			if (good(n)) ans++;
		}while (next_permutation(s, s + n));
		cout << "Case #" << ca++ << ": " << ans << endl;
	}

	return 0;
}

