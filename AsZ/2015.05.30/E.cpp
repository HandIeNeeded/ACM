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

const int N = 205;
const int C = 126 - 33 + 1;
const int L = 55;

struct AC_Automation{
    int tr[N * L][C], fail[N * L], sg[N * L], val[N * L][C];
    int node;

    int New_Node() {
        MST(tr[node], 0), MST(val[node], 0);
        fail[node] = 0;
        return node++;
    }

    void init() {
        node = 0;
        New_Node();
    }

    int get(char c) {
        return c - 33;
    }

    void insert(char *s) {
        int pos = 0, now = 0;
        while (s[pos]) {
            int x = get(s[pos++]);
            if (!tr[now][x]) {
                tr[now][x] = New_Node();
                val[now][x] = 1;
            }
            now = tr[now][x];
        }
    }

    void getfail() {
        queue<int> q;
        REP(i, C) {
            if (tr[0][i]) {
                q.push(tr[0][i]);
                fail[tr[0][i]] = 0;
            }
        }
        while (q.size()) {
            int x = q.front(); q.pop();
            REP(i, C) {
                if (!tr[x][i]) {
                    tr[x][i] = tr[fail[x]][i];
                    continue;
                }
                int y = tr[x][i];
                q.push(y);
                fail[y] = tr[fail[x]][i];
            }
        }
    }

    void dfs(int x = 0) {
        sg[x] = 0;
        bool vis[2 * C] = {0};
        REP(i, C) {
            if (val[x][i] > 0) {
                dfs(tr[x][i]);
                vis[sg[tr[x][i]]] = 1;
            }
        }
        int &ans = sg[x];
        while (vis[ans]) ans++;
    }
}AC;

char s[L];

int main() {
    ios :: sync_with_stdio(0);
    freopen("game.in", "r", stdin);
    //freopen("game.out", "w", stdout);
    int n;
    cin >> n;
    AC.init();
    REP(i, n) {
        cin >> s;
        AC.insert(s);
    }
    AC.getfail();
    AC.dfs();
    //cout << AC.node << endl;
    REP(i, AC.node) {
        cout << i << ' ' << AC.sg[i] << ' ' << endl;
    }
    if (AC.sg[0]) {
        cout << "First" << endl;
        REP(i, C) {
            if (!AC.sg[AC.tr[0][i]]) {
                cout << char(33 + i);
            }
        }
        cout << endl;
    }
    else {
        cout << "Second" << endl;
    }

    return 0;
}
