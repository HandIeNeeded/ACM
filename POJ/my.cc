#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 25;
const int M = (1 << 14) + 5;

int vis[N][N][M], mp[N][N], dp[N][N][M];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int n, m, l, k;

struct Node{
    int x, y, state;
    Node () {};
};

void ban(Node a, int x) {
    int nx = a.x, ny = a.y;
    mp[nx][ny] = x;
    REPP(i, 1, l - 1) {
        if (((a.state >> (2 * l - 2 - 2 * i)) & 3) == 0) ny++;
        if (((a.state >> (2 * l - 2 - 2 * i)) & 3) == 1) ny--;
        if (((a.state >> (2 * l - 2 - 2 * i)) & 3) == 2) nx++;
        if (((a.state >> (2 * l - 2 - 2 * i)) & 3) == 3) nx--;
        mp[nx][ny] = x;
    }
}

int dis(int x, int y) {
    return x - 1 + y - 1;
}

bool good(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && !mp[x][y];
}

struct cmp{
    bool operator () (const Node &a, const Node &b) {
        return dp[a.x][a.y][a.state] + dis(a.x, a.y) > dp[b.x][b.y][b.state] + dis(b.x, b.y);
    }
};

int main() {
#ifdef HOME
    freopen("tmp.in", "r", stdin);
#endif

    int ca = 1;
    while (scanf("%d%d%d", &n, &m, &l), n | m | l) {
        REPP(i, 1, n) REPP(j, 1, m) mp[i][j] = 0;
        Node start;
        start.state = 0;
        int x, y, px, py;
        REP(i, l) {
            scanf("%d%d", &x, &y);
            if (i == 0) start.x = x, start.y = y;
            else {
                if (px == x && py < y) start.state |= 0 << (2 * l - 2 - 2 * i);
                if (px == x && py > y) start.state |= 1 << (2 * l - 2 - 2 * i);
                if (px < x && py == y) start.state |= 2 << (2 * l - 2 - 2 * i);
                if (px > x && py == y) start.state |= 3 << (2 * l - 2 - 2 * i);
            }
            px = x, py = y;
        }
        scanf("%d", &k);
        REP(i, k) {
            scanf("%d%d", &x, &y);
            mp[x][y] = 1;
        }
        if (start.x == 1 && start.y == 1) {
            printf("Case %d: %d\n", ca++, 0);
            continue;
        }
        priority_queue<Node, vector<Node>, cmp> q;
        q.push(start);
        dp[start.x][start.y][start.state] = 0;
        int ans = -1;
        while (q.size()) {
            Node tmp = q.top(); q.pop();
            int x = tmp.x, y = tmp.y;
            //cout << x << ' ' << y << ' ' << tmp.state << endl;
            ban(tmp, 1);
            REP(i, 4) {
                int tx = x + dx[i], ty = y + dy[i];
                if (good(tx, ty)) {
                    if (tx == 1 && ty == 1) {
                        ans = dp[x][y][tmp.state] + 1;
                        break;
                    }
                    Node now;
                    now.x = tx, now.y = ty, now.state = tmp.state;
                    //cout << now.state << endl;
                    now.state >>= 2;
                    //cout << now.state << endl;
                    if (tx == x && ty < y) now.state |= 0 << (2 * l - 2 - 2 * 1);
                    if (tx == x && ty > y) now.state |= 1 << (2 * l - 2 - 2 * 1);
                    if (tx < x && ty == y) now.state |= 2 << (2 * l - 2 - 2 * 1);
                    if (tx > x && ty == y) now.state |= 3 << (2 * l - 2 - 2 * 1);
                    if (vis[tx][ty][now.state] == ca) continue;
                    vis[tx][ty][now.state] = ca;
                    dp[tx][ty][now.state] = dp[x][y][tmp.state] + 1;
                    q.push(now);
                    //cout << "tx ty: " << tx << ' ' << ty << ' ' << now.state << endl;
                }
            }
            //cout << "********************" << endl;
            if (ans >= 0) break;
            ban(tmp, 0);
        }
        printf("Case %d: %d\n", ca++, ans);
    }

    return 0;
}
