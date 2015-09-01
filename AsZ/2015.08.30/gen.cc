#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 1e6 + 5;
const int M = 1e9;
int a[N];

int main() {
	ios :: sync_with_stdio(0);
    //freopen("tmp.in", "w", stdout);
	srand(time(0) % clock());
    int t = 1;
    cout << t << endl;
    REP(i, t) {
        int n = 8000;
        cout << n << endl;
        REPP(i, 1, n) a[i] = rand() % 40 + 1;
        REPP(i, 1, n) {
            cout << a[i] << ' ';
        }
        cout << endl;
        int m = 8000;
        cout << m << endl;
        while (m--) {
            int l = rand() % n + 1, r = rand() % n + 1;
            if (l > r) swap(l, r);
            cout << l << ' ' << r << endl;
        }
    }


	return 0;
}

