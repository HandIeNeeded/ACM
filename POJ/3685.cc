#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 20;
LL mp[N][N];

int n = 6;
int base = 49990;

void init() {
    REPP(i, 1, 5) {
        REPP(j, 1, 5) {
            LL a = i + base;
            LL b = j + base;
            mp[i][j] = a * a + 100000 * a + b * b - 100000 * b + a * b;
        }
        REPP(j, 1, 5) {
            cout << mp[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif


    

    return 0;
}

