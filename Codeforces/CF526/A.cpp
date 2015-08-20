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
char s[N];

int main() {
	ios :: sync_with_stdio(0);
	int n;
	cin >> n >> s;
	int flag = 0;
	REP(i, n) {
		if (flag) break;
		if (s[i] == '*') {
			REPP(d, 1, 100) {
				int bad = 0;
				REP(j, 5) {
					if (i + d * j < n && s[i + d * j] == '*') {
						continue;
					}
					else {
						bad = 1;
					}
				}
				if (!bad) {
					flag = 1;
					break;
				}
			}
		}
	}
	cout << (flag ? "yes" : "no") << endl;

	return 0;
}
