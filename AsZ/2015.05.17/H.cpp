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

const int N = 200;
bitset<N> can[N];
int mp[N][N], n;
bool vis[N];

void dfs(int x) {
    vis[x] = 1;
    can[x].reset();
    REP(i, n) if (mp[x][i]) {
        can[x].set(i);
        if (!vis[i]) dfs(i);
        can[x] |= can[i];
    }
}

void doIt() {
    int ans = 0;
    REP(i, n) {
        ans += can[i].count();
    }
    cout << ans << endl;
}

int main() {
    ios :: sync_with_stdio(0);
	freopen("settling.in", "r", stdin);
	freopen("settling.out", "w", stdout);
    int m;
    cin >> n >> m;
    REP(i, m) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        mp[x][y] = 1;
    }
    REP(i, n) if (!vis[i]) {
        dfs(i);
    }
    doIt();
    int q;
    cin >> q;
    while (q--) {
        string tmp;
        int x, y;
        cin >> tmp >> x >> y;
        x--, y--;
        REP(i, n) vis[i] = 0;
        if (tmp[0] == '?') {
            if (can[x].test(y)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else {
            if (tmp[0] == '-') {
                mp[x][y] = 0;
            }
            else {
                mp[x][y] = 1;
            }
            REP(i, n) if (!vis[i]) {
                dfs(i);
            }
            doIt();
        }
    }
    
    return 0;
}


