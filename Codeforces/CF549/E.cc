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

using namespace std;

const int N = 2e5 + 5;
pair<int, int> p[N];
int a[N];

int main() {
    ios :: sync_with_stdio(0);
	int n;
	cin >> n;
	REPP(i, 1, n) {
		cin >> a[i];
		p[i] = {a[i], i};
	}
	sort(p + 1, p + n + 1);
	REPP(i, 1, n) {
		int d = i - p[i].second;
		p[i].first += d;
	}
	REPP(i, 1, n) a[i] = p[i].first;
	int bad = 0;
	REPP(i, 1, n) {
		if (a[i] < 0 || (i < n && a[i] > a[i + 1])) {
			bad = 1;
		}
	}
	if (bad) {
		cout << ":(" << endl;
	}
	else {
		REPP(i, 1, n) {
			cout << a[i] << ' ';
		}
	}

    return 0;
}

