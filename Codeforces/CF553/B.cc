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

const int N = 55;

LL fib[N] = {1, 1, 2};

void solve(deque<int> &ans, LL k, int dep) {
	if (dep == 0) {
		return ;
	}
	else if (dep == 1) {
		ans.push_back(1);
		return ;
	}
	else {
		if (k <= fib[dep - 1]) {
			solve(ans, k, dep - 1);
			REP(i, ans.size()) ans[i]++;
			ans.push_front(1);
		}
		else {
			solve(ans, k - fib[dep - 1], dep - 2);
			REP(i, ans.size()) ans[i] += 2;
			ans.push_front(1), ans.push_front(2);
		}
		return ;
	}
}

int main() {
    ios :: sync_with_stdio(0);
	REPP(i, 3, 50) fib[i] = fib[i - 1] + fib[i - 2];
	//REPP(i, 1, 50) {
	//	cout << fib[i] << endl;
	//}
	//cout << fib[50] << endl;
	int n;
	LL k;
	cin >> n >> k;
	deque<int> ans;
	solve(ans, k, n);
	REP(i, ans.size()) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	
    return 0;
}
