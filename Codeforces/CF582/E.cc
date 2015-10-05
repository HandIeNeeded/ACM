#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

map<int, int> mp;

void Erase(int x, int val) {
    mp[x] -= val;
    if (mp[x] == 0) mp.erase(x);
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    REP(i, n * n) {
        int x;
        scanf("%d", &x);
        mp[x]++;
    }
    vector<int> ans;
    while (ans.size() < 1u * n) {
        int x = mp.rbegin()->first;
        REP(i, ans.size()) {
            Erase(__gcd(x, ans[i]), 2);
        }
        ans.push_back(x);
        Erase(x, 1);
    }
    for(auto &y: ans) {
        cout << y << ' ' ;
    }
    cout << endl;

    return 0;
}


