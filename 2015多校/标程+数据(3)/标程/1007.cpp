#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100000+5;
const int Mod = 998244353;

int pow_mod(int x, int n) {
    int ret = 1;
    while(n) {
        if(n&1) ret = 1ll*ret*x%Mod;
        x = 1ll*x*x%Mod;
        n >>= 1;
    }
    return ret;
}

int Top, m1[N<<3], m2[N<<3];

void NTT(int *a, int n, int rev) {
    for(int i = 1, j = 0;i < n; i++) {
        for(int k = n>>1;k > (j^=k); k >>= 1) ;
        if(i < j) swap(a[i], a[j]);
    }
    for(int i = 0;i < n; i++) m2[i] = m1[i*(Top/n)];
    for(int m = 2;m <= n; m <<= 1) {
        int wm = rev==1 ? n-n/m : n/m;
        for(int i = 0;i < n; i += m) {
            int w = 0;
            for(int j = i;j < i+m/2; j++) {
                int t = 1ll*m2[w]*a[j+m/2]%Mod;
                a[j+m/2] = a[j]-t;
                if(a[j+m/2] < 0) a[j+m/2] += Mod;
                a[j] = a[j]+t;
                if(a[j] >= Mod) a[j] -= Mod;
                w += wm;
                if(w >= n) w -= n;
            }
        }
    }
    if(rev == -1) {
        int inv = pow_mod(n, Mod-2);
        for(int i = 0;i < n; i++) a[i] = 1ll*a[i]*inv%Mod;
    }
}

int dp[N], a[N<<3], b[N<<3];
int fac[N], ff[N];

inline void Add(int &x, int y) {
    x += y;
    if(x >= Mod) x -= Mod;
}

void solve(int l, int r) {
    if(l == r) {
        return ;
    }
    int mid = l+r>>1;
    solve(l, mid);
    int len = r-l+1;
    int n = 1;
    while(n <= 2*len) n <<= 1;
    for(int i = 0;i < n; i++) {
        a[i] = b[i] = 0;
        if(i < n/2) b[i] = 1ll*i*i%Mod;
    }
    for(int i = l;i <= mid; i++) {
        a[i-l+1] = 1ll*dp[i]*ff[i]%Mod;
    }
    NTT(a, n, 1); NTT(b, n, 1);
    for(int i = 0;i < n; i++) a[i] = 1ll*a[i]*b[i]%Mod;
    NTT(a, n, -1);
    for(int i = mid+1;i <= r; i++) {
        Add(dp[i], 1ll*a[i-l+1]*fac[i-1]%Mod);
    }
    solve(mid+1, r);
}

void init(int n) {
    fac[0] = ff[0] = 1;
    for(int i = 1;i <= n; i++) {
        fac[i] = 1ll*fac[i-1]*i%Mod;
        ff[i] = pow_mod(fac[i], Mod-2);
    }

    int maxn = 1;
    while(maxn <= 2*n) maxn <<= 1;
    Top = maxn;
    m1[0] = 1; m1[1] = pow_mod(3, (Mod-1)/Top);
    for(int i = 2;i < Top; i++) {
        m1[i] = 1ll*m1[i-1]*m1[1]%Mod;
    }
    dp[0] = 1;
    solve(0, n);
//    for(int i = 1;i <= 10; i++) printf("dp[%d] = %d\n", i, dp[i]);
}

int main() {
    init(100000);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    while(scanf("%d", &n) == 1) {
        printf("%d\n", dp[n]);
    }
    return 0;
}
