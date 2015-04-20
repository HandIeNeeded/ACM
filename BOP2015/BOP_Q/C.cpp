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
#define LL long long

using namespace std;

const int N = 1005;

struct point{
	int x, y;
}p[N], q[N];

inline LL sqr(int x) {return 1LL * x * x;}

int ansx, ansy;
int tmp[N], n, a, b;

LL getdis(int x) {
	LL ans = 0;
	REPP(i, 1, n) ans += sqr(tmp[i] - x);
	return ans;
}

int calc() {
	int ans = 1 << 30;
	REPP(i, 1, b) {
		ans = min(ans, abs(ansx - q[i].x) + abs(ansy - q[i].y));
	}
	return ans;
}

pair<int, int> px, py;

void range(int ty) {
	if (ty == 0) {
		int &l = px.first, &r = px.second;
		int lo = 0, hi = ansx;
		LL sum = getdis(ansx);
		while (lo + 1 < hi) {
			int mid = (hi + lo) >> 1;
			if (getdis(mid) > sum) lo = mid;
			else hi = mid;
		}
		l = hi;
		lo = ansx, hi = 1e7 + 5;
		while (lo + 1 < hi) {
			int mid = (hi + lo) >> 1;
			if (getdis(mid) > sum) hi = mid;
			else lo = mid;
		}
		r = lo;
	}
	else {
		int &l = py.first, &r = py.second;
		int lo = 0, hi = ansy;
		LL sum = getdis(ansy);
		while (lo + 1 < hi) {
			int mid = (hi + lo) >> 1;
			if (getdis(mid) > sum) lo = mid;
			else hi = mid;
		}
		l = hi;
		lo = ansy, hi = 1e7 + 5;
		while (lo + 1 < hi) {
			int mid = (hi + lo) >> 1;
			if (getdis(mid) > sum) hi = mid;
			else lo = mid;
		}
		r = lo;
	}
}

void get(int ty, int a) {
	n = a;
	if (ty == 0) {
		REPP(i, 1, n) {
			tmp[i] = p[i].x;
		}
	}
	else {
		REPP(i, 1, n) {
			tmp[i] = p[i].y;
		}
	}
	int hi = 1e7 + 5, lo = 0;
	while (lo + 5 < hi) {
		int mid1 = (2 * lo + hi) / 3, mid2 = (lo + 2 * hi) / 3;
		if (getdis(mid1) > getdis(mid2)) lo = mid1;
		else hi = mid2;
	}
	LL mx = 1LL << 60, id = -1;
	REPP(i, lo, hi) {
		LL sum = getdis(i);
		if (sum < mx) {
			mx = sum;
			id = i;
		}
	}
	ty ? ansy = id : ansx = id;
	range(ty);
}

int main() {
	//freopen("C.in", "r", stdin);
	int t, ca = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d%d%d", &n, &m, &a, &b);
		REPP(i, 1, a) {
			int x, y;
			scanf("%d%d", &x, &y);
			p[i] = {x, y};
		}
		REPP(i, 1, b) {
			int x, y;
			scanf("%d%d", &x, &y);
			q[i] = {x, y};
		}
		get(0, a), get(1, a);
		LL ans = 0;
		REPP(i, 1, a) {
			ans += sqr(ansx - p[i].x) + sqr(ansy - p[i].y);
		}
		int ans1 = 1 << 30;
		REPP(i, 1, b) {
			int sum = 0;
			int tmp = 1 << 30;
			if (q[i].x >= px.first && q[i].x <= px.second) tmp = 0;
			else tmp = min(abs(q[i].x - px.first), abs(q[i].x - px.second));
			sum += tmp;
			tmp = 1 << 30;
			if (q[i].y >= py.first && q[i].y <= py.second) tmp = 0;
			else tmp = min(abs(q[i].y - py.first), abs(q[i].y - py.second));
			sum += tmp;
			ans1 = min(ans1, sum);
		}
		ans += ans1;
		printf("Case #%d: %lld\n", ca++, ans);
	}

	return 0;
}

