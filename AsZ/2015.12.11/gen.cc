#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    int t = 1;
    cout << t << endl;
    REP(i, t) {
        int n = rand() % 5 + 1;
        int m = rand() % 5 + 1;
        cout << n << ' ' << m << endl;
        REP(j, m) {
            int m = rand() % n + 1;
            cout << m;
            vector<int> tmp;
            REP(i, n) tmp.push_back(i + 1);
            random_shuffle(tmp.begin(), tmp.end());
            REP(i, m) {
                cout << ' ' << tmp[i];
            }
            cout << endl;
        }
    }


    return 0;
}


