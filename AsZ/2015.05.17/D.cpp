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
#define LL long long

using namespace std;

const int N = 59049; //3**10

int cnt[10];

int get() {
    int ans = 0;
    REP(i, 10) {
        ans = 3 * ans + cnt[i];
    }
    return ans;
}

void getcnt(int x) {
    REP(i, 10) {
        cnt[9 - i] = x % 3;
        x /= 3;
    }
}

int mp[N][10];
int bit[20];
LL dp[20][2][N];
bool vis[20][2][N];

LL dfs(int dep, int flag, int first, int st) {
    if (dep < 0) return 1;
    else if (flag && vis[dep][first][st]) return dp[dep][first][st];
    else {
        if (flag) {
            vis[dep][first][st] = 1;
            LL &ans = dp[dep][first][st];
            ans = 0;
            if (first) {
                REP(bit, 10) if (mp[st][bit] >= 0) {
                    ans += dfs(dep - 1, flag, first, mp[st][bit]);
                }
            }
            else {
                REP(bit, 10) if (mp[st][bit] >= 0) {
                    ans += dfs(dep - 1, flag, bit > 0, bit ? mp[st][bit] : st);
                }
            }
            return ans;
        }
        else {
            LL ans = 0;
            if (!first) {
                REP(bit, ::bit[dep] + 1) if (mp[st][bit] >= 0) {
                    ans += dfs(dep - 1, bit < ::bit[dep], bit > 0, bit ? mp[st][bit] : st);
                }
            }
            else {
                REP(bit, :: bit[dep] + 1) if (mp[st][bit] >= 0) {
                    ans += dfs(dep - 1, bit < ::bit[dep], first, mp[st][bit]);
                }
            }
            return ans;
        }
    }
}

LL go(LL x) {
    if (x == 0) return 1;
    int len = 0;
    while (x) {
        bit[len++] = x % 10;
        x /= 10;
    }
    return dfs(len - 1, 0, 0, N - 1);
}

void init() {
    REP(i, N) {
        getcnt(i);
        REP(j, 10) {
            if (cnt[j]) {
                cnt[j]--;
                mp[i][j] = get();
                cnt[j]++;
            }
            else mp[i][j] = -1;
        }
    }
}

int main() {
    ios :: sync_with_stdio(0);
    freopen("exchange.in", "r", stdin);
    freopen("exchange.out", "w", stdout);
    init();
    LL l, r;
    //cout << go(110) << endl;
    cin >> l >> r;
    //cout << go(l - 1) << ' ' << go(r) << endl;
    cout << go(r) - go(l - 1) << endl;

    return 0;
}

 
