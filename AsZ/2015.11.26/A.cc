#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 2;

int a[N][N], b[N][N];

void rotate() {
    int tmp[N][N];
    tmp[0][1] = a[0][0];
    tmp[1][1] = a[0][1];
    tmp[1][0] = a[1][1];
    tmp[0][0] = a[1][0];
    memcpy(a, tmp, sizeof(a));
}

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif

    int t, ca = 1;

    scanf("%d", &t);
    while (t--) {
        REP(i, 2) {
            REP(j, 2) {
                scanf("%d", &a[i][j]);
            }
        }
        REP(i, 2) {
            REP(j, 2) {
                scanf("%d", &b[i][j]);
            }
        }
        int good = 0;
        REP(round, 4) {
            if (a[0][0] == b[0][0] && a[0][1] == b[0][1] && a[1][0] == b[1][0] && a[1][1] == b[1][1]) good = 1;
            rotate();
        }
        printf("Case #%d: ", ca++);
        good ? puts("POSSIBLE") : puts("IMPOSSIBLE");
    }


    return 0;
}


