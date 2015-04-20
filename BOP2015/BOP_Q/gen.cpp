#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 30005;
const int M = 200;

int main() {
	ios :: sync_with_stdio(0);
	srand(time(0) % clock());
	int n, m, t, a, b;
	t = rand() % 10 + 1;
	cout << t << endl;
	REPP(i, 1, t) {
		n = M, m = M;
		a = rand() % M + 1, b = rand() % M + 1;
		cout << n << ' ' << m << ' ' << a << ' ' << b << endl;
		REPP(i, 1, a + b) {
			int x = rand() % n + 1, y = rand() % m + 1;
			cout << x << ' ' << y << endl;
		}
	}
	return 0;
}

