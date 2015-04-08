#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

int main() {
	ios :: sync_with_stdio(0);

	srand(time(0) % clock());
	
	int n = rand() % 4 + 1;
	int m = rand() % 4 + 1;
	if (n < m) swap(n, m);
	cout << n << ' ' << m << ' ' << endl;
	REP(i, n) {
		cout << rand() % 8 << ' ';
	}
	cout << endl;
	return 0;
}
