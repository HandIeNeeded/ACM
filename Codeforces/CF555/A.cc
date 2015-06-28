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

const int N = 1e5 + 5;
vector<int> a[N];
int tmp[N];

bool cmp(int i, int j) {
	return a[i][0] < a[j][0];
}

int main() {
    ios :: sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	if (m == 1) {
		cout << 0 << endl;
		return 0;
	}
	REP(i, m) {
		int cnt;
		cin >> cnt;
		REP(j, cnt) {
			int x;
			cin >> x;
			a[i].push_back(x);
		}
	}
	REP(i, m) tmp[i] = i;
	sort(tmp, tmp + m, cmp);
	int ans = 0;
	REPP(i, 1, m - 1) {
		ans += 2 * a[tmp[i]].size() - 1;
	}
	int pos = a[tmp[0]].end() - upper_bound(a[tmp[0]].begin(), a[tmp[0]].end(), a[tmp[1]][0]);
	ans += 2 * pos;
	cout << ans << endl;
    return 0;
}
