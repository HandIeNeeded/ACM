#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

string str = "+-";

int go(string &s, int now) {
	int cnt = 0;
	REP(i, s.size()) {
		if (s[i] != str[now]) cnt++;
		now ^= 1;
	}
	return cnt;
}


int main() {
	ios :: sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		int ans = 1000000;
		ans = min(ans, go(str, 1));
		ans = min(ans, go(str, 0));
		cout << ans << endl;
	}

	return 0;
}
