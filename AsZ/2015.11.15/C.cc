#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 120;
char s[N], r[N], tmp[6][N];
int n;

void dfs(int dep, int cost, int &ans) {
    if (cost >= ans) return ;
    if (dep == 6) {
        int cnt = 0;
        REP(i, n) cnt += s[i] != r[i];
        if (cnt + cost < ans) {
            cout << s << ' ' << r << endl;
            cout << ans << endl;
        }
        ans = min(ans, cnt + cost);
        return ;
    }
    memcpy(tmp[dep], s, sizeof(s));
    REP(i, 6) {
        REP(j, n) if (s[j] == '1' + dep) s[j] = '1' + i;
        dfs(dep + 1, cost + (i != dep), ans);
        memcpy(s, tmp[dep], sizeof(s));
    }
}

int main() {
#ifdef HOME
    freopen("C.in", "r", stdin);
#endif

    while (scanf("%s", s) > 0) {
        n = strlen(s);
        int ans = 0;
        scanf("%s", r);
        //cout << s << ' ' << r << endl;
        swap(s, r);
        //cout << s << ' ' << r << endl;
        REP(i, n) ans += s[i] != r[i];
        dfs(0, 0, ans);
        printf("%d\n", ans);
    }

    return 0;
}

