#include <queue>
#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
#include <iostream>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 25;
const int M = 2200;
int mp[N][N], g[N][N], dp[M][N][N], cnt[9];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
map<deque<pair<int, int> >, int> shape[9];
int n, m, l, k;

bool good(int x, int y, const deque<pair<int, int> > &snake) {
    if (x < 1 || x > n || y < 1 || y > m || mp[x][y]) return 0;
    REP(i, snake.size()) {
        if (snake[i].first == x && snake[i].second == y) return 0;
    }
    return 1;
}

void modify(deque<pair<int, int> > &snake) {
    int n = snake.size();
    REPP(i, 1, n - 1) {
        snake[i].first -= snake[0].first;
        snake[i].second -= snake[0].second;
    }
    snake[0] = make_pair(0, 0);
}

deque<pair<int, int> > q;
void dfs(int now, int x, int y) {
    if (now > 8) return ;
   g[x + 10][y + 10] = 1;
    deque<pair<int, int> > tmp = q;
    modify(tmp);
    shape[now][tmp] = cnt[now]++;
    REP(i, 4) {
        int tx = x + dx[i], ty = y + dy[i];
        if (!g[tx + 10][ty + 10]) {
            q.push_front(make_pair(tx, ty));
            dfs(now + 1, tx, ty);
            q.pop_front();
        }
    }
    g[x + 10][y + 10] = 0;
}

int getShape(deque<pair<int, int> > snake) {
    modify(snake);
    return shape[snake.size()][snake];
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int ca = 1;
    dfs(1, 0, 0);
    //A001411 1, 4, 12, 36, 100, 284, 780, 2172 
    //REPP(i, 1, 8) {
    //    cout << cnt[i] << endl;
    //}
    while (scanf("%d%d%d", &n, &m, &l), n | m | l) {
        REPP(i, 1, n) REPP(j, 1, m) mp[i][j] = 0;
        deque<pair<int, int> > snake;
        int sx, sy;
        REP(i, l) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (i == 0) sx = x, sy = y;
            snake.push_back(make_pair(x, y));
        }
        scanf("%d", &k);
        REP(i, k) {
            int x, y;
            scanf("%d%d", &x, &y);
            mp[x][y] = 1;
        }
        REP(i, cnt[l]) {
            REPP(j, 1, n) {
                REPP(k, 1, m) {
                    dp[i][j][k] = -1;
                }
            }
        }
        int ans = -1;
        queue<deque<pair<int, int> > > q;
        q.push(snake), dp[getShape(snake)][sx][sy] = 0;
        if (sx == 1 && sy == 1) {
            printf("Case %d: 0\n", ca++);
            continue;
        }
        int find = 0;
        while (q.size()) {
            deque<pair<int, int> > now = q.front(), tmp;
            q.pop();
            int x, y, a = getShape(tmp);
            x = now[0].first, y = now[0].second;
            REP(i, 4) {
                tmp = now;
                int tx = x + dx[i], ty = y + dy[i];
                if (good(tx, ty, now)) {
                    //cout << tx << ' ' << ty << endl;
                    if (tx == 1 && ty == 1) {
                        ans = dp[a][x][y] + 1;
                        find = 1;
                        break;  
                    }
                    tmp.push_front(make_pair(tx, ty));
                    tmp.pop_back();
                    int b = getShape(tmp);
                    if (dp[b][tx][ty] >= 0) continue;
                    dp[b][tx][ty] = dp[a][x][y] + 1;
                    q.push(tmp);
                }
            }
            if (find) break;
        }
        printf("Case %d: %d\n", ca++, ans);
    }

    return 0;
}

