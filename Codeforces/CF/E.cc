#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

string s;

int solve(int start, int type, vector<int> &ans) {
    set<int> L, R;
    REP(i, s.size()) {
        if (s[i] == 'L') L.insert(i);
        else R.insert(i);
    }
    L.erase(start), R.erase(start);
    int res = 0;
    ans.push_back(start);
    int now = start;
    while (L.size() || R.size()) {
        //cout << now << ' ' << "hehe" << endl;
        if (type) {
            auto pos = R.upper_bound(now);
            if (pos == R.end() || (pos == ++R.begin() && L.size() > R.size())) {
                pos = R.begin();
                res++;
            }
            now = *pos;
            R.erase(now);
        }
        else {
            auto pos = L.upper_bound(now);
            if (pos == L.end() || (pos == ++L.begin() && R.size() > L.size())) {
                pos = L.begin();
                res++;
            }
            now = *pos;
            L.erase(now);
        }
        type ^= 1;
        ans.push_back(now);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);

    cin >> s;
    int n = s.size();
    int a = 0, b = 0;
    REP(i, n) {
        if(s[i] == 'L') a++;
        else b++;
    }
    int start = 0, type;
    if (a == b) {
        start = 0, type = s[0] == 'L';
        vector<int> a, b;
        int ansa = solve(
    }
    else {
        if (a > b) {
            start = *L.begin(), type = 1;
        }
        else {
            start = *R.begin(), type = 0;
        }
    }
    cout << res << endl;
    for (auto &x: ans) {
        cout << x + 1 << ' ';
    }
    cout << endl;

    return 0;
}
