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

#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;

multiset<int> girl;
int a[N];

int main() {
    ios :: sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	REPP(i, 1, n) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	REPP(i, 1, n) {
		int x;
		cin >> x;
		girl.insert(x);
	}
	int ans = 0;
	REPP(i, 1, n) {
		int tmp = a[i] - k;
		auto it = girl.lower_bound(tmp);
		if (it == girl.end() || *it > a[i] + k) continue;
		else {
			ans++;
			girl.erase(it);
		}
	}
	cout << ans << endl;

    return 0;
}

