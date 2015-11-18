#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
char s[N];
int cnt[2][30];

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    freopen("concatenation.in", "r", stdin);
    freopen("concatenation.out", "w", stdout);
    LL ans = 1;
    REP(i, 2) {
        scanf("%s", s);
        int n = strlen(s);
        ans *= n;
        REP(j, n) cnt[i][s[j] - 'a']++;
        if (i == 0) cnt[i][s[0] - 'a']--;
        if (i == 1) cnt[i][s[n - 1] - 'a']--;
    }
    REP(i, 26) {
        ans -= 1LL * cnt[0][i] * cnt[1][i];
    }
    cout << ans << endl;
    return 0;
}


