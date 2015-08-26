#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

map<string, int> mp;
char s[11];

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    int now = 0;
    string newLanguage = "hehehehehe";
    while (n--) {
        scanf("%s", s);
        string tmp(s);
        if (mp.count(tmp)) {
            puts("Impossible");
        }
        else {
            mp[tmp] = now++;
        }
    }
    printf("%d\n", mp.size());
    auto it = mp.begin();
    REP(i, mp.size()) {
        printf("%s-%s\n", newLanguage.c_str(), it->first.c_str());
        it++;
    }


    return 0;
}

