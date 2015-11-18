#include <bits/stdc++.h>

using namespace std;

const int gx[] = {0, 1, 0, -1};
const int gy[] = {1, 0, -1, 0};
const int MAXN = 56 * 56 * 10;
const int limXY = 50;

// N:0, E:1, S:2, W:3
vector <int> des[MAXN][11];
// (x, y, inp)
int ti[MAXN], now, canGo[limXY + 5][limXY + 5][10], ans[limXY + 5][limXY + 5];
char ha[] = "NESW";

void addRoadCan(int x1, int y1, int x2, int y2) {
    if (y1 > y2) swap(y1, y2);
    if (x1 > x2) swap(x1, x2);
    if (x1 == x2) {
        for (int i = y1; i < y2; ++i)
            canGo[x1][i][0] = 1;
        for (int i = y2; i > y1; --i)
            canGo[x1][i][2] = 1;
    } else {
        for (int i = x1; i < x2; ++i)
            canGo[i][y1][1] = 1;
        for (int i = x2; i > x1; --i)
            canGo[i][y1][3] = 1;
    }
}

int legal(int ip, int op) {
    int rip = (ip + 2) % 4;
    if (rip == op) return 0;
    return 1;
}

int calc(int x, int y, int p) {
    return ((x * 51) + y) * 4 + p;
}

void recalc(int &x, int &y, int &p, int val) {
    p = val % 4;
    val /= 4;
    y = val % 51;
    x = val / 51;
}

void init() {
    for (int i = 0; i <= limXY; ++i)
        for (int j = 0; j <= limXY; ++j)
            for (int p = 0; p < 4; ++p)
                if (canGo[i][j][p]) {
                    int u = calc(i, j, p);
                    int nx = i + gx[p];
                    int ny = j + gy[p];
                    int v = calc(nx, ny, p);
                    des[u][1].push_back(v);
                    for (int d = 2; d <= 10; ++d) {
                        ++now;
                        for (int k = 0; k < des[u][d - 1].size(); ++k) {
                            int dx, dy, dip, du = des[u][d - 1][k];
                            recalc(dx, dy, dip, du);
                            for (int dop = 0; dop < 4; ++dop)
                                if (canGo[dx][dy][dop] && legal(dip, dop)) {
                                    int dnx = dx + gx[dop];
                                    int dny = dy + gy[dop];
                                    int dv = calc(dnx, dny, dop);
                                    if (ti[dv] != now) {
                                        des[u][d].push_back(dv);
                                        ti[dv] = now;
                                    }
                                }
                        }
                    }
                }
}

vector <int> vec0, vec1;

void letGo(int x, int y, int p) {
    //int nx = x + gx[p];
    //int ny = y + gy[p];
    //for (int np = 0; np < 4; ++np)
      //  if (canGo[nx][ny][np]) {
            int v = calc(x, y, p);
            if (ti[v] != now) {
                ti[v] = now;
                vec1.push_back(v);
            }
        //}
}

int main() {
#ifdef HOME
    freopen("in.txt", "r", stdin);
#endif
    int n, x0, y0, t;
    scanf("%d%d%d%d", &n, &x0, &y0, &t);
    for (int i = 1; i <= n; ++i) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        addRoadCan(x1, y1, x2, y2);
    }

    init();

    for (int p = 0; p < 4; ++p)
        if (canGo[x0][y0][p])
            vec0.push_back(calc(x0, y0, p));

    for (int i = 1; i <= t; ++i) {
        int d, pr;
        char ch;
        scanf("%d %c\n", &d, &ch);
        for (int j = 0; j < 4; ++j)
            if (ch == ha[j]) pr = j;

        vec1.clear();
        ++now;
        for (; !vec0.empty(); ) {
            int u = vec0.back();
            vec0.pop_back();
            int x, y, p;
            recalc(x, y, p, u);
            for (int j = 0; j < des[u][d].size(); ++j) {
                int v = des[u][d][j];
                int xv, yv, pv;
                recalc(xv, yv, pv, v);
                if (pv == pr) {
                    //go All direction
                    for (int k = 0; k < 4; ++k)
                        if (canGo[xv][yv][k] && legal(pv, k))
                            letGo(xv, yv, k);
                } else {
                    //only p
                    if (canGo[xv][yv][pr] && legal(pr, pv)) {
                        letGo(xv, yv, pr);
                    }
                }
            }
        }
        swap(vec0, vec1);
    }

    for (int i = 0; i < vec0.size(); ++i) {
        int x, y, p;
        recalc(x, y, p, vec0[i]);
        ans[x][y] = 1;
    }

    for (int i = 0; i <= limXY; ++i)
        for (int j = 0; j <= limXY; ++j)
            if (ans[i][j])
                printf("%d %d\n", i, j);
    return 0;
}
