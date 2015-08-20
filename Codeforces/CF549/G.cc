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

const int N = 2e5 + 5;
int a[N];

int main() {
    ios :: sync_with_stdio(0);
	int n;
	cin >> n;
	REPP(i, 1, n) {
		cin >> a[i];
		a[i] += i;
	}
	sort(a + 1, a + n + 1);
	REPP(i, 1, n) a[i] -= i;
	REPP(i, 1, n - 1) {
		if (a[i] > a[i + 1]) {
			cout << ":(" << endl;
			return 0;
		}
	}
	REPP(i, 1, n) {
		cout << a[i] << ' ';
	}
	cout << endl;

    return 0;
}


