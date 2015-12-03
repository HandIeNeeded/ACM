#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int M = 10;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    srand(time(0) % clock());

    int t = 1;
    cout << t << endl;
    REP(i, t) {
        int n = rand() % 3 + 1;
        int length = rand() % 15 + 2;
        string s;
        REP(i, length) {
            s += char('0' + rand() % 10);
        }
        int pos = rand() % s.size();
        s.insert(pos, 1, '*');
        cout << n << endl << s << endl;
    }

    return 0;
}

