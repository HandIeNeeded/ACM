#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2005;

int mp[N][N], now;

void paint(int x, int y, int type) {
    now++;
    REP(i, 2) {
        REP(j, 2) {
            if (((i << 1) | j) == type) continue;
            mp[x + i][y + j] = now;
        }
    }
}

void draw(int, int, int, int);
void solve(int, int, int);

/*
 * 0 for   *
 *       * *
 *
 * 1 for * 
 *       * *
 *
 * 2 for * *
 *         *
 *
 * 3 for * *
 *       *
 */

void get0(int x, int y) {
    paint(x, y + 2, 2);
    paint(x + 2, y, 1);
    paint(x + 1, y + 1, 0);
    paint(x + 2, y + 2, 0);
}

void get1(int x, int y) {
    paint(x, y, 3);
    paint(x + 2, y, 1);
    paint(x + 1, y + 1, 1);
    paint(x + 2, y + 2, 0);
}

void get2(int x, int y) {
    //no need
}

void get3(int x, int y) {
    paint(x, y, 3);
    paint(x + 1, y + 1, 3);
    paint(x, y + 2, 2);
    paint(x + 2, y, 1);
}

void draw(int x, int y, int n, int length) {
    if (length == 3) {
        int cnt = (n - 3) / 2;
        REP(i, cnt) {
            paint(x, y + i * 2 + 3, 3);
            paint(x + 1, y + i * 2 + 3, 0);
        }
        REP(i, cnt) {
            paint(x + i * 2 + n, y + n * 2 - 3, 3);
            paint(x + i * 2 + n, y + n * 2 - 2, 0);
        }
        solve(x + 2 * n - 6, y, 3);
        cnt = (2 * n - 6) / 2;
        REP(i, cnt) {
            paint(x + i * 2, y, 3);
            paint(x + i * 2, y + 1, 0);
        }
        REP(i, cnt) {
            paint(x + n * 2 - 3, y + 6 + i * 2, 3);
            paint(x + n * 2 - 2, y + 6 + i * 2, 0);
        }
    }
    else {
        int cnt = (n - 6) / 2;
        REP(i, cnt) {
            paint(x, y + i * 2 + 6, 3);
            paint(x + 1, y + i * 2 + 6, 0);
            paint(x + 3, y + i * 2 + 6, 3);
            paint(x + 4, y + i * 2 + 6, 0);
        }
        REP(i, cnt) {
            paint(x + n + 2 * i, y + 2 * n - 6, 3);
            paint(x + n + 2 * i, y + 2 * n - 5, 0);
            paint(x + n + 2 * i, y + 2 * n - 3, 3);
            paint(x + n + 2 * i, y + 2 * n - 2, 0);
        }
        solve(x + 2 * n - 12, y, 6);
        cnt = (2 * n - 12) / 4;
        REP(i, cnt) {
            get3(x + i * 4, y);
            get0(x + i * 4, y + 2);
        }
        REP(i, cnt) {
            get3(x + n * 2 - 6, y + 12 + i * 4);
            get0(x + n * 2 - 4, y + 12 + i * 4);
        }
    }
}

void solve(int x, int y, int n) {
    if (n == 1) {
        paint(x, y, 1);
    }
    else if (n == 2) {
        get1(x, y);
    }
    else if (n == 3) {
        paint(x, y, 3);
        paint(x, y + 1, 0);
        paint(x + 2, y + 2, 1);
        paint(x + 3, y + 4, 3);
        paint(x + 4, y + 4, 0);
        get1(x + 2, y);
    }
    else if (n == 4) {
        get1(x + 2, y + 2);
        get1(x + 4, y);
        get3(x, y);
        get0(x + 4, y + 4);
    }
    else if (n == 6) {
        get3(x, y);
        get0(x, y + 2);
        get1(x + 4, y + 4);
        get3(x + 6, y + 8);
        get0(x + 8, y + 8);
        solve(x + 4, y, 4);
    }
    else {
        if (n & 1) {
            draw(x, y, n, 3);
            solve(x + 3, y + 3, n - 3);
        }
        else {
            draw(x, y, n, 6);
            solve(x + 6, y + 6, n - 6);
        }
    }
}

void print(int n) {
    REPP(i, 1, n) {
        REPP(j, 1, n) {
            printf("%d%c", mp[i][j], " \n"[j == n]);
        }
    }
    REPP(i, 1, n) {
        REPP(j, 1, 2 * n) {
            printf("%d%c", mp[i + n][j], " \n"[j == 2 * n]);
        }
    }
}

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) > 0) {
        now = 0;
        solve(1, 1, n);
        print(n);
    }

    return 0;
}
