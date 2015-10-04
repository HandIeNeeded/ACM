struct point{
    int x, y, id;
    point (int x = 0, int y = 0, int id = 0) :x(x), y(y), id(id) {}

    point operator - (const point &a) const {
        point res;
        res.x = x - a.x, res.y = y - a.y;
        return res;
    }
}p[N];

long long det(const point &a, const point &b) {
    return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

bool cmp(const point &a, const point &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

vector<point> ConvexHull(vector<point> v) {
    sort(v.begin(), v.end(), cmp);
    int n = v.size(), m;
    vector<point> C;
    for (int i = 0; i < n; i++) {
        while ((m = C.size()) > 1 && det(C[m - 1] - C[m - 2], v[i] - C[m - 2]) < EPS) C.pop_back();
        C.push_back(v[i]);
    }
    int k = C.size();
    for (int i = n - 2; i >= 0; i--) {
        while ((m = C.size()) > k && det(C[m - 1] - C[m - 2], v[i] - C[m - 2]) < EPS) C.pop_back();
        C.push_back(v[i]);
    }
    if (n > 1) C.pop_back();
    return C;
}
