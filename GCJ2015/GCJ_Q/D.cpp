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

char str[2][10] = {"RICHARD", "GABRIEL"};

int main() {
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	int t, ca = 1;
	scanf("%d", &t);
	while (t--) {
		int ans = 0;
		int x, r, c;
		scanf("%d%d%d", &x, &r, &c);
		if (x == 4) {
			if (r * c == 12 || r * c == 16) ans = 1;
			else ans = 0;
		}
		else if (x == 3) {
			if (r * c == 6 || r * c == 9 || r * c == 12) ans = 1;
			else ans = 0;
		}
		else if (x == 2) {
			if ((r * c) & 1) ans = 0;
			else ans = 1;
		}
		else ans = 1;
		printf("Case #%d: %s\n", ca++, str[ans]);
	}

	return 0;
}

