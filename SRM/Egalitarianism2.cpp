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

using namespace std;

const int INF = 0x3f3f3f3f;
const LL LIM = 1LL << 62;
const double EPS = 1e-9;

const int N = 25;
double mp[N][N], g[N][N];
VI p, q;

double sqr(double x) {return x * x;}

double dis(const int &i, const int &j) {
	return sqrt(sqr(p[i] - p[j]) + sqr(q[i] - q[j]));
}

double lowcost[N], edge[N];
int vis[N], pre[N], ca, n;

int cmp(double x) {
	if (fabs(x) < EPS) return 0;
	else if (x > 0) return 1;
	else return -1;
}

double prim() {
	vis[0] = ca;
	REP(i, n) lowcost[i] = 1e100;
	lowcost[0] = pre[0] = 0;
	REP(i, n) {
		if (vis[i] != ca && cmp(lowcost[i] - g[0][i]) > 0) {
			lowcost[i] = g[0][i];
			pre[i] = 0;
		}
	}

	double ans = 0.0;
	REP(i, n - 1) {
		double mi = 1e100;
		int best  = -1;
		REP(j, n) {
			if (vis[j] != ca && cmp(lowcost[j] - mi) < 0) {
				mi = lowcost[j];
				best = j;
			}
		}
		vis[best] = ca;
		ans += mp[pre[best]][best];
		edge[i] = mp[pre[best]][best];
		lowcost[best] = 0;
		REP(j, n) {
			if (cmp(lowcost[j] - g[best][j]) > 0) {
				lowcost[j] = g[best][j];
				pre[j] = best;
			}
		}
	}
	double avg = ans / (n - 1);
	ans = 0;
	REP(i, n - 1) {
		ans += sqr(edge[i] - avg);
	}
	ans /= n - 1;
	ans = sqrt(ans);
	return ans;
}

class Egalitarianism2 {
	public:
	double minStdev(vector <int> x, vector <int> y) {
		n = SZ(x);
		p = x, q = y;
		REP(i, n) REPP(j, i + 1, n - 1) {
			mp[i][j] = mp[j][i] = dis(i, j);
		}
		double ans = 1e100;
		ca = 0;
		REP(i, n) {
			REPP(j, i + 1, n - 1) {
				REPP(a, i, n - 1) {
					REPP(b, (a == i ? j + 1 : a + 1), n - 1) {
						double avg = (mp[i][j] + mp[a][b]) * 0.5 + 0.01;
						ca++;
						REP(ii, n) REPP(jj, ii + 1, n - 1) {
							g[ii][jj] = g[jj][ii] = sqr(mp[ii][jj] - avg);
						}
						ans = min(ans, prim());
					}
				}
			}
		}
		return ans;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(0, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.5; verify_case(1, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {12,46,81,56}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,45,2,67}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.102799971320928; verify_case(2, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2,3,9,10,15,16}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.9428090415820632; verify_case(3, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {167053, 536770, -590401, 507047, 350178, -274523, -584679, -766795, -664177, 267757, -291856, -765547, 604801, -682922, -404590, 468001, 607925, 503849, -499699, -798637}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-12396, -66098, -56843, 20270, 81510, -23294, 10423, 24007, -24343, -21587, -6318, -7396, -68622, 56304, -85680, -14890, -38373, -25477, -38240, 11736}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 40056.95946451828; verify_case(4, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {-306880, 169480, -558404, -193925, 654444, -300247, -456420, -119436, -620920, -470018, -914272, -691256, -49418, -21054, 603373, -23656, 891691, 258986, -453793, -782940}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-77318, -632629, -344942, -361706, 191982, 349424, 676536, 166124, 291342, -268968, 188262, -537953, -70432, 156803, 166174, 345128, 58614, -671747, 508265, 92324}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 36879.15127634308; verify_case(5, Arg2, minStdev(Arg0, Arg1)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	Egalitarianism2 ___test;
	clock_t st = clock(), ed;

	___test.run_test(-1);

	ed = clock();
	cout << endl << "Time: " << fixed << setprecision(7) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
	return 0;
}
// END CUT HERE
