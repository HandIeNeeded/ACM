const double pi = acos(-1.0);

int cmp(double x) {
    if(fabs(x) < EPS) return 0;
    if(x > 0) return 1;
    return -1;
}

inline double sqr(double x) {
    return x * x;
}

struct point {
    double x, y;
    point() {}
    point(double a, double b): x(a), y(b) {}
    void input(){
        scanf("%lf%lf",&x, &y);
    }

    point operator + (const point &a, const point &b) {
        return point(a.x + b.x, a.y + b.y);
    }

    point operator - (const point &a, const point &b) {
        return point(a.x - b.x, a.y - b.y);
    }

    bool operator == (const point &a, const point &b) {
        return cmp(a.x - b.x) == 0 && cmp(a.y - b.y) == 0;
    }

    point operator * (const point &a, const double &b) {
        return point(a.x * b, a.y * b);
    }

    point operator * (const double &a, const point &b) {
        return point(a * b.x, a * b.y);
    }

    point operator / (const point &a, const double &b) {
        return point(a.x / b, a.y / b);
    }
    double norm(){
        return sqrt(sqr(x) + sqr(y));
    }
};

double det(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
}

double dot(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
}

double dist(const point &a, const point &b) {
    return (a - b).norm();
}

point rotate_point(const point &p, double A){
    double tx = p.x, ty = p.y;
    return point(tx * cos(A) - ty * sin(A), tx * sin(A) + ty * cos(A));
}

struct line {
    point a, b;
    line(){}
    line(point x, point y):a(x),b(y){}
};

line point_make_line(const point a, const point b) {
    return line(a,b);
}

double dis_point_segment(const point p, const point s, const point t) {
    if(cmp(dot(p - s, t - s))<0) return (p-s).norm();
    if(cmp(dot(p - t, s - t))<0) return (p-t).norm();
    return fabs(det(s - p, t - p) / dist(s, t));
}

void PointProjLine(const point p, const point s, const point t, point &cp) {
    double r = dot(t - s, p - s) / dot (t - s, t - s);
    cp = s + r * (t - s);
}

bool PointOnSegment(point p, point s, point t) {
    return cmp(det(p - s, t - s))==0 && cmp(dot(p - s, p - t)) <= 0;
}

bool parallel(line a, line b) {
    return !cmp(det(a.a - a.b, b.a - b.b));
}

bool line_make_point(line a, line b, point &res){
    if(parallel(a, b)) return false;
    double s1 = det(a.a - b.a, b.b - b.a);
    double s2 = det(a.b - b.a, b.b - b.a);
    res = (s1 * a.b - s2 * a.a) / (s1 - s2);
    return true;
}

const int maxn = 100;

struct polygon {
    int n;
    point a[maxn];
    polygon() {}
    double perimeter() {
        double sum = 0;
        a[n] = a[0];
        for (int i = 0; i < n; i++) sum += (a[i+1] - a[i]).norm();
        return sum;
    }

    double area() {
        double sum = 0;
        a[n] = a[0];
        for (int i = 0; i < n; i++) sum += det(a[i+1], a[i]);
        return sum/2.;
    }

    int Point_In(point t){
        int num = 0, i, d1, d2, k;
        a[n] = a[0];
        for(i = 0; i < n; i++){
            if(PointOnSegment(t, a[i], a[i+1])) return 2;
            k = cmp(det(a[i+1] - a[i], t - a[i]));
            d1 = cmp(a[i].y - t.y);
            d2 = cmp(a[i+1].y - t.y);
            if( k > 0 && d1 <= 0 && d2 > 0) num++;
            if( k < 0 && d2 <= 0 && d1 > 0) num--;
        }
        return num != 0;
    }
};

point polygon::MassCenter() {
    point ans = point(0, 0);
    if(cmp(area()) == 0) return ans;
    a[n] = a[0];
    for (int i = 0; i < n; i++) ans = ans + (a[i] + a[i + 1]) * det(a[i + 1], a[i]);
    return ans / area() / 6.;
}


struct polygon_convex {
    vector<point> P;
    polygon_convex(int Size = 0) {
        P.resize(Size);
    }
    double perimeter() {
        double ret = 0;
        int n = P.size();
        #define next(i) ( (i + 1) % n)
        for(int i = 0; i < n; i++) ret += (P[i] - P[next(i)]).norm();
        return ret;
    }

    double area() {
        double ret = 0;
        int n = P.size();
        #define next(i) ( (i + 1) % n)
        for(int i = 0 ;i < n; i++)ret += det(P[next(i)], P[i]);
        return ret / 2;
    }
};

bool comp_less(const point &a, const point &b){
    return cmp(a.x -b.x) < 0 || cmp(a.x - b.x) == 0 && cmp (a.y - b.y) < 0;
}

polygon_convex convex_hull(vector<point> a) {
    polygon_convex res(2 * a.size() + 5);
    sort(a.begin(), a.end(), comp_less);
    a.erase(unique(a.begin(), a.end()), a.end());
    int m = 0;
    for(int i = 0; i < a.size(); i++){
        while( m > 1 && cmp(det(res.P[m-1] - res.P[m-2], a[i] - res.P[m - 2])) <= 0) m--;
        res.P[m++] = a[i];
    }

    int k = m;
    for(int i = int(a.size()) - 2; i >= 0; i--) {
        while(m > k && cmp(det(res.P[m-1] - res.P[m-2], a[i] - res.P[m-2])) <= 0) m--;
        res.P[m++] = a[i];
    }
    res.P.resize(m);
    if(a.size() > 1) res.P.resize(m-1);
    return res;
}
