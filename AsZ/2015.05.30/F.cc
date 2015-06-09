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

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int main() {
    ios :: sync_with_stdio(0);
	freopen("merge.in", "r", stdin);
	freopen("merge.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	REPP(i, 1, n + m) {
		string ans, tmp;
		int first = 0;
		REPP(k, 0, i) {
			int x = k, y = i - k;
			stringstream out;
			if (x > n || y > m) continue;
			if (first == 0) {
				if (x > 0 && y == 0) {
					out << "x" << x;
				}
				else if (y > 0 && x == 0) {
					out << "y" << y;
				}
				else {
					out << "x" << x << "|" << "y" << y;
				}
				out >> tmp;
				ans = tmp;
				first++;
			}
			else {
				if (x > 0 && y == 0) {
					out << "x" << x;
				}
				else if (y > 0 && x == 0) {
					out << "y" << y;
				}
				else {
					out << "x" << x << "|" << "y" << y;
				}
				out >> tmp;
				ans = "(" + ans + ")&" + "(" + tmp + ")";
			}
		}
		assert(ans.size() <= 2000);
		cout << ans << endl;
	}

    return 0;
}

