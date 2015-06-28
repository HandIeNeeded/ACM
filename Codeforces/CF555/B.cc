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

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2e5 + 5;
LL L[N], R[N];
pair<LL, int> a[N];
pair<LL, LL> p[N];

struct Line{
	LL x, type, id;
}l[N << 1];

bool cmp(Line a, Line b) {
	return a.x < b.x || (a.x == b.x && a.type < b.type);
}

int ans[N];

int main() {
    ios :: sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	REPP(i, 1, n) {
		cin >> L[i] >> R[i];
	}
	int tot = 1;
	REPP(i, 1, n - 1) {
		l[tot++] = {L[i + 1] - R[i], 1, i};
		l[tot++] = {R[i + 1] - L[i], -1, i};
		p[i] = {L[i + 1] - R[i], R[i + 1] - L[i]};
	}
	n--;
	REPP(i, 1, m) {
		LL x;
		cin >> x;
		a[i] = {x, i};
	}
	sort(a + 1, a + m + 1);
	sort(l + 1, l + 2 * n + 1, cmp);
	if (m < n) {
		cout << "No" << endl;
	}
	else {
		set<pair<LL, int> > candidate;
		int start = 1;
		bool bad = 0;
		REPP(i, 1, 2 * n) {
			int id = l[i].id;
			while (start <= m && a[start].first <= l[i].x) {
				candidate.insert(a[start++]);
			}
			if (l[i].type == -1) {
				auto it = candidate.lower_bound({p[id].first, -1});
				if (it == candidate.end()) {
					bad = 1;
					break;
				}
				else {
					ans[id] = it->second;
					candidate.erase(it);
				}
			}
		}
		if (bad) {
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << endl;
			REPP(i, 1, n) cout << ans[i] << " \n"[i == n];
		}
	}

    return 0;
}
