#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LB(x) ((x) & (-(x)))

using namespace std;

const int N = 5e4 + 5;
const int M = 1e5 + 5;

int fi[N], en[N << 1], ne[N << 1], edge, clk;
int lastpos[M], sum[M];
int ans[N], tmp[N], path[N];
vector<int> fac[N];
pair<int, int> p[N];

void update(int x, int d) {
    if (x == 0) return ;
    while (x < M) {
        sum[x] += d;
        x += LB(x);
    }
}

int query(int x) {
    int ans = 0;
    while (x) {
        ans += sum[x];
        x -= LB(x);
    }
    return ans;
}

void add(int x, int y) {
    ne[++edge] = fi[x];
    fi[x] = edge;
    en[edge] = y;
}

void dfs(int x, int pre) {
    p[x].first = ++clk;
    path[clk] = x;
    for (int go = fi[x]; go; go = ne[go]) {
        int y = en[go];
        if (y != pre) {
            dfs(y, x);
        }
    }
    p[x].second = clk;
}

int get() {
    char c;
    while (c = getchar(), (c < '0' || c > '9') && (c != '-'));
    bool flag = (c == '-');
    if (flag) c = getchar();
    int x = 0;
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - 48;
        c = getchar();
    }
    return flag ? -x : x;
}

void output(int x) { //int
    if (x < 0) putchar('-'), x = -x;
    int len = 0, bit[10]; // LL  -> bit[20]
    while (x) {
        bit[len++] = x % 10;
        x /= 10;
    }
    if (!len) bit[len++] = 0;
    while (len--) putchar(bit[len] + 48);
}

bool cmp(const int &i, const int &j) {
    if (p[i].second != p[j].second) {
        return p[i].second < p[j].second;
    }
    return p[i].first < p[j].first;
}

bool cmp1(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    int n, m;
    int x, y;
    while (scanf("%d%d", &n, &m) > 0) {
        REPP(i, 1, n - 1) {
            x = get(), y = get();
            add(x, y);
            add(y, x);
        }
        dfs(1, 0);
        REPP(i, 1, n) tmp[i] = i;
        sort(tmp + 1, tmp + n + 1, cmp);
        sort(p + 1, p + n + 1, cmp1);
        REPP(i, 1, m) {
            x = get(), y = get();
            fac[x].push_back(y); 
        }
        //REPP(i, 1, n) {
        //    cout << p[i].first << ' ' << p[i].second << endl;
        //}
        //REPP(i, 1, clk) {
        //    cout << path[i] << ' ';
        //}
        //cout << endl;
        //REPP(i, 1, clk) {
        //    cout << tmp[i] << ' ';
        //}
        //cout << endl;
        int now = 1;
        REPP(i, 1, n) {
            while (now <= clk && now <= p[i].second) {
                x = path[now];
                REP(j, fac[x].size()) {
                    y = fac[x][j];
                    //cout << y << endl;
                    update(lastpos[y], -1);
                    update(now, 1);
                    lastpos[y] = now;
                }
                now++;
            }
            //cout << tmp[i] << endl;
            //cout << p[i].first << ' ' << p[i].second << endl;
            ans[tmp[i]] = query(p[i].second) - query(p[i].first - 1);
        }
        REPP(i, 1, n) {
            output(ans[i]);
            i == n ? putchar('\n') : putchar(' ');
        }
        MST(lastpos, 0), MST(fi, 0), MST(sum, 0);
        edge = clk = 0;
        REPP(i, 1, n) fac[i].clear();
    }

    return 0;
}
