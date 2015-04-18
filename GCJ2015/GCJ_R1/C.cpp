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

const int N = 20;
const int EPS = 0;

struct point{
	int x, y, id;
	point (int x = 0, int y = 0, int id = 0) :x(x), y(y), id(id) {}

	point operator - (const point &a) const {
		point res;
		res.x = x - a.x, res.y = y - a.y;
		return res;
	}
}p[N];

long long det(const point &a, const point &b) {
	return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

bool cmp(const point &a, const point &b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

vector<point> Convex_Hull(vector<point> vertex) {
    sort(vertex.begin(), vertex.end(), cmp);
    int n = vertex.size(), m;
    vector<point> C;
    for (int i = 0; i < n; i++) {
        while ((m = C.size()) > 1 && det(C[m - 1] - C[m - 2], vertex[i] - C[m - 2]) < EPS) C.pop_back();
        C.push_back(vertex[i]);
    }
    int k = C.size();
    for (int i = n - 2; i >= 0; i--) {
        while ((m = C.size()) > k && det(C[m - 1] - C[m - 2], vertex[i] - C[m - 2]) < EPS) C.pop_back();
        C.push_back(vertex[i]);
    }
    if (n > 1) C.pop_back();
    return C;
}

int ans[N];

int main() {
	ios :: sync_with_stdio(0);
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int t, ca = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		REP(i, n) {
			int x, y;
			cin >> x >> y;
			p[i] = {x, y, i};
		}
		REP(i, n) ans[i] = n;
		REP(i, 1 << n) {
			vector<point> tmp;
			int tot = 0;
			REP(j, n) {
				if (i & (1 << j)) {
					tmp.push_back(p[j]);
					tot++;
				}
			}
			tmp = Convex_Hull(tmp);
			REP(k, tmp.size()) {
				int x = tmp[k].id;
				ans[x] = min(ans[x], n - tot);
			}
		}
		cout << "Case #" << ca++ << ":" << endl;
		REP(i, n) {
			cout << ans[i] << endl;
		}
	}

	return 0;
}

