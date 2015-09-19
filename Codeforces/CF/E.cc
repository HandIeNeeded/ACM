#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

string s;
vector<int> ans;
set<int> L, R;

int get(int start, int type) {
    ans.clear();
    int res = 0;
    ans.push_back(start);
    int now = start;
    L.erase(start), R.erase(start);
    while (L.size() || R.size()) {
        if (type) {
            auto pos = R.upper_bound(now);
            if (pos == R.end()) {
                pos = R.begin();
                res++;
            }
            now = *pos;
            R.erase(now);
        }
        else {
            auto pos = L.upper_bound(now);
            if (pos == L.end()) {
                pos = L.begin();
                res++;
            }
            now = *pos;
            L.erase(now);
        }
        type ^= 1;
        ans.push_back(now);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);

    set<int> L, R;
    cin >> s;
    int n = s.size();
    int a = 0, b = 0;
    REP(i, n) {
        if(s[i] == 'L') a++, L.insert(i);
        else b++, R.insert(i);
    }
    int start = 0, type;
    int res = INT_MAX;
    if (a == b) {
        start = 0, type = s[0] == 'L';
        ::L = L, ::R = R;
        int a = get(*L.begin(), type);
        ::L = L, ::R = R;
        int b = get(*R.begin(), type);
        if (a < b) {
            ::L = L, ::R = R;
            res = get(*L.begin(), type);
        }
        else {
            res = b;
        }
    }
    else {
        if (a > b) {
            start = *L.begin(), type = 1;
            ::L = L, ::R = R;
            res = get(start, type);
        }
        else {
            start = *R.begin(), type = 0;
            ::L = L, ::R = R;
            res = get(start, type);
        }
    }
    cout << res << endl;
    for (auto &x: ans) {
        cout << x + 1 << ' ';
    }
    cout << endl;

    return 0;
}

