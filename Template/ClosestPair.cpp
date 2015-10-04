//double version
struct point{
    double x, y;
}p[N];
//sort all points using cmp at first
inline bool cmp(const point &a, const point &b) { 
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
inline bool cmpy(const int &a, const int &b) {return p[a].y < p[b].y;}
inline double sqr(double x) {return x * x;}
inline double dis(const int &i, const int &j) {
    return sqrt(sqr(p[i].x - p[j].x) + sqr(p[i].y - p[j].y));
}//square of dis

int tmp[N];
//return (dis * dis)
double Closest_Pair(int left, int right) { 
    double d = INF; // square of ans
    if (left == right) return d;
    if (left + 1 == right) return dis(left, right);
    int mid = (left + right) >> 1;
    double  dl = Closest_Pair(left, mid);
    double dr = Closest_Pair(mid + 1, right);
    d = min(dl, dr);
    int cnt = 0;
    REPP(i, left, right) {
        if (abs(p[mid].x - p[i].x) <= d) {
            tmp[cnt++] = i;
        } 
    }
    sort(tmp, tmp + cnt, cmpy);
    REP(i, cnt) {
        for (int j = i + 1; j < cnt && p[tmp[j]].y - p[tmp[i]].y < d; ++j) {
            double dd = dis(tmp[i], tmp[j]); //tmp[i] not i
            if (d > dd) d = dd;
        }
    }
    return d;
}
