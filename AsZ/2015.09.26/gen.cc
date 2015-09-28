#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 1e5 + 5;
int tmp[N];



const int M = 8;

int main() {
	ios :: sync_with_stdio(0);
    //freopen("tmp.in", "w", stdout);
	srand(time(0) % clock());
    int t = 2;
    cout << t << endl;
    REP(i, t) {
        int h = M, w = M, m = 10, n = rand() % M;
        cout << h << ' '  << w << ' ' << m << ' ' << n << endl;
        REP(i, n) {
            int x = rand() % h + 1, y = rand() % w + 1; 
            int dx = rand() % M, dy = rand() % M;
            while (x + dx > h || y + dy > w) {
                dx = rand() % M;
                dy = rand() % M;
            }
            cout << x << ' '  << y << ' ' << x + dx << ' ' << y + dy << ' ' << rand() % m + 1 << endl;
        }
    }
	return 0;
}

