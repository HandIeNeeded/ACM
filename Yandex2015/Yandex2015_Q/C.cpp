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

const int N = 1e5 + 5;
vector<int> d[N];
int a[N], n;
int stamp[N];

struct Q{
    LL val;
    int id, clk;
}p[N];

struct cmp{
    bool operator () (Q i, Q j) {
        return i.val < j.val;
    }
};

priority_queue<Q, vector<Q>, cmp> q;

LL calc(int x) {
    LL ans = 0;
    REP(i, n) {
        ans += 1LL * a[i] * d[x][i];
    }
    return ans;
}

int main() {
    //freopen("C.in", "r", stdin);
    ios :: sync_with_stdio(0);
    cin >> n;
    REP(i, n) cin >> a[i];
    int m;
    cin >> m;
    REP(i, m) {
        REP(j, n) {
            int x;
            cin >> x;
            d[i].push_back(x);
        }
        p[i].val = calc(i);
        p[i].id = i, p[i].clk = 0;
        q.push(p[i]);
    }
    int q;
    cin >> q;
    REP(i, q) {
        int ty;
        cin >> ty;
        if (ty == 1) {
            int x;
            cin >> x;
            vector<Q> tmp;
            REP(i, x) {
                Q y = ::q.top();
                if (y.clk == stamp[y.id]) {
                    tmp.push_back(y);
                }
                else i--;
                ::q.pop();
            }
            REP(i, x) ::q.push(tmp[i]);
            REP(i, x) {
                cout << tmp[i].id + 1 << " \n"[i == x - 1];
            }
        }
        else {
            int x, y, z;
            cin >> x >> y >> z;
            p[x - 1].val += 1LL * (z - d[x - 1][y - 1]) * a[y - 1];
            d[x - 1][y - 1] = z;
            p[x - 1].clk++, stamp[x - 1] = p[x -1 ].clk;
            ::q.push(p[x - 1]);
        }
    }

    return 0;
}


