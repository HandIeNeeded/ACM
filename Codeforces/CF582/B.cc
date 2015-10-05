#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define MST(a, b) memset(a, b, sizeof(a))
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define debug(x) cout << #x << "is: " << x << endl
#define next hehe

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

const int N = 305;
int cnt[N], a[N], next[N];

int main() {
	ios :: sync_with_stdio(0);
    int n, t;
    cin >> n >> t;
    REP(i, n) cin >> a[i];
    VI tmp;
    REP(i, n) tmp.push_back(a[i]);
    sort(ALL(tmp));
    tmp.resize(unique(ALL(tmp)) - tmp.begin());
    REP(i, n) a[i] = lower_bound(ALL(tmp), a[i]) - tmp.begin();
    int sum = 0, ans = 0;
    REP(i, tmp.size()) next[i] = tmp.size();
    next[tmp.size()] = tmp.size();
    REP(i, n * n) {
        REP(j, n) {
            if (cnt[next[a[j]]] == 0) {
                cnt[a[j]]++;
                sum++;
            }
            else {
                cnt[a[j]]++;
                cnt[next[a[j]]]--;
            }
            REP(k, tmp.size()) {
                next[k] = k + 1;
            }
            for (int k = tmp.size() - 1; k >= 0; k--) {
                next[k] = cnt[next[k]] ? next[k] : next[next[k]];
            }
        }
        if (i == t - 1) {
            ans = sum;
            break;
        }
    }
    if (t > n * n) {
        int pre = sum;
        REP(j, n) {
            if (cnt[next[a[j]]] == 0) {
                cnt[a[j]]++;
                sum++;
            }
            else {
                cnt[a[j]]++;
                cnt[next[a[j]]]--;
            }
            REP(k, tmp.size()) next[k] = k + 1;
            for (int k = tmp.size() - 1; k >= 0; k--) {
                next[k] = cnt[next[k]] ? next[k] : next[next[k]];
            }
        }
        int d = sum - pre;
        ans = pre + (t - n * n) * d;
    }
    cout << ans << endl;

	return 0;
}
