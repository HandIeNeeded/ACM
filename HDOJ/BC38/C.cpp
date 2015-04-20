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

int bit(int x) {
	for (int i = 30; i >= 0; i--) {
		if (x & (1 << i)) return i;
	}
	return 0;
}

int get(int x, int l, int r) {

}

int go(int a, int b, int c, int d) {
	if (a >= c && b <= d) return 0;
	else if (a <= c && b >= d) {
		return max(go(a, c, c, d) + go(d, b, c, d));
	}
	else if (a >= c && a <= d) return go(d, b, c, a);
	else if (b <= d && b >= c) return go(a, c, b, d);

	if (a == b || c == d) {
		if (a == b) return get(a, c, d);
		else return get(c, a, b);
	}
	else {

	}
}

int main() {
	int t, ca = 1;
	scanf("%d", &t);
	while (t--) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int ans = go(a, b, c, d);
		printf("Case #%d: %d\n", ca++, ans);
	}
	return 0;
}

