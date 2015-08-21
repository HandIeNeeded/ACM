#include <bits/stdc++.h>

#define REP(i, a) for(int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 100005;
int sg[N], mex[N << 2];

void init(int limit) {
	REPP(i, limit, N - 1) {
		int start = i / limit + 1;
		for (int j = start; j >= 2; --j) {
			int a = i / j;
			int tmp = 0;
			if ((j - i % j) & 1) tmp ^= sg[a];
			if ((i % a) & 1) {
				tmp ^= sg[a + 1];
			}
			mex[tmp] = i;
		}
		int now = 0;
		while (mex[now] == i) now++;
		sg[i] = now;
	}
}

string tostring(int x) {
	string ans;
	REP(i, 20) {
		ans += (char) ((x & 1) + '0');
		x >>= 1;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("nimg.in", "r", stdin);
	freopen("nimg.out", "w", stdout);
	int round, limit;
	cin >> round >> limit;
	init(limit);
	REP(i, round) {
		int n, x;
		cin >> n;
		int ans = 0;
		REP(i, n) {
			cin >> x;
			ans ^= sg[x];
		}
		cout << (ans > 0) << " \n"[i == round - 1];
	}

	return 0;
}
