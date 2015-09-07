#include <cstdio>
#include <queue>
#include <cstring>
#include <cmath>
//#include <tuple>
#include <iostream>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 55;
const double eps = 1e-8;

int dp[N][N][2], n, m;
int sx, sy, bx, by;
char mp[N][N];

//tuple<int, int, int> pre[N][N][2];

int cmp(double x) {
    if (fabs(x) < eps) return 0;
    if (x > 0) return 1;
    return -1;
}

bool good(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] != 'X';
}

bool cross(int a, int b, int p, int q) {
    if (a > p) {
        swap(a, p), swap(b, q);
    }
    double A = (q - b) - 1201 * (p - a);
    double B = by * (p - a) - bx * 1201 * (p - a) - (p - a) * q + p * (q - b);
    double x = B / A;
    return cmp(x - bx) > 0 && cmp(x - a) > 0 && cmp(x - p) < 0;
}

//void print(int x, int y, int z) {
//    int a, b, c;
//    tie(a, b, c) = pre[x][y][z];
//    while (a || b || c) {
//        //cout << a << ' ' << b << ' ' << c << endl;
//        tie(a, b, c) = pre[a][b][c];
//    }
//}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    REPP(i, 1, n) {
        scanf("%s", mp[i] + 1);
    }
    REPP(i, 1, n) {
        REPP(j, 1, m) {
            if (mp[i][j] == 'X') {
                bx = i, by = j;
            }
            if (mp[i][j] == '*') {
                sx = i, sy = j;
            }
        }
    }
    //cout << sx << ' ' << sy << ' ' << bx << ' ' << by << endl;
    queue<int> q;
    MST(dp, -1);
    dp[sx][sy][0] = 0;
    q.push(sx), q.push(sy), q.push(0);
    int find = 0, ans = 0;
    while (q.size()) {
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        int state = q.front(); q.pop();
        REPP(i, -1, 1) {
            REPP(j, -1, 1) if (i || j) {
                int tx = x + i, ty = y + j;
                if (!good(tx, ty)) continue;
                int newstate = state;
                if (cross(x, y, tx, ty)) newstate ^= 1;
                if (dp[tx][ty][newstate] == -1) {
                    dp[tx][ty][newstate] = dp[x][y][state] + 1;
                    //pre[tx][ty][newstate] = make_tuple(x, y, state);
                    if (tx == sx && ty == sy && newstate == 1) {
                        ans = dp[tx][ty][newstate];
                        find = 1;
                        break;
                    }
                    q.push(tx), q.push(ty), q.push(newstate);
                }
            }
            if (find) break;
        }
        if (find) break;
    }
    //print(sx, sy, 1);
    printf("%d\n", ans);

    return 0;
}

