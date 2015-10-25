#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 1e6 + 5;
const int M = 50;
int tmp[N];

int main() {
	ios :: sync_with_stdio(0);
    //freopen("tmp.in", "w", stdout);
	srand(time(0) % clock());
    int t = 1;
    REP(i, t) {
        int n = rand() % 5 + 3;
        cout << n << endl;
        REPP(i, 1, n) {
            cout << rand() % M + 1 << ' ' << rand() % M + 1 << endl;
        }
    }
	return 0;
}

