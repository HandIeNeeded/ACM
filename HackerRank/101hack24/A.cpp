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

const int N = 105;
int a[N], b[N];

int main() {
	ios :: sync_with_stdio(0);
	int n;
	cin >> n;
	REPP(i, 1, n) {
		cin >> a[i];
	}
	REPP(i, 1, n) {
		cin >> b[i];
	}
	int best = 1;
	REPP(i, 1, n) {
		if (b[best] * a[i] > b[i] * a[best]) {
			best = i;
		}
	}
	vector<int> ans;
	REPP(i, 1, n) {
		if (b[best] * a[i] == b[i] * a[best]) {
			ans.push_back(i);
		}
	}
	REP(i, ans.size()) {
		cout << ans[i] << endl;
	}

	return 0;
}

