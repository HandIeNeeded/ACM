#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

map<char, int> mp;
string digit = "0123456789ABCDEF";

int main() {
#ifdef HOME
    freopen("B.in", "r", stdin);
#endif

    REP(i, 10) mp['0' + i] = i;
    REPP(i, 'A', 'F') mp[i] = 10 + i - 'A';

    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    int find = 0;
    REP(i, n) {
        int x = mp[s[i]];
        //cout << i << "xixi" << endl;
        REPP(j, x + 1, 15) {
            //cout << j << "hehe" << endl;
            int vis[16];
            memset(vis, 0, sizeof(vis));
            vis[j] = 1;
            int bad = 0;
            REPP(k, i + 1, n - 1) {
                //cout << k << ' ' << s[k] << ' ' << vis[1] << ' ' << j  << endl;
                vis[mp[s[k]]]++;
                //cout << k << ' ' << s[k] << ' ' << vis[1] << ' ' << j  << endl;
                if (vis[mp[s[k]]] > 1) {
                    bad = 1;
                    break;
                }
            }
            //REP(i, 16) {
            //    cout << i << ' ' << vis[i] << endl;
            //}
            if (bad) continue;
            s[i] = digit[j];
            int now = 0;
            for (int k = i - 1; k >= 0; k--) {
                while (vis[now] && now < 16) now++;
                vis[now] = 1;
                s[k] = digit[now];
            }
            reverse(s.begin(), s.end());
            cout << s << endl;
            find = 1;
            break;
        }
        if (find) break;
    }
    if (!find) {
        string ans = "1";
        REP(i, n) ans += digit[i + 1];
        ans[1] = '0';
        cout << ans << endl;
    }
    return 0;
}


