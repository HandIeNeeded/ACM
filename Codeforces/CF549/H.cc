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

int a, b, c, d;

bool check(double x) {
	double A = -1e300, B = 1e300, C = -1e300, D = 1e300;
	for (int i = -1; i < 2; i += 2) {
		for (int j = -1; j < 2; j += 2) {
			A = max(1.0 * (a + i * x) * (d + j * x), A);
			B = min(1.0 * (a + i * x) * (d + j * x), B);
			C = max(1.0 * (c + i * x) * (b + j * x), C);
			D = min(1.0 * (c + i * x) * (b + j * x), D);
		}
	}
	if (B <= C && A >= D) return 1;
	return 0;
}

int main() {
    ios :: sync_with_stdio(0);
	cin >> a >> b >> c >> d;
	double lo = 0, hi = 1e100;
	int cnt = 0;
	while (cnt < 10000) {
		double mid = (hi + lo) / 2.0;
		if (check(mid)) hi = mid;
		else lo = mid;
		cnt++;
	}
	cout << fixed << setprecision(10) << hi << endl;

    return 0;
}

