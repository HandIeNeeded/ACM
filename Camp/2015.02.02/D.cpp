#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
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
#define LB(x) ((x) & (-(x)))

using namespace std;

const int N = 1e5 + 5;
const int MO = 1e9 + 7;
int p[N], vis[N], mobius[N] = {0, 1}, tot;

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
}

int s[N];

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
    if ( x < 0) x += MO;
}

void update(int x, int d) {
    while (x < N) {
        add(s[x], d);
        x += LB(x);
    }
}

int query(int x) {
    int ans = 0;
    while (x) {
        add(ans, s[x]);
        x -= LB(x);
    }
    return ans;
}

int sum(int x) {
    return 1LL * x * (x + 1) / 2 % MO;
}

struct Query{
    int a, n, m, id;
}Q[N];
int ans[N];

bool cmp(Query a, Query b) {
    return a.a < b.a;
}

int last;

int calc(int x) {
    int n = Q[x].n, m = Q[x].m, a = Q[x].a;
    REPP(i, last, a) {
        for (int j = i, k = 1; j < N; j += i, k++) {
            int tmp = 1LL * j * k % MO;
            update(j, mobius[k] * tmp);
        }
    }
    last = a + 1;
    if (n > m) swap(n, m);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int a = n / i, b = m / i;
        int pos1 = n / a, pos2 = m / b;
        int nextpos = min(pos1, pos2);
        int tmp = query(nextpos);
        add(tmp, MO - query(i - 1));
        add(ans, 1LL * sum(a) * sum(b) % MO * tmp % MO);
        i = nextpos;
    }
    return ans;
}

int main() {
    prime();
    int t;
    cin >> t;
    REPP(i, 1, t){
        int x, y, z;
        cin >> x >> y >> z;
        Q[i] = {z, x, y, i};
    }
    sort(Q + 1, Q + t + 1, cmp);
    last = 1;
    REPP(i, 1, t) {
        ans[Q[i].id] = calc(i);
    }
    REPP(i, 1, t) {
        cout << ans[i] << endl;
    }

    return 0;
}

