#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int MO = 1e9 + 7;
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
}

int main() {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    int ans = pow_mod(27, n);
    add(ans, MO - pow_mod(7, n));
    cout << ans << endl;
    return 0;
}


