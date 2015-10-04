#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define MST(a, b) memset(a, b, sizeof(a))
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define debug(x) cout << #x << "is: " << x << endl

#define FI first
#define SE second
#define VI vector<int>
#define VP vector<PII>
#define VS vector<string>
#define PII pair<int, int>
#define ALL(a) (a).begin(), (a).end()
#define pb push_back
#define make make_pair

const int inf = 0x3f3f3f3f;
const double eps = 1e-9;

using namespace std;

map<int, int> mp;

int main() {
	ios :: sync_with_stdio(0);
    int n;
    cin >> n;
    REP(i, n * n) {
        int x;
        cin >> x;
        mp[x]++;
    }
    int now = 1;
    vector<int> tmp;
    while (mp.size()) {
        tmp.clear();
        for (auto &y: mp) {
            if (y.second & 1) {
                REP(i, now) cout << y.first << ' ';
                tmp.push_back(y.first);
            }
        }
        REP(i, tmp.size()) {
            mp[tmp[i]] -= 1;
            if (mp[tmp[i]] == 0) mp.erase(tmp[i]);
            REPP(j, i + 1, tmp.size() - 1) {
                int d = __gcd(tmp[i], tmp[j]);
                mp[d] -= 2;
                if (mp[d] == 0) mp.erase(d);
            }
        }
        now <<= 1;
        for (auto &y: mp) {
            y.second >>= 2;
        }
    }
    cout << endl;

	return 0;
}
