#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int mp[26];

int main() {
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    REP(i, 26) mp[i] = i;
    REP(i, m) {
        char a, b;
        cin >> a >> b;
        REP(j, 26) {
            if (mp[j] == a - 'a') {
                mp[j] = b - 'a';
            }
            else if (mp[j] == b - 'a') {
                mp[j] = a - 'a';
            }
        }
    }
    REP(i, n) {
        cout << char(mp[s[i] - 'a'] + 'a');
    }
    cout << endl;

    return 0;
}


