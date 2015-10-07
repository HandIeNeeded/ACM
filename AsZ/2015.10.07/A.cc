#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

set<vector<int> > s;

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        vector<int> tmp;
        REP(i, 3) {
            int x;
            scanf("%d", &x);
            tmp.push_back(x);
        }
        sort(tmp.begin(), tmp.end());
        s.clear();
        do {
            s.insert(tmp);
        }while (next_permutation(tmp.begin(), tmp.end()));
        set<vector<int> > :: iterator it;
        printf("Case #%d:\n", ca++);
        for (it = s.begin(); it != s.end(); it++) {
            tmp = *it;
            printf("%d %d %d\n", tmp[0], tmp[1], tmp[2]);
        }
    }

    return 0;
}


