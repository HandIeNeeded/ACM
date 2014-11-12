#line 2 "SegmentDrawing.cpp"

#include <bits/stdc++.h>

#define LL long long
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define VI vector<int> 
#define VP vector<PII>
#define VS vector<string>
#define PII pair<int, int>
#define SZ(a) ((int) a.size())
#define ALL(a) a.begin(), a.end()
#define mem(a) memset(a, 0, sizeof(a))
#define memm(a) memset(a, -1, sizeof(a))
#define DBG(x, s) cout << (x) << ' ' << (s) << endl
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define RED(i, n) for (int i = (int) (n - 1); i >= 0; --i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define REDD(i, a, b) for (int i = (int) (a); i >= (int) (b); --i)
#define INF 0x3f3f3f3f
#define EPS 1e-8

using namespace std;

const int N = 1005;
const int M = 200005;

int fi[N], cur[N];
int ne[M << 1], en[M << 1], e[M << 1], edge;
int source, sink;
int lvl[N], vis[N];

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
    void input() {
        scanf("%lf%lf",&x,&y);
    }

    friend point operator + (const point &a, const point &b) {
        return point(a.x + b.x, a.y + b.y);
    }

    friend point operator - (const point &a, const point &b) {
        return point(a.x - b.x, a.y - b.y);
    }

    friend bool operator == (const point &a, const point &b) {
        return cmp(a.x - b.x) == 0 && cmp(a.y - b.y) == 0;
    }

    friend point operator * (const point &a, const double &b) {
        return point(a.x * b, a.y * b);
    }

    friend point operator * (const double &a, const point &b) {
        return point(a * b.x, a * b.y);
    }

    friend point operator / (const point &a, const double &b) {
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

struct line {
    point a, b;
    line(){}
    line(point x, point y):a(x),b(y){}
};

void _add(int x, int y, int z) {
	ne[++edge] = fi[x], fi[x] = edge, en[edge] = y, e[edge] = z;
}

void add(int x, int y, int z) {
	_add(x, y, z);
	_add(y, x, 0);
}

int bfs() {
	queue<int> q;
	mem(vis), mem(lvl);
	q.push(source);
	vis[source] = 1;

	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int go = fi[x]; go; go = ne[go]) if (e[go] > 0){
			if (!vis[en[go]]) {
				lvl[en[go]] = lvl[x] + 1;
				vis[en[go]] = 1;
				q.push(en[go]);
			}
		}
	}

	return lvl[sink];
}

int dfs(int x, int flow) {
	if (x == sink || flow == 0) return flow;
	int ans = 0, tmp;
	for (int &go = cur[x]; go; go = ne[go]) {
		int y = en[go];
		if (lvl[y] == lvl[x] + 1 && (tmp = dfs(y, min(flow, e[go]))) > 0) {
			e[go] -= tmp;
			e[go ^ 1] += tmp;
			ans += tmp;
			flow -= tmp;
		}
		if (flow == 0) return ans;
	}
	return ans;
}

int n;
point p[25];
line l[405];

int Dinic() {
	int ans = 0, tmp = 0;

	while (bfs()) {
		REPP(i, 1, sink) cur[i] = fi[i];
		while ((tmp = dfs(source, INF))) ans += tmp;
	}

	return ans;
}

bool cross(int i, int j) {
	return det(l[j].a - l[i].a, l[i].b - l[i].a) * det(l[j].b - l[i].a, l[i].b - l[i].a) <= 0
		&& det(l[i].a - l[j].a, l[j].b - l[j].a) * det(l[i].b - l[j].a, l[j].b - l[j].a) <= 0;
}

class SegmentDrawing {
	public:
	int maxScore(vector <int> x, vector <int> y, vector <int> redScore, vector <int> blueScore) {
		n = SZ(x);
		REP(i, n) p[i] = point(x[i], y[i]);
		REP(i, n) REP(j, n) l[i * n + j] = line(p[i], p[j]);
		int num = n * n;
		source = 2 * num + 1, sink = 2 * num + 2;
		edge = 1, mem(fi);
		int ans = 0;
		REPP(i, 1, n) REPP (j, 1, n) {
			ans += redScore[(i - 1) * n + (j - 1)], add(source, (i - 1) * n + (j - 1) + 1, redScore[(i - 1) * n + (j - 1)]);
		}
		REPP(i, 1, n) REPP(j, 1, n) {
			ans += blueScore[(i - 1) * n + (j - 1)], add((i - 1) * n + (j - 1) + num + 1, sink, blueScore[(i - 1) * n + (j - 1)]);
		}
		REP(i, num) REP(j, num) {
			if (cross(i, j)) add(i + 1, j + 1 + num, INF);
		}
		int tmp = 0;
		//cout << ans << endl;
		//cout << "$" << (tmp = Dinic()) << "$" << endl;
		return (ans - Dinic()) >> 1;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,0,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,0,-1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3,
 1, 0, 6, 4,
 2, 6, 0, 5,
 3, 4, 5, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 2, 3, 7,
 2, 0, 4, 6,
 3, 4, 0, 5,
 7, 6, 5, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 27; verify_case(0, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 101, 101, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 100, 100, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 101; verify_case(1, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {-3, -1, -1,  1,  1,  3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0, -2,  2, -2,  2,  0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 2, 1, 2, 1, 2,
 2, 0, 2, 1, 2, 1,
 1, 2, 0, 2, 1, 2,
 2, 1, 2, 0, 2, 1,
 1, 2, 1, 2, 0, 2,
 2, 1, 2, 1, 2, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0,
 0, 0, 0, 21, 0, 0,
 0, 0, 21, 0, 0, 0,
 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 25; verify_case(2, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {-100, 100, 0, -10, 10, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 100, 10, 10, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0, 96, 96, 25, 25, 25,
 96,  0, 96, 25, 25, 25,
 96, 96,  0, 25, 25, 25,
 25, 25, 25,  0, 10, 10,
 25, 25, 25, 10,  0, 10,
 25, 25, 25, 10, 10,  0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 0, 30, 30, 20, 20, 20,
 30,  0, 30, 20, 20, 20,
 30, 30,  0, 20, 20, 20,
 20, 20, 20,  0, 86, 86,
 20, 20, 20, 86,  0, 86,
 20, 20, 20, 86, 86,  0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 546; verify_case(3, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 15, 2, 3, 4, 5, 6, 7, 8, 9,
 15, 0, 15, 2, 3, 4, 5, 6, 7, 8,
 2, 15, 0, 15, 2, 3, 4, 5, 6, 7,
 3, 2, 15, 0, 15, 2, 3, 4, 5, 6,
 4, 3, 2, 15, 0, 15, 2, 3, 4, 5,
 5, 4, 3, 2, 15, 0, 15, 2, 3, 4,
 6, 5, 4, 3, 2, 15, 0, 15, 2, 3,
 7, 6, 5, 4, 3, 2, 15, 0, 15, 2,
 8, 7, 6, 5, 4, 3, 2, 15, 0, 15,
 9, 8, 7, 6, 5, 4, 3, 2, 15, 0}
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0, 2, 3, 4, 5, 6, 7, 8, 9,
 0, 0, 0, 2, 3, 4, 5, 6, 7, 8,
 2, 0, 0, 0, 2, 3, 4, 5, 6, 7,
 3, 2, 0, 0, 0, 2, 3, 4, 5, 6,
 4, 3, 2, 0, 0, 100, 2, 3, 4, 5,
 5, 4, 3, 2, 100, 0, 0, 2, 3, 4,
 6, 5, 4, 3, 2, 0, 0, 0, 2, 3,
 7, 6, 5, 4, 3, 2, 0, 0, 0, 2,
 8, 7, 6, 5, 4, 3, 2, 0, 0, 0,
 9, 8, 7, 6, 5, 4, 3, 2, 0, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 300; verify_case(4, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	SegmentDrawing ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
