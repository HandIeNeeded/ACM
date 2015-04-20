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

const string str[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};
char s[2][10];
int day[2], year[2], month[2];

int get(int x) {
	int k = x / 400, b = x % 400;
	return 97 * k + b / 4 - b / 100 + 1;
}

int find(char *s) {
	REP(i, 12) {
		if (str[i] == string(s)) {
			return i;
		}
	}
	return -1;
}

int main() {
	ios :: sync_with_stdio(0);
	int t, ca = 1;
	scanf("%d", &t);
	while (t--) {
		REP(i, 2) scanf("%s%d,%d", s[i], day + i, year + i);
		REP(i, 2) month[i] = find(s[i]);
		int ans = 0;
		if (year[0] == year[1]) {
			int lunar = (year[0] % 100 && year[0] % 4 == 0) || year[0] % 400 == 0;
			if (lunar) {
				if (!(month[0] > 1 || month[1] < 1 || (month[1] == 1 && day[1] < 29))) {
					ans = 1;
				}
			}
		}
		else {
			int lunar = (year[0] % 100 && year[0] % 4 == 0) || year[0] % 400 == 0;
			if (lunar) {
				if (month[0] < 1 || (month[0] == 1 && day[0] <= 29)) {
					ans++;
				}
			}
			lunar = (year[1] % 100 && year[1] % 4 == 0) || year[1] % 400 == 0;
			if (lunar) {
				if (month[1] > 1 || (month[1] == 1 && day[1] == 29)) {
					ans++;
				}
			}
		}
		ans += max(0, get(year[1] - 1) - get(year[0]));
		printf("Case #%d: %d\n", ca++, ans);
	}

	return 0;
}

