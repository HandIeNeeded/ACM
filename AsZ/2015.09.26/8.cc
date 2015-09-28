#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 1e5 + 5;

int ans[N << 2];
vector<int> num[N << 2];
int qx, qd, q, M;
vector<int> number;

void build(int x, int l, int r) {
    if (l == r) {
        ans[x] = 1;
        num[x].clear(), num[x].push_back(1);
    }
    else {
        build(LC), build(RC);
        ans[x] = 1;
    }
}

void update(int x, int l, int r) {
    if (l == r) {
        if (qd == 1) {
            num[x].push_back(1LL * ans[x] * number[l - 1] % M);
            ans[x] = num[x].back();
        }
        else {
            num[x].pop_back();
            ans[x] = num[x].back();
        }
    }
    else {
        if (qx <= MID) update(LC);
        else update(RC);
        ans[x] = 1LL * ans[L] * ans[R] % M;
    }
}

int a[N], b[N];

int main() {
#ifdef HOME
    freopen("8.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        number.clear();
        scanf("%d%d", &q, &M);
        REPP(i, 1, q) {
            scanf("%d%d", a + i, b + i);
            if (a[i] == 1) number.push_back(b[i]);
        }
        sort(number.begin(), number.end());
        number.resize(unique(number.begin(), number.end()) - number.begin());
        int tot = number.size();
        build(1, 1, tot);
        printf("Case #%d:\n", ca++);
        REPP(i, 1, q) {
            if (a[i] == 1) {
                b[i] = lower_bound(number.begin(), number.end(), b[i]) - number.begin() + 1;
                qx = b[i], qd = 1;
                update(1, 1, tot);
            }
            else {
                b[i] = b[b[i]];
                qx = b[i], qd = 0;
                update(1, 1, tot);
            }
            printf("%d\n", ans[1]);
        }
    }
    return 0;
}

