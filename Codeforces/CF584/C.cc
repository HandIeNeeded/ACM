#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
char ans[N];

int main() {
    ios::sync_with_stdio(0);
    string s, r;
    int n, k;
    cin >> n >> k;
    cin >> s >> r;
    k = n - k;
    vector<int> same, diff;
    REP(i, n) {
        if (s[i] != r[i]) diff.push_back(i);
        else same.push_back(i);
    }
    diff.insert(diff.end(), same.begin(), same.end());
    if (2 * k - int(same.size()) > n) {
        cout << -1 << endl;
        return 0;
    }
    int a = 0, b = 0, cnt = 0;
    while (a < k || b < k) {
        int x = diff.back();
        if (1u * cnt < same.size()) {
            ans[x] = s[x];
            a++, b++;
        }
        else {
            if (cnt & 1) {
                ans[x] = s[x];
                a++;
            }
            else {
                ans[x] = r[x];
                b++;
            }
        }
        diff.pop_back();
        cnt++;
    }
    REP(i, diff.size()) {
        int x = diff[i];
        REP(j, 26) {
            if ('a' + j != s[x] && 'a' + j != r[x]) {
                ans[x] = 'a' + j;
                break;
            }
        }
    }
    ans[n] = 0;
    cout << ans << endl;
    return 0;
}


