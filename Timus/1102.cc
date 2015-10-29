#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

string s[6] = {"one", "out", "output", "in", "input", "puton"};

int main() {
	ios :: sync_with_stdio(0);
	string str;
	int n;
	cin >> n;
	REPP(i, 1, n) {
		cin >> str;
		vector<bool> tmp(0, str.size() + 1);
		tmp[0] = 1;
		REP(i, str.size()) {
			REP(j, 6) {
				int start = i - s[j].size() + 1;
				if (start < 0) continue;
				if (str.substr(start, s[j].size()) == s[j]) {
					tmp[i + 1] = tmp[i + 1] | tmp[start];
				}
			}
		}
		if (!tmp[str.size()]) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
	return 0;
}

