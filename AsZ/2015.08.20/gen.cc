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
    int t = 4;
    cout << t << endl;
    int l, r;
    REP(i, t) {
        int n = rand() % 100 + 1, m = rand() % 100 + 1;
        cout << n << ' ' << m << endl;
        REPP(i, 1, n) tmp[i] = 100 - rand() % 200;
        REPP(i, 1, n) {
            cout << tmp[i] << ' ';
        }
        cout << endl;
        while (m--) {
            int type = rand() & 1;
            if (type) {
                l = rand() % n + 1, r = 100 - rand() % 200;
            }
            else {
                l = rand() % n + 1, r = rand() % n + 1;
                if (l > r) swap(l, r);
            }
            cout << type << ' ' << l << ' ' << r << endl;
        }
    }
	return 0;
}

