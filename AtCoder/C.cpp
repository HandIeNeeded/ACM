#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 1005;
pair<LL, LL> p[N];
map<pair<LL, LL>, int> mp;

int main() {
	ios :: sync_with_stdio(0);
	int n;
	cin >> n;
	REPP(i, 1, n) {
		LL x, y;
		cin >> x >> y;
		x <<= 1, y <<= 1;
		p[i] = make_pair(x, y);
		mp.insert(make_pair(p[i], i));
	}
	REPP(i, 1, n) {
		REPP(j, i + 1, n) {
			LL a = p[i].first, b = p[i].second, c = p[j].first, d = p[j].second;
			pair<LL, LL> A = make_pair((a + c + d - b) >> 1, (b + a + d - c) >> 1);
			pair<LL, LL> B = make_pair((a + b + c - d) >> 1, (c + b + d - a) >> 1);
			if (mp.count(A) && mp.count(B)) {
				cout << 4 << endl;
				int a[4];
				a[0] = mp[p[i]], a[1] = mp[p[j]], a[2] = mp[A], a[3] = mp[B];
				sort(a, a + 4);
				REP(i, 4) {
					cout << a[i] << endl;
				}
				return 0;
			}
		}
	}

	cout << 0 << endl;

	return 0;
}

