#include <bits/stdc++.h>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define LL long long

using namespace std;

const int N = 5005;
const int L = 13;

int dp[N][L], a[N], n;

void init() {
    REPP(i, 1, n) dp[i][0] = a[i];
    REPP(j, 1, L - 1) {
        REPP(i, 1, n) {
            if (i + (1 << j) - 1 > n) break;
            else {
                dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
}

class ModModMod {
    public:
    long long findSum(vector <int> mod, int R) {
        n = mod.size();
        REP(i, n) a[i + 1] = mod[i];
        init();
        LL ans = 0;
        REPP(i, 1, R) {
            int now = i, pos = 1;
            while (pos < n) {
                int tmp = L - 1;
                while (tmp >= 0) {
                    if (dp[pos][tmp] > now) {
                        pos += 1 << tmp;
                    }
                    tmp--;
                }
                if (pos <= n) now %= a[pos];
            }
            now %= a[n];
            ans += now;
        }
        return ans;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; long long Arg2 = 4LL; verify_case(0, Arg2, findSum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {33, 15, 7, 10, 100, 9, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 64; long long Arg2 = 92LL; verify_case(1, Arg2, findSum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {995,149,28,265,275,107,555,241,702,462,519,212,362,478,783,381,602,546,183,886,59,317,977,612,328,91,771,131}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 992363; long long Arg2 = 12792005LL; verify_case(2, Arg2, findSum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; long long Arg2 = 4950LL; verify_case(3, Arg2, findSum(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {2934}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10000000; long long Arg2 = 14664070144LL; verify_case(4, Arg2, findSum(Arg0, Arg1)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
    ModModMod ___test;
    clock_t st = clock(), ed;

    ___test.run_test(-1);

    ed = clock();
    cout << endl << "Time: " << fixed << setprecision(7) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
    return 0;
}
// END CUT HERE
