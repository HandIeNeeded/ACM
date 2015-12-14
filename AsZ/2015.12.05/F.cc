#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define ALL(a) (a).begin(), (a).end()

using namespace std;

const int N = 1e5 + 5;
int a[N], dp[N];
vector<int> num;

int main() {
    freopen("fragmentation.in", "r", stdin);
#ifndef HOME
    freopen("fragmentation.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    REPP(i, 1, n) {
        scanf("%d", a + i);
        num.push_back(a[i]);
    }
    sort(ALL(num));
    num.resize(unique(ALL(num)) - num.begin());
    REPP(i, 1, n) a[i] = lower_bound(ALL(num), a[i]) - num.begin() + 1;
    



    return 0;
}


