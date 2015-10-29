#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;

int a[N], n;
int b[N];

bool check() {
	REP(i, 1 << n) if (__builtin_popcount(i) > 1) {
		int ans = 0;
		REP(j, n) {
			if (i & (1 << j)) {
				ans ^= a[j];
			}
		}
		if (ans == 0) return 0;
	}
	return 1;
}

int main() {
	ios :: sync_with_stdio(0);
    //freopen("tmp.in", "w", stdout);
	srand(time(0) % clock());
	//cout << RAND_MAX << endl;
	n = rand() % 13 + 2;
	int m = n * (n - 1) / 2;
	cout << m << endl;
	while (!check()) {
		REP(i, n) {
			a[i] = rand();
		}
	}
	int now = 0;
	REP(i, n) {
		REPP(j, i + 1, n - 1) {
			b[now++] = a[i] ^ a[j];
		}
	}
	random_shuffle(b, b + now);
	REP(i, now) {
		cout << b[i] << " \n"[i == now - 1];
	}
	return 0;
}

