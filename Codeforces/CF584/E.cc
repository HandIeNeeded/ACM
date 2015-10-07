#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 2005;
int a[N], b[N], pos[N], p[N];

void Swap(int i, int j) {
    swap(p[a[i]], p[a[j]]);
    swap(a[i], a[j]);
}

bool need(int x, int y) {
    int target = pos[a[x]];
    return abs(x - target) > abs(y - target);
}

int main() {
    ios::sync_with_stdio(0);
    //freopen("in", "r", stdin);

    int n;
    cin >> n;
    REPP(i, 1, n) {
        cin >> a[i];
        p[a[i]] = i;
    }
    REPP(i, 1, n) {
        cin >> b[i];
        pos[b[i]] = i;
    }
    //REPP(i, 1, n) {
    //    cout << p[i] << ' ';
    //}
    //cout << endl;
    //REPP(i, 1, n) {
    //    cout << pos[i] << ' ';
    //}
    //cout << endl;
    
    int ans = 0;
    vector<pair<int, int>> res;
    REPP(i, 1, n) {
        int p = ::p[b[i]];
        if (p == i) continue;
        if (p > i) {
            int j = p - 1;
            while (j >= i) {
                if (need(j, p)) {
                    ans += p - j;
                    res.push_back({p, j});
                    Swap(p, j);
                    swap(p, j);
                    j = p;
                }
                j--;
            }
        }
        if (p < i) {
            int j = p + 1;
            while (j <= i) {
                if (need(j, p)) {
                    ans += j - p;
                    res.push_back({p, j});
                    Swap(p, j);
                    swap(p, j);
                    j = p;
                }
                j++;
            }
        }
    }
    cout << ans << endl;
    cout << res.size() << endl;
    for (auto &now: res) {
        cout << now.first << ' ' << now.second << endl;
    }

    return 0;
}
