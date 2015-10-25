#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 105;
pair<int, int> p[N];
int tmp[N], need[N], n;

bool cmp(int i, int j) {
    return p[i].second < p[j].second || (p[i].second == p[j].second && p[i].first < p[j].first);
}

bool check(int x) {
    REPP(i, 1, n) need[i] = x;
    REPP(i, 0, 10000) {
        REPP(jj, 1, n) {
            int j = tmp[jj];
            if (need[j] && p[j].second >= i && p[j].first <= i) {
                need[j]--;
                break;
            }
        }
    }
    REPP(j, 1, n) if (need[j] > 0) return 0;
    return 1;
}

int main() {
#ifdef HOME
    freopen("F.in", "r", stdin);
#endif
    cin >> n;
    REPP(i, 1, n) {
        int x, y;
        cin >> x >> y;
        y--;
        p[i] = {x, y};
    }
    REPP(i, 1, n) tmp[i] = i;
    sort(tmp + 1, tmp + n + 1, cmp);
    //REPP(i, 1, n) cout << tmp[i] << ' ';
    //cout << endl;
    int lo = 0, hi = 10001;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid)) lo = mid;
        else hi = mid;
    }
    //cout << lo << endl;
    cout << n * lo << endl;

    return 0;
}


