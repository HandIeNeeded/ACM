#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define ALL(a) (a).begin(), (a).end()

using namespace std;

const int N = 25;
const int MO = 1e9 + 7;

struct Unit{
    int cnt, mx;
}mp[N][N], g[N][N];

int bit[1 << 10];

vector<int> row, col;
int r, c, n, m, h, w;

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

void toMin(int &x, int y) {
    x = min(x, y);
}

void update(int x, int y, int a, int b, int v) {
    int r = a - x, c = b - y;
    REP(i, r) {
        REP(j, c) {
            toMin(mp[x + i][y + j].mx, v);
        }
    }
}

int pow_mod(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1LL * ans * a % MO;
        b >>= 1;
        a = 1LL * a * a % MO;
    }
    return ans;
}

struct rect{
    int a, b, c, d, v;

    void print() {
        cout << a << ' ' << b << ' '  << c << ' '  << d << ' ' << v << endl;
    }
}p[N];

void paint(int x) {
    REPP(i, 1, r) {
        REPP(j, 1, c) {
            g[i][j] = mp[i][j];
            
        }
    }
    REP(i, n) {
        if (x & (1 << i)) {
            update(p[i].a, p[i].b, p[i].c, p[i].d, p[i].v - 1);
        }
    }
}

void recover() {
    REPP(i, 1, r) {
        REPP(j, 1, c) {
            mp[i][j] = g[i][j];
        }
    }
}

void modifyr(int &x) {
    x = lower_bound(ALL(row), x) - row.begin() + 1;
}

void modifyc(int &x) {
    x = lower_bound(ALL(col), x) - col.begin() + 1;
}

void modify(rect &x) {
    modifyr(x.a), modifyr(x.c);
    modifyc(x.b), modifyc(x.d);
}

int get() {
    int ans = 1;
    REPP(i, 1, r) {
        REPP(j, 1, c) {
            ans = 1LL * ans * pow_mod(mp[i][j].mx, mp[i][j].cnt) % MO;
        }
    }
    return ans;
}

int main() {
#ifdef HOME
    freopen("tmp.in", "r", stdin);
#endif

    REP(i, 1 << 10) bit[i] = __builtin_parity(i);

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d", &h, &w, &m, &n);
        row.clear(), col.clear();
        row.push_back(1), row.push_back(h + 1);
        col.push_back(1), col.push_back(w + 1);
        REP(i, n) {
            int a, b, c, d, v;
            scanf("%d%d%d%d%d", &a, &b, &c, &d, &v);
            row.push_back(a), row.push_back(c + 1);
            col.push_back(b), col.push_back(d + 1);
            p[i] = (rect) {a, b, c + 1, d + 1, v};
        }
        sort(ALL(row)), sort(ALL(col));
        row.resize(unique(ALL(row)) - row.begin());
        col.resize(unique(ALL(col)) - col.begin());
        REP(i, n) {
            modify(p[i]);
            //p[i].print();
        }
        r = row.size() - 1, c = col.size() - 1;
        //cout << r << ' ' << c << endl;
        REPP(i, 1, r) {
            REPP(j, 1, c) {
                mp[i][j] = (Unit) {(row[i] - row[i - 1]) * (col[j] - col[j - 1]), m};
            }
        }
        REP(i, n) {
            update(p[i].a, p[i].b, p[i].c, p[i].d, p[i].v);
        }
        int ans = 1;
        REPP(i, 1, r) {
            REPP(j, 1, c) {
                ans = 1LL * ans * pow_mod(mp[i][j].mx, mp[i][j].cnt) % MO;
            }
        }
        REP(i, 1 << n) if (i) {
            paint(i);
            int tmp = get();
            recover();
            if (bit[i]) add(ans, MO - tmp);
            else add(ans, tmp);
        }
        printf("Case #%d: %d\n", ca++, ans);
    }
    return 0;
}
