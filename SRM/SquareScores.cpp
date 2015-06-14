#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define MST(a, b) memset(a, b, sizeof(a))
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)

using namespace std;

const int N = 26;
const int M = 1005;
double p[N];
int sum[M];
string s;

bool match(char a, char b) {
	return a == b || a == '?' || b == '?';
}

int cnt[N][M];
double pw[N][M];

class SquareScores {
    public:
    double calcexpectation(vector <int> P, string s) {
		::s = s;
		int n = P.size();
		REP(i, n) p[i] = 1.0 * P[i] / 100;
		n = s.size();
		REPP(i, 1, n) sum[i] = sum[i - 1] + (s[i - 1] == '?');
		REP(j, 26) {
			REPP(i, 1, n) {
				cnt[j][i] = cnt[j][i - 1] + match(s[i - 1], 'a' + j);
			}
			pw[j][0] = 1.0;
			REPP(i, 1, n) {
				pw[j][i] = pw[j][i - 1] * p[j];
			}
		}
		double ans = 0;
		REP(i, n) {
			REP(j, 26) {
				if (match('a' + j, s[i])) {
					REPP(k, 1, n) if (i + k - 1 < n) {
						int st = i, ed = st + k;
						if (cnt[j][ed] - cnt[j][st] == ed - st) {
							ans += pw[j][sum[ed] - sum[st]];
							//ans += pow_mod(p[j], sum[ed] - sum[st]);
							//cout << i << ' ' << j << ' ' << ans << endl;
						}
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
	void test_case_0() { int Arr0[] = {1, 99}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aaaba"; double Arg2 = 8.0; verify_case(0, Arg2, calcexpectation(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {10, 20, 70}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aa?bbbb"; double Arg2 = 15.0; verify_case(1, Arg2, calcexpectation(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10, 20, 30, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "a??c?dc?b"; double Arg2 = 11.117; verify_case(2, Arg2, calcexpectation(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {25, 25, 21, 2, 2, 25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "a??b???????ff??e"; double Arg2 = 21.68512690712425; verify_case(3, Arg2, calcexpectation(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "??????????????????????????????"; double Arg2 = 31.16931963781721; verify_case(4, Arg2, calcexpectation(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {4, 3, 4, 3, 8, 2, 4, 3, 4, 4, 3, 2, 4, 4, 3, 4, 2, 4, 7, 6, 4, 4, 3, 4, 4, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "makigotapresentfromniko"; double Arg2 = 23.0; verify_case(5, Arg2, calcexpectation(Arg0, Arg1)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
    SquareScores ___test;
    clock_t st = clock(), ed;

    ___test.run_test(-1);

    ed = clock();
    cout << endl << "Time: " << fixed << setprecision(7) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
    return 0;
}
// END CUT HERE
