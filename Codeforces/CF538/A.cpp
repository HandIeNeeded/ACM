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
string s, r = "CODEFORCES";

int find(string a, string b) {
	REP(i, a.size()) if (i + b.size() <= a.size()) {
		int bad = 0;
		REP(j, b.size()) {
			if (a[i + j] != b[j]) {
				bad = 1;
				break;
			}
		}
		if (!bad) return i;
	}
	return -1;
}

int main() {
	ios :: sync_with_stdio(0);
	cin >> s;
	int good = 0;
	if (s.size() <= r.size()) {
		cout << "NO" << endl;
		return 0;
	}
	REPP(i, 0, r.size()) {
		string r1 = r.substr(0, i), r2 = r.substr(i);
		if (find(s, r1) == 0 && s.substr(s.size() - r2.size()) == r2) {
			good = 1;
			break;
		}
	}
	cout << (good ? "YES" : "NO") << endl;

	return 0;
}

