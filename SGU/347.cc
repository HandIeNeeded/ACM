#include <bits/stdc++.h>

#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 105;

string s[N];

bool cmp(string a, string b) {
	return a + b < b + a;
}

int main() {
    ios :: sync_with_stdio(0);
	int n;
	cin >> n;
	REP(i, n) cin >> s[i];
	sort(s, s + n, cmp);
	string ans;
	REP(i, n) ans += s[i];
	cout << ans << endl;

    return 0;
}

