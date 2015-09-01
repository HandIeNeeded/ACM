#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1005;

int a[N][N], b[N][N], c[N][N];
int n, p, m;
int sum[N];

int get(int x, int y) {
    int ans = 0;
    REPP(i, 1, p) {
        ans += a[x][i] * b[i][y];
    }
    return ans;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    scanf("%d%d%d", &n, &p, &m);
    REPP(i, 1, n) {
        REPP(j, 1, p) {
            scanf("%d", &a[i][j]);
        }
    }
    REPP(i, 1, p) {
        REPP(j, 1, m) {
            scanf("%d", &b[i][j]);
            b[i][0] += b[i][j];
        }
    }
    REPP(i, 1, n) {
        REPP(j, 1, m) {
            scanf("%d", &c[i][j]);
            c[i][0] += c[i][j];
        }
    }

    REPP(i, 1, n) {
        REPP(j, 1, p) {
            sum[i] += a[i][j] * b[j][0];
        }
        if (sum[i] != c[i][0]) {
            REPP(j, 1, m) {
                int tmp = get(i, j);
                if (tmp != c[i][j]) {
                    puts("No");
                    printf("%d %d\n%d\n", i, j, tmp);
                    return 0;
                }
            }
            
        }
    }
    puts("Yes");

    return 0;
}
