#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LB(x) ((x) & (-(x)))
#define delete del

using namespace std;

const int N = 1e5 + 5;
vector<int> v[N], w[N];
int s[2][N];

void add(int id, int x, int val) {
    while (x < N) {
        s[id][x] += val;
        x += LB(x);
    }
}

int query(int id, int x) {
    int ans = 0;
    while (x) {
        ans += s[id][x];
        x -= LB(x);
    }
    return ans;
}

void update(int x) {
    add(0, x, 1);
    add(1, x, x);
}

void delete(int x) {
    add(0, x, -1);
    add(1, x, -x);
}

int get(int x) {
    int lo = 0, hi = N;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (query(0, mid) < x) lo = mid;
        else hi = mid;
    }
    return query(1, lo) + (x - query(0, lo)) * hi;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    REPP(i, 1, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (y) {
            v[x].push_back(y);
            update(y);
        }
        else {
            v[0].push_back(0);
        }
    }
    REP(i, N) {
        sort(v[i].begin(), v[i].end());
        reverse(v[i].begin(), v[i].end());
        if (i) {
            REP(j, v[i].size()) {
                w[j].push_back(v[i][j]);
            }
        }
    }
    int ans = 0, res = 1 << 30, now = v[0].size();
    for (int i = n; i >= 1; i--) {
        //others at most i - 1 votes
        REP(j, w[i - 1].size()) {
            ans += w[i - 1][j];
            now++;
            delete(w[i - 1][j]);
        }
        if (now >= i) {
            res = min(res, ans);
        }
        else {
            int pre = ans;
            ans += get(i - now);
            res = min(res, ans);
            ans = pre;
        }
    }
    cout << res << endl;
    return 0;
}
