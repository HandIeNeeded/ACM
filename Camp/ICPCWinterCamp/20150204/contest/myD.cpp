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

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 2e5 + 5;

struct Segment{
    int x, y, dir;
    bool operator < (const Segment &rhs) const {
        return x < rhs.x || (x == rhs.x && dir < rhs.dir) || (x == rhs.x && dir == rhs.dir && dir == 0 && y < rhs.y) || (x == rhs.x && dir == rhs.dir && dir == 1 && y > rhs.y);
    }
}p[N << 1];

int mx[N << 2];
int ql, qr, qx, qd;

void modify(int x, int l, int r) {
    if (l == r) {
        mx[x] = max(mx[x], qd);
    }
    else {
        if (qx <= MID) modify(LC);
        else modify(RC);
        mx[x] = max(mx[L], mx[R]);
    }
}

int query(int x, int l, int r) {
    if (ql <= l && qr >= r) {
        return mx[x];
    }
    else {
        int ans = 0;
        if (ql <= MID) ans = max(ans, query(LC));
        if (qr > MID) ans = max(ans, query(RC));
        return ans;
    }
}

int main() {
    freopen("D.in", "r", stdin);
    ios :: sync_with_stdio(0);
    int tot = 0;
    int n;
    cin >> n;
    REPP(i, 1, n) {
        char s[5];
        int a, b, x, y, sum = i - 1;
        cin >> s >> a >> b;
        if (s[0] == 'A') {
            if (a <= sum) {
                x = a, y = sum - a;
                p[tot++] = {x, y, 1};
            }
            if (b <= sum) {
                x = b, y = sum - b;
                p[tot++] = {x, y, 0};
            }
        }
        else {
            if (a <= sum) {
                x = sum - a, y = a;
                p[tot++] = {x, y, 1};
            }
            if (b <= sum) {
                x = sum - b, y = b;
                p[tot++] = {x, y, 0};
            }
        }
    }
    sort(p, p + tot);
    //REP(i, tot) {
    //    cout << p[i].x << ' ' << p[i].y << ' ' << p[i].dir << endl;
    //}
    REP(i, tot) {
        int y = p[i].y, dir = p[i].dir;
        //cout << y << ' ' << dir << endl;
        if (dir == 0) {
            ql = 1, qr = y + 1;
            qx = y + 2, qd = query(1, 1, n + 1) + 1;
            modify(1, 1, n + 1);
        }
        else {
            ql = 1, qr = y + 1;
            qx = y + 1, qd = query(1, 1, n + 1) + 1;
            modify(1, 1, n + 1);
        }
    }
    cout << mx[1] << endl;
    return 0;
}



