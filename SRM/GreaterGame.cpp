#line 2 "GreaterGame.cpp"

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

using namespace std;

class GreaterGame {
	public:
	double calc(vector <int> hand, vector <int> sothe) {
		bool use[105] = {0};
		bool belong[105] = {0};

		int n = SZ(hand);
		VI unsettle[2];
		REPP(i, 1, 2 * n) belong[i] = 1;
		REP(i, n) {
			belong[hand[i]] = 0;
		}
		double ans = 0.0;
		REP(i, n) {
			if (sothe[i] > 0) {
				use[sothe[i]] = 1;
				REPP(j, sothe[i] + 1, 2 * n) if (!use[j] && belong[j] == 0) {
					ans += 1.0;
					use[j] = 1;
					break;
				}
			}
		}
		REDD(i, 2 * n, 1) {
			if (!use[i] && belong[i] == 1) {
				unsettle[1].push_back(i);
			}
		}
		int tot = SZ(unsettle[1]);
		for (int j = 2 * n, i = 0; i < tot; --j) {
			if (!use[j] && belong[j] == 0) {
				unsettle[0].push_back(j);
				i++;
			}
		}
		// cout << tot << ' ' << unsettle[1].size() << endl;
		// REP(i, tot) cout << unsettle[0][i] << endl;
		REP(i, tot) {
			REP(j, tot) {
				if (unsettle[0][i] > unsettle[1][j]) {
					ans += 1.0 / tot;
				}
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
	void test_case_0() { int Arr0[] = {4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.5; verify_case(0, Arg2, calc(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.0; verify_case(1, Arg2, calc(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(2, Arg2, calc(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,3,5,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8,-1,4,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.5; verify_case(3, Arg2, calc(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {6,12,17,14,20,8,16,7,2,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,4,-1,11,3,13,-1,-1,18}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 8.0; verify_case(4, Arg2, calc(Arg0, Arg1)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	GreaterGame ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
