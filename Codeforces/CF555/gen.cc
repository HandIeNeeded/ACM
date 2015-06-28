#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
const int M = 1e9;
int tmp[N];

int main() {
	ios :: sync_with_stdio(0);
    //freopen("tmp.in", "w", stdout);
	srand(time(0) % clock());
	int n = 50000, k = rand() % M;
	cout << n << ' ' << k << endl;
	REP(i, n) {
		cout << rand() % M << endl;
	}
	int q = 50000;
	cout << q << endl;
	REP(i, q) {
		int x = rand() % n, y = rand() % n;
		if (x > y) swap(x, y);
		cout << x << ' ' << y << endl;
	}
	return 0;
}

