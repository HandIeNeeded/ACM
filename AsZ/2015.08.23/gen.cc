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
        int n = rand() % 6 + 1;
        cout << n << endl;
        REP(i, n) tmp[i] = i + 1;
        random_shuffle(tmp, tmp + n);
        REP(i, n) cout << tmp[i] << ' ';
        cout << endl;
    }
	return 0;
}

