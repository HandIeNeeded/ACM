#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 24 * 60 + 5;
const int cost[2] = {26, 28};
int stamp[N], type[N], dp[N], a[N], b[N], n;

int get1(int l, int r) {
    int in = 0, pre = 0, cnt = 0, ans = 0;
    memset(stamp, 0, sizeof(stamp));
    memset(type, 0, sizeof(type));
    REPP(i, l, r) {
        stamp[a[i]] = 1;
        type[a[i]] = b[i];
    }
    REP(i, N) {
        if (stamp[i]) {
            if (!in || i - pre > 90 || (in && cnt && type[i] == 1)) {
                ans += cost[type[i]];
                in = 1, pre = i;
                cnt = type[i];
            }
            else {
               if (in == 1) {
                   ans += 44 - cost[type[pre]];
               } 
               in++;
               cnt += type[i];
            }
        }
    }
    return ans;
}

void toMin(int &x, int y) {
    if (x > y) x = y;
}

int get2() {
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    a[0] = -100, b[0] = 0;
    REP(i, n) {
        dp[i + 1] = dp[i] + cost[b[i + 1]];
        for (int j = i; j > 0; j--) {
            if (a[i + 1] - a[j] > 90) break;
            toMin(dp[i + 1], dp[j - 1] + get1(j, i + 1));
        }
    }
    return dp[n];
}

int main() {
#ifdef HOME
    freopen("F.in", "r", stdin);
#endif

    cin >> n;
    REPP(i, 1, n) {
        int x, y;
        char c;
        scanf("%d:%d %c", &x, &y, &c);
        stamp[x * 60 + y] = 1, type[x * 60 + y] = c == 'U';
        a[i] = x * 60 + y, b[i] = type[a[i]];
    }
    cout << get1(1, n) << ' ' << get2() << endl;
    return 0;
}


