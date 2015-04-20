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

struct point{
	long long a, b, c;
	point(int a = 0, int b = 0, int c = 0) :a(a), b(b), c(c) {}
	point operator - (const point &rhs) const {
		return point(a - rhs.a, b - rhs.b, c -rhs.c);
	}
}p[4];

long long sqr(int x) {return 1LL * x * x;}

point det(point a, point b) {
	point res;
	res.a = a.b * b.c - a.c * b.b;
	res.b = a.c * b.a - a.a * b.c;
	res.c = a.a * b.b - a.b * b.a;
	return res;
}

long long dot(point a, point b) {
	return a.a * b.a + a.b * b.b + a.c * b.c;
}

long long dis(point a, point b) {
	return sqr(a.a - b.a) + sqr(a.b - b.b) + sqr(a.c - b.c);
}

int main() {
	int t, ca = 1;
	scanf("%d", &t);
	while (t--) {
		REP(i, 4) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			p[i] = point(x, y, z);
		}
		vector<long long> d;
		REP(i, 4) {
			REPP(j, i + 1, 3) {
				d.push_back(dis(p[i], p[j]));
			}
		}
		sort(d.begin(), d.end());
		d.resize(unique(d.begin(), d.end()) - d.begin());
		int ans = 0;
		if (int(d.size()) == 2 && d[1] == d[0] * 2) {
			ans = 1;
		}
		else ans = 0;
		point dict = det(p[1] - p[0], p[2] - p[0]);
		if (dot(dict, p[3] - p[0])) ans = 0;
		printf("Case #%d: %s\n", ca++, ans ? "Yes" : "No");
	}
	return 0;
}

