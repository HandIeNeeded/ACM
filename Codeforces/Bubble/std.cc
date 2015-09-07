#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 10005;
char str[N];

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) > 0) {
        set<string> s;
        string ss;
        REPP(i, 1, n) {
            int x;
            scanf("%d", &x);
            ss += 10 + x;
        }
        REP(i, n) {
            REPP(j, i, n - 1) {
                s.insert(ss.substr(i, j - i + 1));
            }
        }
        printf("%d\n", s.size());
    }

    return 0;
}
