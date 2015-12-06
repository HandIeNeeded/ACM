#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define ALL(a) (a).begin(), (a).end()

using namespace std;

const int N = 10005;
vector<int> num[N];
int a[N], b[N], c[N], d[N], n, k;
int p, q;

bool vis[1005];

void getNum(int x) {
    memset(vis, 0, sizeof(vis));
    num[x].push_back(a[x]);
    int pre = a[x];
    vis[a[x]] = 1;
    while (1) {
        int now = (b[x] * pre + c[x]) % d[x];
        if (vis[now]) break;
        num[x].push_back(now);
        vis[now] = 1;
        pre = now;
    }
}

vector<int> res;

void getId(int x) {
    int pre = a[x];
    int cnt = 0;
    int key;
    if (x == p) key = num[x][q];
    else key = num[x].back();
    if (a[x] == key) {
        res.push_back(0);
        return ;
    }
    while (1) {
        cnt++;
        int now = (b[x] * pre + c[x]) % d[x];
        //cout << now << ' ' << cnt << ' ' << key << endl;
        if (now == key) {
            res.push_back(cnt);
            return ;
        }
        pre = now;
    }
}

int main() {
#ifdef HOME
    freopen("G.in", "r", stdin);
#endif

    
    scanf("%d%d", &n, &k);
    REPP(i, 1, n) {
        scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
        getNum(i);
        //for (auto &x: num[i]) {
        //    cout << x << ' ';
        //}
        //cout << endl;
        //REP(j, num[i].size()) num[i][j] %= k;
        //for (auto &x: num[i]) {
        //    cout << x << "lala" << endl;
        //}
        sort(ALL(num[i]));
        num[i].resize(unique(ALL(num[i])) - num[i].begin());
        //for (auto &x: num[i]) {
        //    cout << x << "lala" << endl;
        //}
        //cout << endl;
    }
    int tot = 0;
    int ans = -1;
    REPP(i, 1, n) tot += num[i].back();
    REPP(i, 1, n) {
        int tmp = tot - num[i].back();
        int need = k - tmp % k;
        if (need == k) need = 0;
        for (int j = num[i].size() - 1; j >= 0; j--) if (num[i][j] % k != need) {
            if (tmp + num[i][j] > ans) {
                ans = tmp + num[i][j];
                p = i, q = j;
            }
        }
    }
    if (ans == -1) {
        printf("%d\n", ans);
    }
    else {
        printf("%d\n", ans);
        REPP(i, 1, n) getId(i);
        REP(i, res.size()) {
            printf("%d%c", res[i], " \n"[i == int(res.size()) - 1]);
        }
    }

    return 0;
}


