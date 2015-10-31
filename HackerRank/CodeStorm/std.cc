#include <bits/stdc++.h>
using namespace std;

#define repu(i, a, b) for (int i = (a); i < (b); ++i)
#define repd(i, a, b) for (int i = (a); i > (b); --i)
#define mem(a, x) memset(a, x, sizeof(a))
#define all(a) a.begin(), a.end()
#define uni(a) a.erase(unique(all(a)), a.end())
#define count_bits(x) __builtin_popcount(x)

typedef long long ll;
const int MOD = 1000000007;

template<class T> inline T tmin(T a, T b) {return (a < b) ? a : b;}
template<class T> inline T tmax(T a, T b) {return (a > b) ? a : b;}
template<class T> inline void amax(T &a, T b) {if (b > a) a = b;}
template<class T> inline void amin(T &a, T b) {if (b < a) a = b;}
template<class T> inline T tabs(T a) {return (a > 0) ? a : -a;}
template<class T> T gcd(T a, T b) {while (b != 0) {T c = a; a = b; b = c % b;} return a;}

const int N = 1000001;
int g[N], cnt[N][4], f[4];

ll mod_pow(ll x, int n) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}

int grundy(int n) {
    if (g[n] != -1) return g[n];
    string st = to_string(n), tmp;
    set<int> s;
    repu(i, 0, st.size() - 1) {
        char c = (st[i] + st[i + 1] - 2 * '0') % 10 + '0';
        if (c == '0' && i == 0) tmp = (i + 2 < st.size()) ? st.substr(i + 2) : "";
        else tmp = (i ? st.substr(0, i) : "") + c + ((i + 2 < st.size()) ? st.substr(i + 2) : "");
        int x = atoi(tmp.c_str());
        s.insert(grundy(x));
    }
    int ret = 0;
    while (s.count(ret) != 0) ret++;
    return (g[n] = ret);
}

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	
	int ntest, n, m, a;
	
    mem(g, -1);
    repu(i, 1, 10) {
        repu(j, 0, 4) cnt[i][j] = cnt[i - 1][j];
        cnt[i][g[i] = 0]++;
    }
    repu(i, 10, N) {
        repu(j, 0, 4) cnt[i][j] = cnt[i - 1][j];
        cnt[i][grundy(i)]++;
    }
    
    cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    
	cin >> ntest;
	while (ntest--) {
		cin >> n >> m;
        repu(i, 0, 4) f[i] = cnt[n][i];
        int x = 0;
        repu(i, 0, m) {
            cin >> a;
            x ^= g[a], f[g[a]]--;
        }
        
        ll ret = 0, t = mod_pow(2, f[0]);
        if (x == 0) {
            ret += mod_pow(2, max(0, f[1] - 1) + max(0, f[2] - 1) + max(0, f[3] - 1)) % MOD;
            if (f[1] && f[2] && f[3]) ret += mod_pow(2, f[1] + f[2] + f[3] - 3) % MOD;
            ret = ret * t % MOD;
            ret -= 1;
        }
        else if (x == 1) {
            if (f[2] && f[3]) ret += mod_pow(2, max(0, f[1] - 1) + f[2] - 1 + f[3] - 1) % MOD;
            if (f[1]) ret += mod_pow(2, f[1] - 1 + max(0, f[2] - 1) + max(0, f[3] - 1)) % MOD;
            ret = ret * t % MOD;
        }
        else if (x == 2) {
            if (f[1] && f[3]) ret += mod_pow(2, f[1] - 1 + max(0, f[2] - 1) + f[3] - 1) % MOD;
            if (f[2]) ret += mod_pow(2, max(0, f[1] - 1) + f[2] - 1 + max(0, f[3] - 1)) % MOD;
            ret = ret * t % MOD;
        }
        else {
            if (f[1] && f[2]) ret += mod_pow(2, f[1] - 1 + f[2] - 1 + max(0, f[3] - 1)) % MOD;
            if (f[3]) ret += mod_pow(2, max(0, f[1] - 1) + max(0, f[2] - 1) + f[3] - 1) % MOD;
            ret = ret * t % MOD;
        }
        printf("%lld\n", ret);
	}
	
	return 0;
}
