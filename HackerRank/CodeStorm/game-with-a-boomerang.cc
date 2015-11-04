#include <bits/stdc++.h>
#include <ext/hash_map>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;
using namespace __gnu_cxx;

struct myhash{
    inline unsigned LL operator () (LL a) const {
        return a;
    }
};

//hash_map<LL, LL, myhash> mp;

LL solve(LL n) {
    if (n <= 2) return 1;
    //if (mp.count(n)) return mp[n];
    if (n & 1) {
        return solve(n - 1) + 1;
        //return mp[n] = solve(n - 1) + 1;
    }
    else {
        LL k = n / 2;
        LL tmp = solve(k);
        if (k & 1) {
            LL ans = k + 2 * tmp;
            if (ans >= n) ans -= n;
            //return mp[n] = ans;
            return ans;
        }
        else {
            LL ans = -1;
            if (tmp <= k / 2) {
                ans = k + 2 * tmp;
            }
            else {
                tmp -= k / 2;
                ans = 2 * tmp - 1;
            }
            //return mp[n] = ans;
            return ans;
        }
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        LL n;
        scanf("%lld", &n);
        printf("%lld\n", solve(n));
    }

    return 0;
}


