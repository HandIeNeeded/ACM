#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 1e5 + 5;
const int M = 1e9;
int tmp[N];
int fib[N] = {0, 1};

int main() {
	ios :: sync_with_stdio(0);
    //freopen("tmp.in", "w", stdout);
	srand(time(0) % clock());
    REPP(i, 2, 30) fib[i] = fib[i - 1] + fib[i - 2];
    int t = 10;

    cout << t << endl;
    REP(i, t) {
        int n = rand() % 30 + 1, m = rand() % fib[n] + 1;
        cout << n << ' ' << m << endl;
    }
	return 0;
}

