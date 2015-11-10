#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define double long double

using namespace std;

const int N = 2e5 + 5;
const double A = sqrt(2) - 1;
const double eps = 1e-5;

int a[N], b[N], n;
pair<double, double> p[2][N];
pair<double, int> tmp[N];
pair<int, int> ans;
double dis;

int cmp(double x) {
    if (fabs(x) < eps) return 0;
    else if (x > 0) return 1;
    return -1;
}

bool cmp1(pair<double, int> a, pair<double, int> b) {
    return cmp(a.first - b.first) < 0 || (cmp(a.first - b.first) == 0 && a.second < b.second);
}

void calc(int a, int b) {
    if (b == 0) {
        REPP(i, 1, n) tmp[i] = {p[a][i].first + p[a][i].second, i};
    }
    else {
        REPP(i, 1, n) tmp[i] = {p[a][i].first - p[a][i].second, i};
    }
    sort(tmp + 1, tmp + n + 1, cmp1);
    double res = tmp[n].first - tmp[1].first;
    if (cmp(res - dis) > 0) {
        dis = res;
        ans = {tmp[1].second, tmp[n].second};
    }
}

int main() {
#ifdef HOME
    freopen("G.in", "r", stdin);
#endif

    scanf("%d", &n);
    REPP(i, 1, n) {
        scanf("%d%d", a + i, b + i);
        p[0][i] = {A * a[i], b[i]};
        p[1][i] = {a[i], A * b[i]};
        //cout << p[0][i].first << ' ' << p[0][i].second << endl;
        //cout << p[1][i].first << ' ' << p[1][i].second << endl;
    }
    REP(i, 2) {
        REP(j, 2) {
            calc(i, j);
        }
    }
    int x, y;
    tie(x, y) = ans;
    printf("%d %d\n", x, y);

    return 0;
}



