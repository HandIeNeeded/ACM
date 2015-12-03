#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 55;
const int MO = 1e9 + 7;
int ans, n;
string s;

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

void dfs(int dep) {
    if (dep == n) {
        //cout << s << ' ' << "hehe" << endl;
        LL a, b;
        int pos = s.find('*');
        if (pos == 0 || pos == int(s.size()) - 1) return ;
        a = stoll(s.substr(0, pos));
        string tmp = s.substr(pos + 1);
        b = stoll(tmp);
        //cout << a << ' ' << b << endl;
        a %= MO, b %= MO;
        add(ans, 1LL * a * b % MO);
    }
    else {
        REP(i, s.size()) {
            REPP(j, i + 1, s.size() - 1) {
                swap(s[i], s[j]);
                dfs(dep + 1);
                swap(s[i], s[j]);
                //cout << "xixi" << i << ' ' << j << ' ' << s.size() << endl;
            }
        }
    }
}

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif

    int t, ca = 1;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        ans = 0;
        dfs(0);
        cout << "Case #" << ca++ << ": " << ans << endl;
    }

    return 0;
}

