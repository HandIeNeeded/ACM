#line 2 "DefectiveAddition.cpp"

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

const int N = 55;
const int MOD = (int) 1e9 + 7;
const int INV = (int) 5e8 + 4;
const int key = 32;
int d[N][40], dp[2][2];

void getbit(int x, int id) {
	REP(i, key) {
		d[id][i] = x & 1;
		x >>= 1;
	}
	reverse(d[id], d[id] + key);
}

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int qp(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1LL * ans * x % MOD;
		y >>= 1;
		x = 1LL * x * x % MOD;
	}
	return ans;
}

class DefectiveAddition {
	public:
	int count(vector <int> cards, int m) {
		int n = SZ(cards);
		REP(i, n) {
			cards[i]++;
			getbit(cards[i], i);
		}
		int ans = 0;
		REP(bit, key) {
			int tmp = 0, cnt = 0, cur = 0;
			int tot = 1, left = key - 1 - bit;
			dp[0][0] = 1, dp[0][1] = 0;
			REP(i, n) {
				cards[i] ^= (d[i][bit] << left);
				tot = 1LL * tot * cards[i] % MOD;
				tmp ^= d[i][bit];
				if (d[i][bit]) {
					cnt ^= 1;
					REP(k, 2) {
						dp[cur ^ 1][k] = 1LL * dp[cur][k ^ 1] * cards[i] % MOD;
						add(dp[cur ^ 1][k], 1LL * dp[cur][k] * (1 << left) % MOD);
					}
				}
				else {
					REP(k, 2) {
						dp[cur ^ 1][k] = 1LL * dp[cur][k] * cards[i] % MOD;
					}
				}
				cur ^= 1;
			}
			if (cnt) {
				add(dp[cur][1], MOD - tot);
			}
			else {
				add(dp[cur][0], MOD - tot);
			}
			REP(k, 2) {
				dp[cur][k] = 1LL * dp[cur][k] * qp(INV, left) % MOD;
			}
			add(ans, dp[cur][(m >> left) & 1]);
			if (tmp ^ ((m >> left) & 1)) break;
		}
		return ans;
	} 
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 6; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4, 5, 7, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 240; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; int Arg2 = 1965600; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; int Arg2 = 0; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 949480669; verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	DefectiveAddition ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
