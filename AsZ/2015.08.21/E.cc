#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

pair<int, int> getdigit(int x) { //get digit sum length
    int ans = 0, cnt = 0;
    if (x == 0) return make_pair(0, 1);
    while (x) {
        ans += x % 10;
        cnt++;
        x /= 10;
    }
    return  make_pair(ans, cnt);
}

int main() {
#ifdef HOME
    freopen("E.in", "r", stdin);
#endif

    int n, m;
    int ca = 1;
    while (scanf("%d%d", &n, &m), n >= 0) {
        int ans = n % 11;
        int sum, length;
        tie(sum, length) = getdigit(n);
        for (int i = 0; i < m; i++) {
            length = getdigit(sum).second;
            ans = ans * (length & 1 ? 10 : 1) + sum;
            ans %= 11;
            int tmps, tmpd;
            tie(tmps, tmpd) = getdigit(sum);
            sum += tmps;
        }
        printf("Case #%d: ", ca++);
        if (ans == 0) {
            puts("Yes");
        }
        else {
            puts("No");
        }
    }

    return 0;
}

