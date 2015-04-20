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

const int N = 2e5 + 5;

struct point{
	int a, b, id;
	point(int a = 0, int b = 0, int c = 0) :a(a), b(b), id(c) {}
}p[N], q[N];

bool operator < (const point &a, const point &b) {
	return a.a > b.a || (a.a == b.a && a.b > b.b);
}

bool operator == (const point &a, const point &b) {
	return a.a == b.a && a.b == b.b;
}

bool cmp(const point &a, const point &b, const point &c) {
	return 1LL * a.a * c.b * (b.b - a.b) * (c.a - b.a) <=
		   1LL * c.a * a.b * (c.b - b.b) * (b.a - a.a);
}

vector<int> id[N];

int main() {
	ios :: sync_with_stdio(0);
	//freopen("C.in", "r", stdin);
	int n;
	cin >> n;
	REPP(i, 1, n) {
		int x, y;
		cin >> x >> y;
		p[i] = {x, y, i};
	}
	sort(p + 1, p + n + 1);
	REPP(i, 1, n) q[i] = p[i];
	int tot = unique(p + 1, p + n + 1) - p - 1;
	REPP(i, 1, tot) p[i].id = i;
	int j = 1;
	REPP(i, 1, n) {
		if (q[i] == p[j]) {
			id[j].push_back(q[i].id);
		}
		else {
			if (j < tot && p[j] < q[i]) {
				j++, i--;
			}
		}
	}
	vector<point> q;
	int now = 1;
	while (now <= tot) {
		if (q.size() == 0) {
			q.push_back(p[now++]);
		}
		else if (q.size() == 1) {
			if(p[now].a == q[0].a) {
				now++;
			}
			else {
				if (p[now].b > q[0].b) {
					q.push_back(p[now]);
				}
				now++;
			}
		}
		else {
			point c = p[now], b = q.back(), a = q[q.size() - 2];
			if (c.a == b.a) {
				now++;
			}
			else if (c.b > b.b) {
				while (q.size() >= 2 && !cmp(a, b, c)) {
					q.pop_back();
					b = q.back(), a = q[q.size() - 2];
				}
				q.push_back(c);
				now++;
			}
			else {
				now++;
			}
		}
	}
	vector<int> ans;
	REP(i, q.size()) {
		for (int z: id[q[i].id]) {
			ans.push_back(z);
		}
	}
	sort(ans.begin(), ans.end());
	for (int x: ans) {
		cout << x << ' ';
	}
	cout << endl;

	return 0;
}
