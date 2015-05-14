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

const int N = 3005;
int step[N], cost[N], n, talk;

bool check(LL tot) {
    REPP(i, 1, n) step[i] = 0;
    int person = 2;
    REPP(i, 1, n) if (i == 1 || step[i]) {
        LL turn = (tot - 1LL * step[i] * talk - cost[i]) / talk;
        int now = step[i];
        int lim = min(1LL * n, turn);
        REP(j, lim) {
            step[person++] = ++now;
            if (person > n) break;
        }
        step[i] = now;
        if (person > n) break;
    }
    REPP(i, 1, n) if ((step[i] == 0 && i > 1) || 1LL * step[i] * talk + cost[i] > tot) return 0;
    return 1;
}

int main() {
    ios :: sync_with_stdio(0);
    //freopen("C.in", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> talk;
        REPP(i, 1, n) cin >> cost[i];
        sort(cost + 1, cost + n + 1);
        reverse(cost + 1, cost + n + 1);
        LL lo = 0, hi = 1e15;
        while (lo + 1 < hi) {
            LL mid = (lo + hi) >> 1;
            if (check(mid)) hi = mid;
            else lo = mid;
        }
        cout << hi << endl;
    }

    return 0;
}


