#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 2000;
bool vis[N];

int main() {
#ifdef HOME
    freopen("I.in", "r", stdin);
#endif

    int n;
    cin >> n;
    REPP(i, 1, n) {
        int x, y;
        cin >> x >> y;
        REPP(j, x, y) vis[j] = 1;
    }
    int good = 1;
    REPP(i, 1, 1826) {
        int cnt = 0;
        REP(j, 180) if (i + j <= 1826) {
            if (vis[i + j]) {
                cnt++;
            }
        }
        if (cnt > 90) {
            good = 0;
            break;
        }
    }
    good ? puts("Yes") : puts("No");

    return 0;
}


