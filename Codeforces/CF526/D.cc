#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e6 + 5;
char s[N];
int f[N], n, k;
string ans;

void getFail() {
    f[0] = f[1] = 0;
    for (int i = 1; i < n; i++) {
        int j = f[i];
        while (j && s[j] != s[i]) j = f[j];
        f[i + 1] = s[j] == s[i] ? j + 1 : 0;
    }
}

bool check(int pos) {
    pos++;
    int length = pos - f[pos];
    int remain = pos % length;
    int cnt = (pos - remain) / length;
    int a = cnt / k * length;
    int b = cnt % k * length + remain;
    return a >= b;
}

int main() {
    ios::sync_with_stdio(0);
#ifdef HOME
    //freopen("in", "r", stdin);
#endif
    cin >> n >> k >> s;
    getFail();
    REP(i, n) {
        ans += char('0' + check(i));
    }
    cout << ans << endl;
    return 0;
}
