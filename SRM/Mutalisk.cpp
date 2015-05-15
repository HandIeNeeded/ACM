#include <bits/stdc++.h>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)

using namespace std;

const int N = 150;
int dp[25][N][N], cost[N], n;

bool check(int x) {
    REPP(i, 0, n) {
        REPP(j, 0, x) {
            REPP(k, 0, x) {
                dp[i][j][k] = 10000;
            }
        }
    }
    dp[0][0][0] = 0;
    REPP(i, 1, n) {
        REPP(j, 0, x) {
            REPP(k, 0, x) if (dp[i - 1][j][k] < 10000) {
                int need = dp[i - 1][j][k];
                int cnt9 = (cost[i] + 8) / 9;
                int up1 = min(cnt9, x - j);
                REPP(a, 0, up1) {
                    int cnt3 = (cost[i] - 9 * a + 2) / 3;
                    int up2 = min(cnt3, x - k);
                    up2 = min(up2, x - a);
                    up2 = max(0, up2);
                    REPP(b, 0, up2) {
                        if (cost[i] - 9 * a - 3 * b > x - a - b) continue;
                        dp[i][j + a][b + k] = min(dp[i][j + a][b + k], need + max(0, cost[i] - 9 * a - 3 * b));
                    }
                }
            }
        }
    }
    REPP(j, 0, x) {
        REPP(k, 0, x) {
            if (dp[n][j][k] < 10000 && dp[n][j][k] <= x) return 1;
        }
    }
    return 0;
}

class Mutalisk {
    public:
    int minimalAttacks(vector <int> a) {
        n = a.size();
        REPP(i, 1, n) cost[i] = a[i - 1];
        int lo = 0, hi = 140;
        while (lo + 1 < hi) {
            int mid = (lo + hi) >> 1;
            if (check(mid)) hi = mid;
            else lo = mid;
        }
        return hi;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {12,10,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimalAttacks(Arg0)); }
	void test_case_1() { int Arr0[] = {54,18,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, minimalAttacks(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, minimalAttacks(Arg0)); }
	void test_case_3() { int Arr0[] = {55,60,53}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(3, Arg1, minimalAttacks(Arg0)); }
	void test_case_4() { int Arr0[] = {60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, minimalAttacks(Arg0)); }
	void test_case_5() { int Arr0[] = {60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 93; verify_case(5, Arg1, minimalAttacks(Arg0)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
    Mutalisk ___test;
    clock_t st = clock(), ed;

    ___test.run_test(-1);

    ed = clock();
    cout << endl << "Time: " << fixed << setprecision(7) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
    return 0;
}
// END CUT HERE
