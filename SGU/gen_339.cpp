#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;

int main() {
	ios :: sync_with_stdio(0);
    freopen("tmp.in", "w", stdout);
	srand(time(0) % clock());
	//cout << RAND_MAX << endl;
    REPP(i, 1, 20) {
		int x = rand() % int(20) - 10, y = rand() % int(20) - 10;
		if (x > y) swap(x, y);
		cout << (rand() & 1 ? '+' : '-') << ' ' << x << ' ' << y << endl;
    }
	return 0;
}

