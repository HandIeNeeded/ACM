#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 1005;
const int M = 100005;
const int MOD = 1000000007;
int n , m;
int fac[M] , inv[M] , dp[N] , f[N];
inline int mut (int a , int b) {
    return 1LL * a * b % MOD;
}
inline int powmod (int a , int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = mut (ret , a);
        a = mut (a , a );
        b >>= 1;
    }
    return ret;
}
inline int binom (int n , int m) {
    return mut (fac[n] , mut (inv[m] , inv[n - m]));
}
inline void add (int &a , int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}
int main () {
    // freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);  
    int t , cas = 0;
    scanf ("%d" , &t);
    fac[0] = inv[0] = 1;
    for (int i = 1 ; i < M ; i ++) {
        fac[i] = mut (fac[i - 1] , i);
        inv[i] = powmod (fac[i] , MOD - 2);
    }
    while (t --) {
        scanf ("%d %d" , &n , &m);
        memset (f , 0 , sizeof (f));
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1 ; j <= i && j <= m ; j ++) {
                add (f[i] , mut (binom (m , j) , binom (i - j + j - 1 , j - 1)));
            }
        }

        memset (dp , 0 , sizeof (dp));
        dp[0] = 1;
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j + i + 1 <= n ; j ++) {
                add (dp[i + j + 1] , mut (dp[i] , mut (f[j + 1] , binom (n - i - 1 , j))));
            }
        }
        printf ("Case #%d: %d\n" , ++ cas , dp[n]);
    }
    return 0;
}
