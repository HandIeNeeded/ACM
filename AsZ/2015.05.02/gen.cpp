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

string str = "()";

int main() {
	ios :: sync_with_stdio(0);
	freopen("in", "w", stdout);
	int t = 20;
	cout << t << endl;
	REP(i, t) {
		int n = 2000, m = 2000;
		cout << n << ' ' << m << endl;
		REP(i, n) {
			cout << str[rand() & 1];
		}
		cout << endl;
		REP(i, m) {
			int x = rand() % 2 + 1;
			if (x == 1) {
				cout << 1 << ' ' << rand() % n + 1 << endl;
			}
			else {
				int l = rand() % n + 1, r = rand() % n + 1;
				int k = rand() % 10 + 1;
				if (l > r) swap(l, r);
				cout << 2 << ' ' << l << ' ' << r << ' ' << k << endl;
			}
		}
	}

	return 0;
}

