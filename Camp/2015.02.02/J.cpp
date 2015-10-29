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

const int N = 1005;
const int L = 1e6;
int pos[N], mp[N][N], vis[N], pre[N], n, now;
bool nouse[N];

int get(int a, int cover, int dir) { //Left 0, Right 1
    if (dir) {
        return a + L - cover;
    }
    else {
        return a - L + cover;
    }
}

int getcover(int i, int j) {
    if (pos[i] > pos[j]) swap(i, j);
    if (pos[j] > pos[i] + L) return 0;
    return pos[i] + L - pos[j];
}

int getpos(int x, int y, int z) {
    pos[z] = get(pos[y], mp[y][z], 0);
    if (getcover(z, x) == mp[z][x]) return 1;
    pos[z] = get(pos[y], mp[y][z], 1);
    if (getcover(z, x) == mp[z][x]) return 1;
    return 0;
}

vector<int> candidate;

void dfs(int x, int p) {
    vis[x] = now;
    pre[x] = p;
    candidate.push_back(x);
    REPP(i, 1, n) if (mp[x][i] && !vis[i] && !nouse[i]) {
        dfs(i, x);
    }
}

bool check() {
    int n = candidate.size();
    REP(i, n) {
        REPP(j, i + 1, n - 1) {
            int x = candidate[i], y = candidate[j];
            if (getcover(x, y) != mp[x][y]) return 0;
        }
    }
    return 1;
}

bool isequal(int x, int y) {
    REPP(i, 1, n) {
        if (mp[x][i] != mp[y][i]) return 0;
    }
    return 1;
}

bool prepare() {
    int n = candidate.size();
    REP(i, n) if (!nouse[candidate[i]]) {
        REPP(j, i + 1, n - 1) if (!nouse[candidate[j]]) {
            int x = candidate[i], y = candidate[j];
            if (mp[x][y] == L) {
                if (!isequal(x, y)) {
                    //cout << x << ' ' << y << "hehe" << endl;
                    return 0;
                }
                else {
                    nouse[y] = 1;
                }
            }
        }
    }
    int x = candidate[0];
    REP(i, n) vis[candidate[i]] = 0;
    candidate.clear();
    dfs(x, 0);
    return 1;
}

int main() {
    ios :: sync_with_stdio(0);
    //freopen("J.in", "r", stdin);
    cin >> n;
    REPP(i, 1, n) {
        REPP(j, 1, n) {
            cin >> mp[i][j];
        }
    }
    bool ans = 1;
    REPP(i, 1, n) if (!vis[i]) {
        now++;
        candidate.clear();
        dfs(i, 0);
        ans &= prepare();
        if (candidate.size() <= 2) continue;
        else {
            int x = candidate[0], y = candidate[1];
            pos[x] = 0, pos[y] = get(pos[x], mp[x][y], 0);
            bool can = 1;
            REPP(i, 2, candidate.size() - 1) {
                int y = pre[candidate[i]];
                int x = pre[y];
                if (y == candidate[0]) x = candidate[1];
                can &= getpos(x, y, candidate[i]);
            }
            if (can && check()) continue;
            can = 1;
            pos[x] = 0, pos[y] = get(pos[x], mp[x][y], 1);
            REPP(i, 2, candidate.size() - 1) {
                int y = pre[candidate[i]];
                int x = pre[y];
                if (y == candidate[0]) x = candidate[1];
                can &= getpos(x, y, candidate[i]);
            }
            if (can && check()) continue;
            ans = 0;
            break;
        }
        if (!ans) break;
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}


