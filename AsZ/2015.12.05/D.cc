#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 5000;
vector<int> sum[N];
int n;

int get(int x) {
    int ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

void init() {
    int pre = 0;
    REPP(i, 1, 1e7) {
        int digit;
        if (i % 10 == 0) {
            digit = get(i);
        }
        else digit = pre + 1;
        if (int(sum[digit].size()) < n) sum[digit].push_back(i);
        pre = digit;
    }
}

LL getSum(int x) {
    LL ans = 0;
    REP(i, n) ans += sum[x][i];
    return ans;
}

int main() {
    freopen("digits.in", "r", stdin);
#ifndef HOME
    freopen("digits.out", "w", stdout);
#endif


    cin >> n;
    init();
    LL ans = LLONG_MAX;
    REP(i, N) {
        if (sum[i].size() == n) {
            ans = min(ans, getSum(i));
        }
    }
    cout << ans << endl;
    return 0;
}


