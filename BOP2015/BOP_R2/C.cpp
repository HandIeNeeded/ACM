#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
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
#define LL long long

using namespace std;

const int N = 1e5 + 5;

int in() {
	char c;
	while (c = getchar(), (c < '0' || c > '9') && (c != '-'));
	bool flag = (c == '-');
	if (flag) c = getchar();
	int x = 0;
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - 48;
		c = getchar();
	}
	return flag ? -x : x;
}

void out(LL x) { //int
	if (x < 0) putchar('-'), x = -x;
	int len = 0, bit[20]; // LL  -> bit[20]
	while (x) {
		bit[len++] = x % 10;
		x /= 10;
	}
	if (!len) bit[len++] = 0;
	while (len--) putchar(bit[len] + 48);
	putchar('\n');
}

int col[10], cnt[10];
int a[N], b[N], n;
LL ans;

void calc(int dep, int k) {
	if (dep == k) {
		if (ans < 10) {
			REP(i, k) {
				cout << col[i] << ' ';
			}
			cout << "lalala" << ans << endl;
		}
		return ;
	}
	int pos = 0;
	REPP(i, 1, dep - 1) pos += cnt[i];
	pos++;
	//cout << dep << ' ' << pos << "hehe" << endl;
	REPP(i, 1, n) {
		if (b[i] == col[dep - 1]) {
			swap(b[i], b[pos]);
			ans += abs(i - pos);
			pos++;
		}
	}
	calc(dep + 1, k);
}

int main() {
	int t, k, ca = 1;
	freopen("C.in", "r", stdin);
	t = in();
	while (t--) {
		n = in(), k = in();
		REP(i, k + 1) cnt[i] = 0;
		REPP(i, 1, n) {
			a[i] = in();
			cnt[a[i]]++;
		}
		//REPP(i, 1, k) cout << cnt[i] << ' ';
		//cout << endl;
		REP(i, k) col[i] = i + 1;
		LL res = 1LL << 60;
		do {
			ans = 0;
			REPP(i, 1, n) b[i] = a[i];
			calc(1, k);
			res = min(res, ans);
		}while(next_permutation(col, col + k));
		printf("Case #%d: ", ca++);
		out(res);
	}

	return 0;
}

