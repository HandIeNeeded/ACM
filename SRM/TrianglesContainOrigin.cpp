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

#define MST(a, b) memset(a, b, sizeof(a))
#define DBG(x, s) cout << (x) << ' ' << (s) << endl
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define RED(i, n) for (int i = (int) (n - 1); i >= 0; --i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define REDD(i, a, b) for (int i = (int) (a); i >= (int) (b); --i)

using namespace std;

const int INF = 0x3f3f3f3f;
const LL LIM = 1LL << 62;
const double EPS = 1e-9;

const int N = 5005;

struct Point {
	long long x, y;
	bool flag;

	Point (long long _x = 0, long long _y = 0, bool _f = 0) : x(_x), y(_y), flag(_f) {}

	int dim() const {
		return x < 0 || x == 0 && y < 0;
	}
};

long long det(const Point &a, const Point &b) {
	return a.x * b.y - a.y * b.x;
}

bool byAng(const Point &a, const Point &b) {
	if (a.dim() == b.dim()) {
		return det(a, b) < 0;
	} else {
		return a.dim() < b.dim();
	}
}

int prefix[N];
int opposite[N];

class TrianglesContainOrigin {
	public:
	long long count(vector <int> x, vector <int> y) {
		Point p[N];
		int n = SZ(x);
		REP(i, n) {
			p[i] = Point(x[i], y[i], 1);
		}
		REP(i, n) {
			p[i + n] = Point(-x[i], -y[i], 0);
		}
		int tot = 2 * n;
		sort(p, p + tot, byAng);
		REP(i, n) {
			REPP(j, i + 1, tot - 1) {
				if (p[i].x == -p[j].x && p[i].y == -p[j].y) {
					opposite[i] = j;
					opposite[j] = i;
					break;
				}
 			}
		}

		REPP(i, 1, tot) {
			prefix[i] = prefix[i - 1] + p[i - 1].flag;
		}

		LL ans = 0;
		REP(i, n) if (p[i].flag) {
			int bound = opposite[i] - 1;
			if (opposite[i] < i) {
				break;
			}
			REPP(j, i + 1, bound)  if (p[j].flag) {
				int start = opposite[i] + 1;
				int end = opposite[j] + 1;
				if (opposite[j] < j) {
					end = tot;
				}
				ans += prefix[end] - prefix[start];
			}
		}
		return ans;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1,-1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,-1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1,-1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,-1,2,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1,-2,3,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-2,-1,1,2,3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 8LL; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,5,10,5,-5,7,-9,-6,-3,0,8,8,1,-4,7,-3,10,9,-6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,-6,-3,4,-2,-8,-7,2,7,4,2,0,-4,-8,7,5,-5,-2,-9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 256LL; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	TrianglesContainOrigin ___test;
	clock_t st = clock(), ed;

	___test.run_test(-1);
	
	ed = clock();
	cout << endl << "Time: " << fixed << setprecision(7) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
	return 0;
}
// END CUT HERE
