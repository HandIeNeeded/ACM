#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 206;
string s, r;
char str[N];

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d%s", &n, str);
        s = string(str);
        r = "";
        int ans = 0;
        REP(i, n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            ans += (j - i - 1) / 2;
            r += string((j - i) & 1 ? 1 : 2, s[i]);
            i = j - 1;
        }
        //cout << r << endl;
        int good = 0;
        for (int i = 1; i < int(r.size()) - 1; i++) {
            if (r[i] != r[i - 1] && r[i] != r[i + 1]) {
                good = 1;
                break;
            }
        }
        if (good) {
            ans += (r.size() - (r.size() & 1 ? 1 : 2)) / 2;
        }
        printf("%d\n", 2 * ans);
    }


    return 0;
}

