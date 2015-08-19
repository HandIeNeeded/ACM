#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 500;

int vis[N], p[N], tot;

void prime() {
	for (int i = 2; i < N; i++) {
		if (!vis[i]) p[tot++] = i;
		for (int j = 0; j < tot && i * p[j] < N; j++) {
			vis[i * p[j]] = p[j];
			if (i % p[j] == 0) break;
		}
	}
}

int mp[30][30], a[30], b[30];
int h[30][30];

int main() {
    ios :: sync_with_stdio(0);
	freopen("elegant.in", "r", stdin);
	freopen("elegant.out", "w", stdout);
	prime();
	int n;
	cin >> n;
	REP(i, n) a[i] = p[i], b[i] = p[i + n];
	if (n & 1) {
		REP(i, n) {
			REP(j, n) {
				mp[i][j] = a[(j + i) % n] * b[(j + (n - 1) * i) % n];
				cout << mp[i][j] << " \n"[j == n - 1];
			}
		}
	}
	else {
		REP(i, n) {
			REP(j, n) {
				mp[i][j] = a[(j + i) % n] * b[(j + (n - 1) * i) % n];
			}
		}
		//REP(i, n) {
		//	REP(j, n) {
		//		cout << mp[i][j] << " \n"[j == n - 1];
		//	}
		//}
		REP(i, n / 2) {
			REP(j, n / 2) {
				h[j][(i + j) % (n / 2)] = p[2 * n + i];
			}
		}
		//REP(i, n / 2) {
		//	REP(j, n / 2) {
		//		cout << h[i][j] << " \n"[j == n / 2 - 1];
		//	}
		//}
		REP(i, n / 2) {
			REP(j, n / 2) {
				mp[i][j] *= h[i][j];
				mp[i][j + n / 2] *= h[i][j];
			}
		}
		REP(i, n / 2) {
			REP(j, n / 2) {
				h[j][(i + j + 1) % (n / 2)] = p[2 * n + i];
			}
		}
		//REP(i, n / 2) {
		//	REP(j, n / 2) {
		//		cout << h[i][j] << " \n"[j == n / 2 - 1];
		//	}
		//}
		REP(i, n / 2) {
			REP(j, n / 2) {
				mp[i + n / 2][j] *= h[i][j];
				mp[i + n / 2][j + n / 2] *= h[i][j];
			}
		}
		REP(i, n) {
			REP(j, n) {
				cout << mp[i][j] << " \n"[j == n - 1];
			}
		}
	}
	//REP(i, n) {
	//	REP(j, n) {
	//		mp[i][j] = a[(j + i) % n] * b[(j + 44 * i) % n];
	//		cout << mp[i][j] << " \n"[j == n - 1];
	//		//printf("(%d, %d)%c", a[(j + i) % n], b[(j + i) % n], " \n"[j == n - 1]);
	//	}
	//}
    return 0;
}
