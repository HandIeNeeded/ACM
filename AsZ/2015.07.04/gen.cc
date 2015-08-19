#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
const int M = 1e9;
int tmp[N];
int a[N], b[N];

int main() {
	ios :: sync_with_stdio(0);
    //freopen("tmp.in", "w", stdout);
	srand(time(0) % clock());
	REP(t, 2) {
		int n = 100, a = rand() % 100 + 20, b = rand() % 80;
		if (a > b) swap(a, b);
		cout << n << ' ' << a << ' ' << b << endl;
		cout << 0.7 << endl;
		REPP(i, 1, n + 1) {
			::a[i] = rand() % 1000;
			::b[i] = rand() % 200;
		}
		sort(::a + 1, ::a + n + 2);
		REPP(i, 1, n + 1) {
			cout << ::a[i] + i << ' ' << ::b[i] << endl;
		}
	}
	cout << 0 << endl;
	return 0;
}

