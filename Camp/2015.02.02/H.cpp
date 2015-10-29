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

const int N = 1e5 + 5;
int suffix[N], a[N];
int mx[17][N], s[17][N];
int LL[16][N], RR[16][N], n;
int ql, qr;

void init() {
    REP(j, 16) LL[j][0] = 0, RR[j][n + 1] = n + 1;
    REP(j, 16) {
        REPP(i, 1, n) {
            if (a[i] & (1 << j)) LL[j][i] = i;
            else LL[j][i] = max(LL[j][i - 1], 1);
        }
    }
    REP(j, 16) {
        for (int i = n; i >= 1; i--) {
            if (a[i] & (1 << j)) RR[j][i] = i;
            else RR[j][i] = min(RR[j][i + 1], n);
        }
    }
    REPP(i, 1, n) mx[0][i] = a[i], s[0][i] = a[i];
    REPP(j, 1, 16) {
        REPP(i, 1, n) {
            mx[j][i] = max(mx[j - 1][i], mx[j - 1][i + (1 << (j - 1))]);
            s[j][i] = s[j - 1][i] | s[j - 1][i + (1 << (j - 1))];
        }
    }
}

void update(int x) {
    REP(a, 16) {
        REP(b, 16) {
            int length = RR[b][x] - LL[a][x] + 1;
            int bit = 31 - __builtin_clz(length);
            int p = max(mx[bit][LL[a][x]], mx[bit][RR[b][x] - (1 << bit) + 1]);
            int q = s[bit][LL[a][x]] | s[bit][RR[b][x] - (1 << bit) + 1];
            suffix[length] = max(suffix[length], p + q);
        }
    }
}

int main() {
    ios :: sync_with_stdio(0);
    cin >> n;
    REPP(i, 1, n) cin >> a[i];
    init();
    REPP(i, 1, n) update(i);
    REPP(i, 1, n) {
        suffix[i] = max(suffix[i], suffix[i - 1]);
        cout << suffix[i] << " \n"[i == n];
    }

    return 0;
}
