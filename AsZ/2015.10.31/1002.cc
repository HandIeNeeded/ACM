#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 2005;

char s[505][N];
int f[505][N], ban[505];

void getfail(char *s, int *f) {
    int n = strlen(s);
    f[0] = f[1] = 0;
    for (int i = 1; i < n; i++) {
        int j = f[i];
        while (j && s[j] != s[i]) j = f[j];
        f[i + 1] = s[j] == s[i] ? j + 1 : 0;
    }
}

bool kmp(int now, int pre) {
    int n = strlen(s[pre]), m = strlen(s[now]);
    int pos = 0;
    REP(i, m) {
        int j = pos;
        while (j && s[pre][j] != s[now][i]) j = f[pre][j];
        pos = s[pre][j] == s[now][i] ? j + 1 : 0;
        if (pos == n) return 1;
    }
    return 0;
}

int main() {
#ifdef HOME
    freopen("1002.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int ans = -1;
        REPP(i, 1, n) {
            ban[i] = 0;
            scanf("%s", s[i]);
        }
        REPP(i, 1, n) {
            REPP(j, 1, i - 1) if (!ban[j]) {
                if(kmp(i, j)) {
                    ban[j] = 1;
                }
                else {
                    ans = i;
                    break;
                }
            }
            getfail(s[i], f[i]);
        }
        printf("Case #%d: %d\n", ca++, ans);
    }
    return 0;
}


