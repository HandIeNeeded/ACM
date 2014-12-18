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
const int N = 100005;
double dp[N << 1];

class WaitingForBus {
	public:
	double whenWillBusArrive(vector <int> time, vector <int> prob, int s) {
		int n = SZ(time);
		MST(dp, 0);
		dp[0] = 1.0;
		double ans = 0;
		REP(i, s) {
			REP(j, n) {
				dp[i + time[j]] += dp[i] * prob[j] / 100.0;
			}
		}
		REPP(i, 0, s - 1) {
			REP(j, n) if (i + time[j] >= s) {
				ans += dp[i] * prob[j] * (i + time[j] - s) / 100.0;
			}
		}
		return ans;	
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {90,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; double Arg3 = 9.5; verify_case(0, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 101; double Arg3 = 4.0; verify_case(1, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {5,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50,50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 88888; double Arg3 = 3.666666666666667; verify_case(2, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,20,30,40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; double Arg3 = 1.166666666666667; verify_case(3, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {10,100,1000,10000,100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {90,4,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100000; double Arg3 = 21148.147303578935; verify_case(4, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	WaitingForBus ___test;
	clock_t st = clock(), ed;

	___test.run_test(-1);
	
	ed = clock();
	cout << endl << "Time: " << fixed << setprecision(7) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
	return 0;
}
// END CUT HERE
