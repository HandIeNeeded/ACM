#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

#define LB(x) ((x) & (-(x)))

using namespace std;

const int N = 5e5 + 5;  
int tot;

struct BIT{
    int a[N];

    void add(int x, int d) {
        while (x <= tot) {
            a[x] += d;
            x += LB(x);
        }
    }

    int query(int x) {
        int ans = 0;
        while (x) {
            ans += a[x];
            x -= LB(x);
        }
        return ans;
    }
}L, R;

int type[N], a[N], b[N];
int c[N], d[N];

int main() {
#ifdef HOME
    freopen("D.in", "r", stdin);
#endif

    int ca = 1;
    int n;
    while (scanf("%d", &n) > 0) {
        int now = 0;
        vector<int> num;
        REP(i, n) {
            int ty, qx;
            scanf("%d%d", &ty, &qx);
            if (ty == 0) {
                type[i] = 0;
                a[i] = qx;
                c[now++] = qx;
                b[i] = qx + now;
                num.push_back(qx);
                num.push_back(qx + now);
            }
            else {
                type[i] = 1;
                a[i] = c[qx - 1];
                b[i] = c[qx - 1] + qx;
            }
        }
        //REP(i, n) {
        //    cout << a[i] << ' ' << b[i] << endl;
        //}
        sort(num.begin(), num.end());
        num.resize(unique(num.begin(), num.end()) - num.begin());
        REP(i, n) {
            a[i] = lower_bound(num.begin(), num.end(), a[i]) - num.begin() + 1;
            b[i] = lower_bound(num.begin(), num.end(), b[i]) - num.begin() + 1;
        }
        tot = num.size();
        printf("Case #%d:\n", ca++);
        REP(i, n) {
            if (type[i] == 0) {
                int ans = R.query(b[i]) - L.query(a[i] - 1);
                printf("%d\n", ans);
                L.add(a[i], 1);
                R.add(b[i], 1);
            }
            else {
                //cout << "hehe" << endl;
                L.add(a[i], -1);
                R.add(b[i], -1);
            }
        }
        REP(i, now) c[i] = 0;
        REP(i, tot + 1) L.a[i] = R.a[i] = 0;
    }


    return 0;
}

