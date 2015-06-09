#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const string str = "^>v<.";
const int N = 105;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

char mp[N][N];
int vis[N][N], ans;
int n, m;

bool good(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

bool check(int i, int j) {
    int x, y;
    bool bad = 1;
    REP(d, 4) {
        x = i, y = j;
        while (good(x + dx[d], y + dy[d])) {
            x += dx[d], y += dy[d];
            if (str.find(mp[x][y]) < 4) {
                return 0;
            }
        }
    }
    return bad;
}

void dfs(int x, int y, int d) {
    if (vis[x][y] && str.find(mp[x][y]) < 4) return ;
    vis[x][y] = 1;
    int tx = x + dx[d], ty = y + dy[d];
    if (good(tx, ty)) {
        int tmp = str.find(mp[tx][ty]);
        if (tmp != 4) d = tmp;
        dfs(tx, ty, d);
    }
    else {
        ans++;
    }
}

int main() {
    ios :: sync_with_stdio(0);
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int t, ca = 1;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        REPP(i, 1, n) {
            cin >> mp[i] + 1;
        }
        ans = 0;
        REPP(i, 1, n) {
            REPP(j, 1, m) {
                vis[i][j] = 0;
            }
        }
        int bad = 0;
        REPP(i, 1, n) {
            REPP(j, 1, m) {
                if (str.find(mp[i][j]) != 4 && check(i, j)) {
                    bad = 1;
                    break;
                }
            }
            if (bad) break;
        }
        cout << "Case #" << ca++ << ": ";
        if (bad) {
            cout << "IMPOSSIBLE" << endl;
        }
        else {
            REPP(i, 1, n) {
                int d;
                REPP(j, 1, m) if (!vis[i][j] && (d = str.find(mp[i][j])) != 4) {
                    dfs(i, j, d);
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}
