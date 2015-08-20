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

int a, b;
string str[2] = {"Daenerys", "Stannis"};

int main() {
    ios :: sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	k = n - k;
	int res = 0;
	REPP(i, 1, n) {
		int x;
		cin >> x;
		if (x & 1) a++;
		else b++;
	}
	if (k == 0) {
		if (a & 1) res = 1;
		else res = 0;
		cout << str[res] << endl;
		return 0;
	}
	int num = k >> 1;
	if (num >= min(a, b)) {
		if (a <= b) {
			res = 0;
		}
		else {
			res = (n - k) & 1;
		}
	}
	else {
		if (k & 1) res = 1;
		else res = 0;
	}
	cout << str[res] << endl;

    return 0;
}

