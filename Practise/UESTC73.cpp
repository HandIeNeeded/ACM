#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 100005;
int fac[N], cnt[N], num, n;
int vis[N], p[N], tot;


void Init() {
	for (int i = 2; i < N; ++i) {
		if (!vis[i]) p[tot++] = i;
		for (int j = 0; j < tot && i * p[j] < N; ++j) {
			vis[i * p[j]] = p[j];
			if (i % p[j] == 0) break;
		}
	}
}

int main() {
	//freopen("cf.in", "r", stdin);
	ios :: sync_with_stdio(0);

	Init();

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		if (n == 1) {
			cout << 2 << endl;
		}
		else {
			int tmp = n;
			num = 0;
			for (int i = 0; i < tot && p[i] * p[i] <= tmp; ++i) {
				if (tmp % p[i] == 0) {
					fac[num++] = p[i];
					while (tmp % p[i] == 0) {
						tmp /= p[i];
					}
				}
			}
			if (tmp > 1) {
				fac[num++] = tmp;
			}

			int now = 1;
			REP(i, num) now *= fac[i];
			cout << n / now + 1 << endl;
		}
	}

	return 0;
}