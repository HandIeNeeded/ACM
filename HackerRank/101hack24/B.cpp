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

const int N = 5005;
vector<int> num;
int cnt[N][N], a[N];

int main() {
	ios :: sync_with_stdio(0);
	int n;
	cin >> n;
	REPP(i, 1, n) cin >> a[i], num.push_back(a[i]);
	sort(num.begin(), num.end());
	num.resize(unique(num.begin(), num.end()) - num.begin());
	int tot = num.size();
	REPP(i, 1, n) a[i] = lower_bound(num.begin(), num.end(), a[i]) - num.begin() + 1;
	for (int i = n; i >= 1; i--) {
		REPP(j, 1, tot) {
			cnt[i][j] = cnt[i + 1][j];
		}
		cnt[i][a[i]]++;
	}
	REPP(i, 1, n) {
		REPP(j, 1, tot) {
			cnt[i][j] += cnt[i][j - 1];
		}
	}
	long long ans = 0;
	REPP(i, 1, n) {
		REPP(j, i + 1, n) if (a[i] < a[j]) {
			ans += cnt[j + 1][a[i] - 1];
		}
	}
	cout << ans << endl;

	return 0;
}

