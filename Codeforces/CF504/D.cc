#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 2005;
const int L = 605;

bitset<N> use[N], num[N];
vector<bitset<N>> g;
char s[L];

pair<vector<int>, int> divide(vector<int> &a) {
    vector<int> ans;
    int step = 0;
    REP(i, a.size()) {
        int x = (a[i] + step * 10) % 2;
        ans.push_back((a[i] + step * 10) / 2);
        step = x;
    }
    reverse(ans.begin(), ans.end());
    while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
    reverse(ans.begin(), ans.end());
    return {ans, step};
}

void get(vector<int> &a, int id) {
    int now = 0;
    while (a.size() > 1 || a[0] != 0) {
        int x;
        tie(a, x) = divide(a);
        num[id].set(now++, x);
    }
}

int main() {
#ifdef HOME
    freopen("D.in", "r", stdin);
#endif

    int n;
    cin >> n;
    REP(i, n) {
        scanf("%s", s);
        int n = strlen(s);
        vector<int> tmp;
        REP(i, n) tmp.push_back(s[i] - '0');
        get(tmp, i);
        use[i].set(i);
        //cout << num[i].to_string() << endl;
    }
    REP(i, n) {

    }
    return 0;
}


