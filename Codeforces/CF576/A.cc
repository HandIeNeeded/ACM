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
const int N = 1005;
int p[N], vis[N], tot;

void prime() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) p[tot++] = i;
        for (int j = 0; j < tot && i * p[j] < N; j++) {
            vis[i * p[j]] = p[j];
            if (i % p[j] == 0) break;
        }
    }
}

vector<int> ans;

int main() {
	ios :: sync_with_stdio(0);
    int n;
    prime();
    cin >> n;
    REP(i, tot) {
        int tmp = p[i];
        while (tmp <= n) {
            ans.push_back(tmp);
            tmp *= p[i];
        }
    }
    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i] << ' ';
    }
    cout << endl;


	return 0;
}
