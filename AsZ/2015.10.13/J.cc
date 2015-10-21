#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 5e4 + 5;
int pre[N];
map<string, pair<int, int> > dp;

int main() {
#ifdef HOME
    freopen("join.in", "r", stdin);
#endif
    freopen("join.in", "r", stdin);
    freopen("join.out", "w", stdout);

    ios::sync_with_stdio(0);
    string buffer, tmp;
    int n;
    cin >> n;
    getline(cin, buffer);
    REPP(i, 1, n) {
        getline(cin, buffer);
        //cout << "buffer" << ' ' << buffer << endl;
        stringstream sin(buffer);
        int first = 0;
        int val = 0, id = i;
        string now;
        while (sin >> tmp) {
            //cout << tmp << ' ';
            if (!first) {
                tmp.pop_back();
                now = tmp;
                //cout << "now: " << now << endl;
                if (!dp.count(tmp)) {
                    dp[tmp] = {0, i};
                }
                tie(val, id) = dp[tmp];
                pre[i] = 0;
                first = 1;
            }
            else {
                if (tmp == now) {
                    continue;
                }
                if (dp.count(tmp)) {
                    //cout << "hehe" << tmp << endl;
                    if (dp[tmp].first + 1 > val) {
                        val = dp[tmp].first + 1;
                        id = i;
                        pre[id] = dp[tmp].second;
                    }
                }
            }
        }
        //cout << endl;
        //cout << i << ' ' << val << ' ' << id << ' ' << pre[i] << endl << endl;
        dp[now] = {val, id};
    }
    vector<int> ans;
    int mx = -1, id = 0;
    for (auto &y: dp) {
        if (y.second.first > mx) {
            mx = y.second.first;
            id = y.second.second;
        }
    }
    while (id) {
        ans.push_back(id);
        id = pre[id];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i] << " \n"[i == int(ans.size()) - 1];
    }

    return 0;
}


