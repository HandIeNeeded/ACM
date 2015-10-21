#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 10000;
char s[N], r[N];

bool check(char *s, char *r) {
    while (*s || *r) {
        if (*s != *r && *s != '*') return 0;
        s++, r++;
    }
    return 1;
}

int main() {
#ifdef HOME
    freopen("F.in", "r", stdin);
#endif

    freopen("fraud.in", "r", stdin);
    freopen("fraud.out", "w", stdout);
    scanf("%s", s);
    int n;
    scanf("%d", &n);
    vector<string> ans;
    REPP(i, 1, n) {
        scanf("%s", r);
        if (check(s, r)) {
            ans.push_back(string(r));
        }
    }
    printf("%d\n", ans.size());
    for (auto &s: ans) {
        printf("%s\n", s.c_str());
    }
    return 0;
}


