#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1005;
bool vis[N];

int main() {
#ifdef HOME
    freopen("C.in", "r", stdin);
#endif


    int n, m;
    scanf("%d%d", &n, &m);
    int ans = n + 1;
    REP(i, m) {
        int x, y;
        cin >> x >> y;
        REPP(i, x + 1, y) vis[i] = 1;
    }
    REPP(i, 1, 1000) ans += 2 * vis[i];
    cout << ans << endl;

    return 0;
}


