#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int MO = 1e9 + 7;
const int N = 1e7 + 5;
const int M = 5e5 + 5;
int cnt[N], f[N], pw[N];
int p[N], vis[N], tot;
short mobius[N];
vector<int> use[N];
 
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
    use[1].push_back(1);
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

int pow_mod(int a, int b, int mod = MO) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1LL * ans * a % mod;
        b >>= 1;
        a = 1LL * a * a % mod;
    }
    return ans;
}

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
    if (x < 0) x += MO;
}

int calc(int s, int x) {
    int ans = 0;
    for (auto &y: use[x]) {
        //cout << x << ' ' << y << ' ' << f[y] << endl;
        if (y != 1) {
            add(s, mobius[y] * (pw[f[y]] - 1));
            add(s, -mobius[y] * (pw[f[y] - 1] - 1));
        }
    }
    //cout << "s: " << s << endl;
    for (auto &y: use[x]) {
        if (y == 1) add(ans, s);
        else {
            add(ans, mobius[y] * (pw[f[y] - 1] - 1));
        }
    }
    return ans;
}

void init() {
    REPP(i, 2, 10000000) if(cnt[i]) {
        go(i, use[i], 1, 0);
    }
}

int main() {
    prime();
    pw[0] = 1;
    REPP(i, 1, 10000000) pw[i] = 2LL * pw[i - 1] % MO;
    int n;
    scanf("%d", &n);
    REPP(i, 1, n) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    init();
    for (int i = 10000000; i >= 1; i--) {
        f[i] = cnt[i];
        for (int j = i + i; j <= 10000000; j += i) {
            f[i] += cnt[j];
        }
    }
    int sum = 0;
    REPP(i, 2, 10000000) if (mobius[i]) add(sum, mobius[i] * (pw[f[i]] - 1));
    sum = MO - sum;
    //cout << sum << "hehe" << endl;
    int ans = 0;
    REPP(i, 1, 10000000) if (cnt[i]) {
        int tmp = 1LL * cnt[i] * calc(sum, i) % MO;
        add(ans, tmp);
    }
    printf("%d\n", ans);
    return 0;
}
