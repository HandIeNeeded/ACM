#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int MO = 100;
const int N = 1e5 + 5;
const int M = 1e9;
int tmp[N];
int fib[N] = {0, 1};

int main() {
	ios :: sync_with_stdio(0);
    //freopen("tmp.in", "w", stdout);
	srand(time(0) % clock());
    int n = rand() % 10 + 2;
    int x = rand() % MO + 1, y = rand() % MO + 1;
    int h1 = rand() % MO + 1, h2 = rand() % MO + 1;
    cout << n << ' ' << x << ' ' << y << ' ' << h1 << ' ' << h2 << endl;
    REPP(i, 1, n) {
        cout << rand() % MO + 1 << ' ';
    }
    cout << endl;

	return 0;
}

