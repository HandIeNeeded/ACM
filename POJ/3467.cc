#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 105;
int dp[4][N][N];
int a[N][N], ans[N], n, m;

int get(int i, int j) {
    int a = dp[0][i][j], b = dp[1][i][j], c = dp[2][i][j], d = dp[3][i][j];
    a = min(a, b), c = min(c, d), a = min(a, c);
    return a - 1;
}

void getDP() {
    //right
    REPP(i, 1, n) {
        for (int j = m; j >= 1; j--) {
            dp[0][i][j] = a[i][j] == a[i][j + 1] ? dp[0][i][j + 1] + 1 : 1;
        }
    }

    //left  
    REPP(i, 1, n) {
        REPP(j, 1, m) {
            dp[1][i][j] = a[i][j] == a[i][j - 1] ? dp[1][i][j - 1] + 1: 1;
        }
    }

    //down
    REPP(j, 1, m) {
        for (int i = n; i >= 1; i--) {
            dp[2][i][j] = a[i][j] == a[i + 1][j] ? dp[2][i + 1][j] + 1 : 1;
        }
    }

    //up
    REPP(j, 1, m) {
        REPP(i, 1, n) {
            dp[3][i][j] = a[i][j] == a[i - 1][j] ? dp[3][i - 1][j] + 1 : 1;
        }
    }

    REPP(i, 1, n) {
        REPP(j, 1, m) {
            ans[a[i][j]] += get(i, j);
        }
    }
}

void update(int x, int y, int c) {
    int pre = a[x][y];
    ans[pre] -= get(x, y);
    a[x][y] = c;
    //right
    for (int j = y; j >= 1; j--) {
        if (j == y) {
            dp[0][x][j] = a[x][j] == a[x][j + 1] ? dp[0][x][j + 1] + 1 : 1;
        }       
        else {
            pre = a[x][j];
            ans[pre] -= get(x, j);
            dp[0][x][j] = a[x][j] == a[x][j + 1] ? dp[0][x][j + 1] + 1 : 1;
            ans[pre] += get(x, j);
        }
    }

    //left
    REPP(j, y, m) {
        if (j == y) {
            dp[1][x][j] = a[x][j] == a[x][j - 1] ? dp[1][x][j - 1] + 1 : 1;
        }
        else {
            pre = a[x][j];
            ans[pre] -= get(x, j);
            dp[1][x][j] = a[x][j] == a[x][j - 1] ? dp[1][x][j - 1] + 1 : 1;
            ans[pre] += get(x, j);
        }
    }

    //down
    for (int i = x; i >= 1; i--) {
        if (i == x) {
            dp[2][i][y] = a[i][y] == a[i + 1][y] ? dp[2][i + 1][y] + 1 : 1;
        }
        else {
            pre = a[i][y];
            ans[pre] -= get(i, y);
            dp[2][i][y] = a[i][y] == a[i + 1][y] ? dp[2][i + 1][y] + 1 : 1;
            ans[pre] += get(i, y);
        }
    }
    
    //up
    REPP(i, x, n) {
        if (i == x) {
            dp[3][i][y] = a[i][y] == a[i - 1][y] ? dp[3][i - 1][y] + 1 : 1;
        }
        else {
            pre = a[i][y];
            ans[pre] -= get(i, y);
            dp[3][i][y] = a[i][y] == a[i - 1][y] ? dp[3][i - 1][y] + 1 : 1;
            ans[pre] += get(i, y);
        }
    }
    ans[c] += get(x, y);
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int c, q;
    scanf("%d%d%d%d", &n, &m, &c, &q);
    REPP(i, 1, n) {
        REPP(j, 1, m) {
            scanf("%d", &a[i][j]);
        }
    }
    getDP();
    while (q--) {
        char tmp[2];
        int x, y, c;
        scanf("%s %d", tmp, &x);
        if (tmp[0] == 'Q') {
            printf("%d\n", ans[x]);
        }
        else {
            scanf("%d %d", &y, &c);
            update(x, y, c);
        }
    }

    return 0;
}

