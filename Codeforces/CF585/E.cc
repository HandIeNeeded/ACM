#include <bits/stdc++.h>
#include <ext/hash_map>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;
using namespace __gnu_cxx;

const int M = 5e5 + 5;
const int N = 1e7 + 5;
const int L = 1e7;
const int MO = 1e9 + 7;
//at most 8 different prime factor, lead to 2^8 factors useful

int a[M], cnt[N], pw[N];
int p[N], vis[N], tot;
short mobius[N];
vector<int> use[M];
hash_map<int, int> mp;
 
void go(int num, vector<int> &b, int now, int dep = 0) {
    if (num == 1) {
        b.push_back(now);
        return ;
    }
    int fac = vis[num];
    while (num % fac == 0) num /= fac;
    go(num, b, now, dep + 1);
    go(num, b, now * fac, dep + 1);
}
 
void prime() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) p[tot++] = i, mobius[i] = -1, vis[i] = i;
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

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
    if (x < 0) x += MO;
}

int calc(int s, int num) {
    int ans = 0, x = mp[num];
    for (auto &y: use[x]) {
        if (y != 1) {
            add(s, mobius[y] * (pw[cnt[y]] - 1));
            add(s, -mobius[y] * (pw[cnt[y] - 1] - 1));
        }
    }
    for (auto &y: use[x]) {
        if (y == 1) add(ans, s);
        else {
            add(ans, mobius[y] * (pw[cnt[y] - 1] - 1));
        }
    }
    return ans;
}

void init() {
    REPP(i, 1, L) if(cnt[i]) {
        int id = mp[i];
        go(i, use[id], 1, 0);
    }
}

int main() {
    prime();
    pw[0] = 1;
    REPP(i, 1, L) pw[i] = 2LL * pw[i - 1] % MO;
    int n;
    scanf("%d", &n);
    REPP(i, 1, n) {
        scanf("%d", a + i);
        cnt[a[i]]++;
    }
    int now = 0;
    REPP(i, 1, L) if (cnt[i]) mp[i] = now++;
    init();
    REPP(i, 1, L) {
        for (int j = i + i; j <= L; j += i) {
            cnt[i] += cnt[j];
        }
    }
    int sum = 0;
    REPP(i, 2, L) if (mobius[i]) add(sum, mobius[i] * (pw[cnt[i]] - 1));
    sum = MO - sum;
    int ans = 0;
    REPP(i, 1, n) {
        add(ans, calc(sum, a[i]));
    }
    printf("%d\n", ans);
    return 0;
}
