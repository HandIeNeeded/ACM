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
const int N = 5e4 + 5;
int vis[N], p[N], tot, mobius[N] = {0, 1};
int sum[N];

void prime() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) p[tot++] = i, mobius[i] = -1;
        for (int j = 0; j < tot && i * p[j] < N; j++) {
            vis[i * p[j]] = p[j];
            mobius[i * p[j]] = -mobius[i];
            if (i % p[j] == 0) {
                mobius[i * p[j]] = 0;
                break;
            }
        }
    }
    REPP(i, 1, N - 1) sum[i] = sum[i - 1] + mobius[i];
}

int cnt[15];

int main() {
    ios :: sync_with_stdio(0);
    prime();
    int t;
    cin >> t;
    REPP(i, 1, t) {
        int a, b, d;
        cin >> a >> b >> d;
        if (a > b) swap(a, b);
        long long ans = 0;
        for (int i = d; i <= a; i += d) {
            int x = a / i, y = b / i;
            int pa = a / x, pb = b / y;
            int nextpos = min(pa, pb);
            ans += 1LL * x * y * (sum[nextpos / d] - sum[(i - 1) / d]);
            i = nextpos / d * d;
        }
        cout << ans << endl;
    }

    return 0;
}

