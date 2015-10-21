#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define next hehe
#define ALL(a) (a).begin(), (a).end()

using namespace std;

const int N = 1e5 + 5;
const int L = 31;

int next[N][L], a[N], b[N], c[N];
int n, tot;
vector<int> num;

struct Tree{
    int l, r, cnt;
}t[N * 20];

int head[N], node;

int Node() {
    t[node].l = t[node].r = t[node].cnt = 0; 
    return node++;
}

void update(int &now, int pre, int l, int r, int num) {
    now = Node();
    if (l == r) {
        t[now].cnt = t[pre].cnt + 1;
        return ;
    }
    else {
        int mid = (l + r) >> 1;
        if (num <= mid) {
            update(t[now].l, t[pre].l, l, mid, num);
            t[now].r = t[pre].r;
        }
        else {
            update(t[now].r, t[pre].r, mid + 1, r, num);
            t[now].l = t[pre].l;
        }
        t[now].cnt = t[t[now].l].cnt + t[t[now].r].cnt;
    }
}

int query(int now, int pre, int l, int r, int qx) {
    if (l == r) {
        return t[now].cnt - t[pre].cnt;
    }
    else {
        int mid = (l + r) >> 1;
        if (qx <= mid) return query(t[now].l, t[pre].l, l, mid, qx);
        else return query(t[now].r, t[pre].r, mid + 1, r, qx);
    }
}

void init() {
    head[0] = Node();
    tot = num.size();
    //for (auto &x: num) {
    //    cout << x << ' ';
    //}
    //cout << endl;
    //cout << "tot: " << tot << endl;
    REPP(i, 1, n) {
        update(head[i], head[i - 1], 1, tot, b[i]);
    }
    REP(i, L) {
        next[n + 1][i] = n + 1;
        for (int j = n; j >= 1; j--) {
            if (a[j] & (1 << i)) next[j][i] = next[j + 1][i];
            else next[j][i] = j;
        }
    }
    //REPP(j, 1, n) {
    //    REP(i, L) {
    //        cout << next[j][i] << ' ';
    //    }
    //    cout << endl;
    //}
}

int main() {
#ifdef HOME
    freopen("H.in", "r", stdin);
#endif
    freopen("hack.in", "r", stdin);
    freopen("hack.out", "w", stdout);

    scanf("%d", &n);
    int now = 0;
    REPP(i, 1, n) scanf("%d", a + i);
    REPP(i, 1, n) {
        now ^= a[i];
        b[i] = now;
        num.push_back(now);
    }
    //REPP(i, 1, n) cout << b[i] << ' ';
    //cout << endl;
    REPP(i, 1, n) c[i] = b[i];
    sort(ALL(num));
    num.resize(unique(ALL(num)) - num.begin());
    REPP(i, 1, n) b[i] = lower_bound(ALL(num), b[i]) - num.begin() + 1;
    init();
    //cout << "tot: " << tot << endl;
    //REPP(i, 1, n) cout << b[i] << ' ';
    //cout << endl;
    LL ans = 0;
    pair<int, int> tmp[L];
    int ql, qr;
    REPP(i, 1, n) {
        REP(j, L) tmp[j] = {next[i][j], j};
        sort(tmp, tmp + L);
        int pre = c[i - 1];
        ql = i;
        int now = 0;
        REP(j, L) {
            qr = tmp[j].first - 1;
            now = 0;
            REPP(k, j, L - 1) if (tmp[k].first >= tmp[j].first) now |= (1 << tmp[k].second);
            if (ql <= qr) {
                int x = pre ^ now;
                int pos = lower_bound(ALL(num), x) - num.begin();
                if (pos == tot || num[pos] != x) {
                    ql = qr + 1;
                    continue;
                }
                //cout << i << ' ' << now << ' ' << "hehe" <<  ' ' << ql << ' ' << qr << ' ' << pos + 1 << endl;
                ans += query(head[qr], head[ql - 1], 1, tot, pos + 1);
            }
            ql = qr + 1;
        }
        qr = n;
        int x = pre;
        int pos = lower_bound(ALL(num), x) - num.begin();
        if (pos == tot || num[pos] != x) ;
        else if (qr >= ql) ans += query(head[qr], head[ql - 1], 1, tot, pos + 1);
        //cout << i << ' ' << now << ' ' << "hehe" <<  ' ' << ql << ' ' << qr << ' ' << pos + 1 << endl;
        //cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
