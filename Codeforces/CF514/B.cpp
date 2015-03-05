#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1005;
int f[N];

struct point{
	int x, y;

	point operator - (const point &a) const {
		return {x - a.x, y - a.y};
	}
}a[N];

int det(point a, point b) {
	return a.x * b.y - a.y * b.x;
}

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

int main() {
	ios :: sync_with_stdio(0);
	int n;
	cin >> n;
	point start;
	cin >> start.x >> start.y;
	REPP(i, 1, n) {
		cin >> a[i].x >> a[i].y;
		a[i] = a[i] - start;
	}
	REPP(i, 1, n) f[i] = i;
	REPP(i, 1, n) {
		REPP(j, i + 1, n) {
			if (det(a[i], a[j]) == 0) {
				f[find(i)] = find(j);
			}
		}
	}
	int cnt = 0;
	REPP(i, 1, n) if (f[i] == i) cnt++;
	cout << cnt << endl;

	return 0;
}


