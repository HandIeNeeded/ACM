#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 1e5 + 5;
const int M = 1e9;
int tmp[N];

int main() {
	ios :: sync_with_stdio(0);
    //freopen("tmp.in", "w", stdout);
	srand(time(0) % clock());
    int t = 1;
    cout << t << endl;
    REP(i, t) {
        int W = rand() % 10 + 1, H = rand() % 10 + 1;
        int n = rand() % 4 + 3;
        cout << n << ' ' << W << ' ' << H << endl;
        REP(i, n) {
            cout << rand() % 15 << ' ' << rand() % 15 << endl;
        }
    }
	return 0;
}

