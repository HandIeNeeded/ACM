#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
} ;
Point operator + (Point a, Point b) { return Point(a.x + b.x, a.y + b.y);}
Point operator - (Point a, Point b) { return Point(a.x - b.x, a.y - b.y);}
bool operator < (Point a, Point b) { return a.x < b.x || a.x == b.x < a.y < b.y;}
inline int crossDet(Point a, Point b) { return a.x * b.y - a.y * b.x;}
inline int crossDet(Point o, Point a, Point b) { return crossDet(a - o, b - o);}
inline int dotDet(Point a, Point b) { return a.x * b.x + a.y * b.y;}

inline bool onSeg(Point p, Point a, Point b) { return crossDet(p, a, b) == 0 && dotDet(a - p, b - p) < 0;}

int ptInPoly(Point p, Point *poly, int sz) {
    int wn = 0;
    poly[sz] = poly[0];
    for (int i = 0; i < sz; i++) {
        if (onSeg(p, poly[i], poly[i + 1])) return -1;
        int k = crossDet(poly[i], poly[i + 1], p);
        int d1 = poly[i].y - p.y;
        int d2 = poly[i + 1].y - p.y;
        if (k > 0 && d1 <= 0 && d2 > 0) wn++;
        if (k < 0 && d2 <= 0 && d1 > 0) wn--;
    }
    if (wn != 0) return 1;
    return 0;
}

int andrew(Point *pt, int n, Point *ch) {
    int m = 0;
    sort(pt, pt + n);
    for (int i = 0; i < n; i++) {
        while (m > 1 && crossDet(ch[m - 2], ch[m - 1], pt[i]) <= 0) m--;
        ch[m++] = pt[i];
    }
    int k = m;
    for (int i = n - 2; i >= 0; i--) {
        while (m > k && crossDet(ch[m - 2], ch[m - 1], pt[i]) <= 0) m--;
        ch[m++] = pt[i];
    }
    if (n > 1) m--;
    return m;
}

const int N = 111;

int inPoly(Point *mines, int m, Point *poly, int p) {
    int ret = 0;
    for (int i = 0; i < m; i++) {
        if (int t = ptInPoly(mines[i], poly, p)) {
            if (t == -1) {
                puts("shit!!!");
                while (1) ;
            }
            mines[ret++] = mines[i];
        }
    }
    return ret;
}

bool mat[N][N], res[N][N], cur[N][N];

bool allOnLeft(Point a, Point b, Point *s, int m) {
    for (int i = 0; i < m; i++) {
        if (crossDet(a, b, s[i]) > 0) return false;
    }
    return true;
}

int work(Point *holes, int h, Point *mines, int m) {
    memset(mat, 0, sizeof(mat));
    memset(res, 0, sizeof(res));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < h; j++) {
            if (i == j) continue;
            if (allOnLeft(holes[i], holes[j], mines, m)) mat[i][j] = res[i][j] = true;
        }
    }
//    for (int i = 0; i < h; i++) {
//        cout << "holes " << holes[i].x << ' ' << holes[i].y << endl;
//    }
//    for (int i = 0; i < m; i++) {
//        cout << "mines " << mines[i].x << ' ' << mines[i].y << endl;
//    }
//    for (int i = 0; i < h; i++) {
//        for (int j = 0; j < h; j++) {
//            cout << mat[i][j];
//        }
//        cout << endl;
//    }
//    cout << "check" << endl;
    for (int t = 1; t <= h; t++) {
        for (int i = 0; i < h; i++) {
            if (res[i][i]) {
//                cout << i << endl;
                return t;
            }
            for (int j = 0; j < h; j++) {
                cur[i][j] = res[i][j];
            }
        }
        memset(res, 0, sizeof(res));
        for (int i = 0; i < h; i++) {
            for (int k = 0; k < h; k++) {
                if (cur[i][k]) {
                    for (int j = 0; j < h; j++) {
                        res[i][j] |= cur[i][k] & mat[k][j];
                    }
                }
            }
        }
    }
    puts("damn!");
    while (1) ;
    return 0;
}

int main() {
//    freopen("in", "r", stdin);
    int T, n, m, g, p;
    Point holes[N], mines[N], poly[N];
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n >> m >> g >> p;
        for (int i = 0; i < n; i++) cin >> holes[i].x >> holes[i].y;
        for (int i = 0; i < m; i++) cin >> mines[i].x >> mines[i].y;
        int t = andrew(holes, n, poly);
//        cout << "Convex Hull" << endl;
        int k = inPoly(mines, m, poly, t);
//        cout << "inPoly" << endl;
        int ans1 = (m - k) * g;
        t = k ? work(holes, n, mines, k) : 0;
        int ans2 = t * p;
//        cout << ans1 << ' ' << ans2 << endl;
        cout << "Case #" << cas << ": " << ans1 + ans2 << endl;
    }
    return 0;
}			

