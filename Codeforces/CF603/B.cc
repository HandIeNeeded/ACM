#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int MO = 1e9 + 7;

int pow_mod(int a, int b, int mod = MO) {
    a %= mod; 
    if (a < 0) a += mod;
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1LL * ans * a % mod;
        b >>= 1;
        a = 1LL * a * a % mod;
    }
    return ans;
}

vector<int> factor;
int p, k;

int main() {
    ios::sync_with_stdio(0);

    cin >> p >> k;
    if (k == 0) {
        cout << pow_mod(p, p - 1) << endl;
    }
    else if (k == 1) {
        cout << pow_mod(p, p) << endl;
    }
    else if (k == p - 1) {
        cout << pow_mod(p, p / 2) << endl;
    }
    else {
        int now = 1;
        int cnt = 1;
        while (1LL * now * k % p != 1) {
            now = 1LL * now * k % p;
            cnt++;
        }
        assert(pow_mod(k, cnt, p) == 1);
        cout << pow_mod(p, (p - 1) / cnt) << endl;
    }
    return 0;
}


