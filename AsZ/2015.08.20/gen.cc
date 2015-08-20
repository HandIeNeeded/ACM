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
    REP(i, 3) {
        int n = rand() % 4 + 3, m = rand() % 4 + 3;
        cout << n << ' ' << m << endl;
        REP(i, n) {
            cout << rand() % 100 + 1 << ' ';
        }
        cout << endl;
        REP(i, m) {
            cout << rand() % 100 + 1 << ' ';
        }
        cout << endl;
    }
	return 0;
}

