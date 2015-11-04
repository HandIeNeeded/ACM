#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define CP const Point&
#define MX 200005
#define EPS 1e-8
struct Point {
	double x, y;
	inline bool operator<(CP p) const {
		if (fabs(x - p.x) > EPS) return x < p.x;
		return y < p.y - EPS;
	}
	inline bool operator==(CP p) const {
		return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
	}
	void input() {
		scanf("%lf%lf", &x, &y);
	}
} P[MX * 2], Q[MX], tp[MX], T, O;


double dis(CP p1, CP p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

double vect(CP p, CP p1, CP p2) {
	return (p1.x - p.x) * (p2.y - p.y) - (p2.x - p.x) * (p1.y - p.y);
}
double multi(const Point &a, const Point &b, const Point &c){//vector product of c->a and c->b
	return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
}
double scal(CP p, CP p1, CP p2) {
	return (p1.x - p.x) * (p2.x - p.x) + (p1.y - p.y) * (p2.y - p.y);
}

double dis(CP p1, CP p2, CP p) {
	if (scal(p1, p, p2) > EPS && scal(p2, p, p1) > EPS) return fabs(vect(p, p1, p2)) / dis(p1, p2);
	return min(dis(p1, p), dis(p2, p));
}

bool onseg(CP p1, CP p2, CP p) {
	return fabs(dis(p1, p) + dis(p2, p) - dis(p1, p2)) < EPS;
}

bool cross(CP p1, CP p2, CP p3, CP p4) {
	return vect(p1, p2, p3) * vect(p1, p2, p4) < -EPS && vect(p3, p4, p1) * vect(p3, p4, p2) < -EPS;
}

bool intersect(CP s1, CP e1, CP s2, CP e2) {
	double a, t1, t2;
	a = multi(s1, e1, s2) - multi(s1, e1, e2);
	if (fabs(a) < EPS) return false;
	t1 = multi(s1, e1, s2) / a;
	t2 = multi(s1, e2, s2) / a;
	return (t1 > -EPS && t1 < 1 + EPS && t2 > -EPS);
}

bool cmp(CP p1, CP p2) {
	double val = vect(T, p1, p2);
	
	if (val > EPS) return true;
	if (val < -EPS) return false;
	return dis(T, p1) < dis(T, p2);
}

int graham_scan(Point *P, int n, Point *CH) {
	int i, k, m;
	
	k = 0;
	for (i = 1; i < n; i++) {
		if (P[i] < P[k]) k = i;
	}
	swap(P[0], P[k]);
	T = P[0];
	sort(P + 1, P + n, cmp);
	
	CH[0] = P[0], CH[1] = P[1];
	m = 2;
	for (i = 2; i < n; i++) {
		while (m > 1 && vect(CH[m - 2], CH[m - 1], P[i]) < EPS) m--;
		CH[m++] = P[i];
	}
	return m;
}

bool chk[MX * 2];

int main() {
	int i, j, k, cnt, T, N, K;
	for (scanf("%d", &T); T--; ) {
		scanf("%d", &N);
		for (i = 0; i < N; i++) P[i].input();
		scanf("%d", &K);
		for (i = 0; i < K; i++) Q[i].input();
		for (i = 0; i < N; i++) P[N + i] = P[i];
		for (i = 0; i < N; i++) chk[i] = 0;
		K = graham_scan(Q, K, tp);
		O.x = O.y = 0;
		for (i = 0; i < K; i++) {
			O.x += tp[i].x, O.y += tp[i].y;
		}
		O.x /= K, O.y /= K;
		for (i = 0; i < N; i++) if (intersect(O, tp[0], P[i], P[i + 1])) break;
		
		chk[i] = true;
		chk[(i + 1) % N] = true;
		for (k = 1; k < K; k++) {
			for (; ; i++) if (intersect(O, tp[k], P[i], P[i + 1])) break;
			chk[i % N] = true;
			chk[(i + 1) % N] = true;
		}
		
		for (cnt = i = 0; i < N; i++) if (chk[i]) cnt++;
		printf("Yes\n%d\n", cnt);
		for (i = 0; i < N; i++) if (chk[i]) printf("%d ", i + 1);
		puts("");
	}
	return 0;
}
