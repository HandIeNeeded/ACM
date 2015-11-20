#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 50005;
bool dp[N], good[N];
char r[N];

char s[120][3] = {
"h", "he", "li", "be", "b", "c", "n", "o", "f", "ne", "na", "mg", "al", "si", "p", "s", "cl", "ar", "k", "ca", "sc", "ti", "v", "cr", "mn", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr", "rb", "sr", "y", "zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb", "te", "i", "xe", "cs", "ba", "hf", "ta", "w", "re", "os", "ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at", "rn", "fr", "ra", "rf", "db", "sg", "bh", "hs", "mt", "ds", "rg", "cn", "fl", "lv", "la", "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu", "ac", "th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr"
};

int get(char a, char b) {
    return (a - 'a' + 2) * 30 + (b - 'a' + 2);
}

int main() {
#ifdef HOME
    freopen("C.in", "r", stdin);
#endif

    REP(i, 114) {
        int n = strlen(s[i]);
        int ans = 0;
        REP(j, n) {
            ans = ans * 30 + s[i][j] - 'a' + 2;
        }
        good[ans] = 1;
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", r);
        int n = strlen(r);
        dp[0] = 1;
        REPP(i, 1, n) {
            dp[i] = dp[i - 1] && good[r[i - 1] - 'a' + 2];
            if (i > 1) {
                int tmp = get(r[i - 2], r[i - 1]);
                dp[i] |= dp[i - 2] && good[tmp];
            }
        }
        //REPP(i, 1, n) {
        //    cout << dp[i] << ' ';
        //}
        //cout << endl;
        !dp[n] ? puts("NO") : puts("YES");
    }


    return 0;
}


