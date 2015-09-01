#include <iostream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1005;
const int M = 1000 * 1000 * 1000;

bitset<N> row[N], col[N];
int a[N][N], b[N][N], c[N][N];
int bx, by;
int n, p, m;

int get(int x, int y) {
    int ans = 0;
    REPP(i, 1, p) {
        ans += a[x][i] * b[i][y];
    }
    return ans;
}

bool good() {
    REPP(i, 1, n) {
        REPP(j, 1, p) {
            row[i][j] = a[i][j] & 1;
        }
    }
    REPP(i, 1, p) {
        REPP(j, 1, m) {
            col[j][i] = b[i][j] & 1;
        }
    }
    REPP(i, 1, n) {
        REPP(j, 1, m) {
            int count = (row[i] & col[j]).count() & 1;
            if (count ^ (c[i][j] & 1)) {
                bx = i, by = j;
                return 0;
            }
        }
    }
    return 1;
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
        }
    }
    int find = 0;
    REPP(i, 1, n) {
        REPP(j, 1, m) {
            scanf("%d", &c[i][j]);
            if (abs(c[i][j]) > M) {
                bx = i, by = j;
                find = 1;
            }
        }
    }
    if (find) {
        puts("No");
        printf("%d %d\n%d\n", bx, by, get(bx, by));
    }
    else {
        if (good()) {
            int sx = rand() % n + 1, sy = rand() % m + 1;
            REP(step, n * m) {
                int tmp = get(sx, sy);
                if (tmp != c[sx][sy]) {
                    puts("No");
                    printf("%d %d\n%d\n", sx, sy, get(sx, sy));
                    return 0;
                }
                sy++;
                if (sy > m) {
                    sy = 1, sx++;
                    if (sx > n) sx = 1;
                }
            }
            puts("Yes");
        }
        else {
            puts("No");
            printf("%d %d\n%d\n", bx, by, get(bx, by));
        }
    }

    return 0;
}
