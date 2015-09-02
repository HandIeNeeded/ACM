#include <cstdio>
#include <cstring>
#include <algorithm>
#include <assert.h>
using namespace std;
typedef long long ll;

const int N = 100000+5;
const int Mod = 258280327;
int pri[N], mu[N], pnum;
bool vis[N];
int fac[N], ff[N], pow2[N];

void mobius(int n) {
    mu[1] = 1;
    for(int i = 2;i <= n; i++) {
        if(!vis[i]) {
            mu[i] = -1;
            pri[pnum++] = i;
        }
        for(int j = 0;j < pnum; j++) {
            if(i*pri[j] > n) break;
            vis[i*pri[j]] = 1;
            if(i%pri[j] == 0) {
                mu[i*pri[j]] = 0;
                break;
            }
            mu[i*pri[j]] = -mu[i];
        }
    }
}

int pow_mod(int x, int n) {
    int ret = 1;
    while(n) {
        if(n&1) ret = 1ll*ret*x%Mod;
        x = 1ll*x*x%Mod;
        n >>= 1;
    }
    return ret;
}

void init(int n) {
    fac[0] = ff[0] = pow2[0] = 1;
    for(int i = 1;i <= n; i++) {
        fac[i] = 1ll*fac[i-1]*i%Mod;
        ff[i] = pow_mod(fac[i], Mod-2);
        pow2[i] = pow2[i-1]*2%Mod;
    }
}

int q1[N], q2[N], cnt[N], a[N], n;

inline void Add(int &x, int y) {
    x += y;
    if(x >= Mod) x -= Mod;
    else if(x < 0) x += Mod;
}

void solve() {
    int mx = 0;
    for(int i = 1;i <= n; i++) mx = max(mx, a[i]);
    for(int i = 1;i <= mx; i++) cnt[i] = 0;
    for(int i = 1;i <= n; i++) cnt[a[i]]++;
    for(int i = 1;i <= mx; i++) {
        int sum = 0;
        for(int j = i;j <= mx;j += i) {
            sum += cnt[j];
        }
        q1[i] = q2[i] = 0;
        if(sum==0) continue;
        for(int j = 1;j <= sum; j++) {
            Add(q1[i], 1ll*fac[n-j+1]*ff[sum-j]%Mod);
        }
        q1[i] = 1ll*q1[i]*fac[sum]%Mod;
        q2[i] = 1ll*sum*pow2[sum-1]%Mod;
    }
    int ans1 = 0, ans2 = 0;
    for(int i = 1;i <= mx; i++) {
        int cur1 = 0, cur2 = 0;
        for(int j = i;j <= mx;j += i) if(mu[j/i]) {
            Add(cur1, 1ll*q1[j]*mu[j/i]%Mod);
            Add(cur2, 1ll*q2[j]*mu[j/i]%Mod);
        }
        Add(ans1, 1ll*cur1*i%Mod); Add(ans2, 1ll*cur2*i%Mod);
    }
//    printf("ans1 = %d ans2 = %d\n", ans1, ans2);
    if(ans1 == ans2) printf("Equal %d\n", ans1);
    else if(ans1 > ans2) printf("Mr. Zstu %d\n", ans1);
    else    printf("Mr. Hdu %d\n", ans2);
}


int main() {
    mobius(100000);
    init(100000);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(scanf("%d", &n) == 1) {
        assert(n >= 1 && n <= 100000);
        for(int i = 1;i <= n; i++) {
            scanf("%d", &a[i]);
            assert(a[i] >= 1 && a[i] <= 100000);
        }
        solve();
    }
    return 0;
}

