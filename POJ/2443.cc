#include <cstdio>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 10005;
int vis[N][1005];

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int now = 0;
    int n;
    while (scanf("%d", &n) > 0) {
        now++;
        REPP(i, 1, n) {
            int cnt = 0;
            scanf("%d", &cnt);
            REP(j, cnt) {
                int x;
                scanf("%d", &x);
                vis[x][i] = now;
            }
        }
        int q;
        scanf("%d", &q);
        while (q--) {
            int x, y;
            scanf("%d%d", &x, &y);
            int good = 0;
            int *a = vis[x], *b = vis[y];
            REPP(i, 1, n) {
                if (a[i] == now && a[i] == b[i]) {
                    good = 1;
                    break;
                }
            }
            good ? puts("Yes") : puts("No");
        }
    }

    return 0;
}

