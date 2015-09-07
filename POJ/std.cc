#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n, m, L;
bool vis[20][20][16500];
int p[20][20], x[10], y[10];
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

struct node{
    int x, y, sta, val;
    node(int _x, int _y, int _sta, int _val){
        x = _x; y = _y; sta = _sta; val = _val;
    }
    node(){}
};

void col(int x, int y, int sta, int val){
    p[x][y] = val;
    for (int i = L - 2; i >= 0; -- i){
        int ty = ((3 << (i * 2)) & sta) >> (i * 2);
        x += dx[ty];
        y += dy[ty];
        p[x][y] = val;
    }
}

int ok(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m && p[x][y] == 0;
}

queue<node> q;

void bfs(int sx, int sy, int start){
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            for (int k = 0; k < (1 << (2 * L - 2)); ++ k){
                vis[i][j][k] = 0;
            }
        }   
    }
    int ans = -1;
    while (!q.empty()) q.pop();
    q.push(node(sx, sy, start, 0));
    vis[sx][sy][start] = 1;
    while (!q.empty()){
        node k = q.front(); q.pop();
        // printf("%d %d\n", k.x + 1, k.y + 1);
        if (k.x == 0 && k.y == 0){
            ans = k.val;
            break;
        }
        col(k.x, k.y, k.sta, 1);
        for (int i = 0; i < 4; ++ i){
            int tx = k.x + dx[i];
            int ty = k.y + dy[i];
            if (ok(tx, ty)){
                int nxt = (k.sta >> 2) | ((i ^ 1) << (2 * L - 4));
                if (vis[tx][ty][nxt] == 0){
                    vis[tx][ty][nxt] = 1;
                    q.push(node(tx, ty, nxt, k.val + 1));
                }
            }
        }
        col(k.x, k.y, k.sta, 0);
    }
    printf("%d\n", ans);
}

int main(){
  //  freopen("in", "r", stdin);
    int _ = 0;
    while (scanf("%d%d%d", &n, &m, &L) != EOF){
        if (n == 0) continue;
        printf("Case %d: ", ++ _);
        memset(p, 0, sizeof(p));
        int sta = 0;
        for (int i = 0; i < L; ++ i){
            scanf("%d%d", &x[i], &y[i]); --x[i]; --y[i];
            if (i){
                sta <<= 2;
                for (int j = 0; j < 4; ++ j){
                    if (dx[j] + x[i-1] == x[i] && dy[j] + y[i-1] == y[i]){
                        sta += j;
                        break;
                    }
                }
            }
        }
        int block;
        scanf("%d", &block);
        for (int i = 0; i < block; ++ i){
            int x, y;
            scanf("%d%d", &x, &y); -- x; -- y;
            p[x][y] = 1;
        }
        bfs(x[0], y[0], sta);
    }
    return 0;
}
