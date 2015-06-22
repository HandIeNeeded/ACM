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
#define LL long long

using namespace std;

int main() {
    ios :: sync_with_stdio(0);
	int n, p, x;
	cin >> n >> p >> x;
	LL ans = -1, id = 0;
	REPP(i, 1, n) {
		int tmp;
		cin >> tmp;
		if (1LL * tmp * p > ans) {
			ans = 1LL * tmp * p;
			id = i;
		}
		p -= x;
	}
	//cout << ans << endl;
	cout << id << endl;

    return 0;
}

