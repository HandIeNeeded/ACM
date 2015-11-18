#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;
const int N = 1e4 + 5;
int cnt[3][N];
char s[N];

int main() {
#ifdef HOME
    freopen("J.in", "r", stdin);
#endif
    int n;
    while (scanf("%d", &n) > 0) {
        int ans = 0;
        memset(cnt, 0, sizeof(cnt));
        REP(i, n) {
            scanf("%s", s);
            if (s[0] == 'S') ans++;
            else {
                int x;
                scanf("%d", &x);
                cnt[s[0] - 'A'][x]++;
            }
        }
        REP(i, 3) {
            ans += cnt[i][1];
        }
        printf("%d\n", ans);
    }


    return 0;
}


