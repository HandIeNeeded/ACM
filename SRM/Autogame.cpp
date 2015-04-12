#include <bits/stdc++.h>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)

using namespace std;

const int N = 55;
const int MO = 1e9 + 7;

vector<int> num[N];
int mp[N][N], vis[N], n;

int dfs(int x) {
	int ans = 1;
	vis[x] = 1;
	REPP(i, 1, n) if (!vis[i] && mp[x][i]) {
		ans += dfs(i);
	}
	return ans;
}

class Autogame {
	public:
	int wayscnt(vector <int> a, int K) {
		n = a.size();
		int ans = 1;
		K = min(K, n);
		REPP(i, 1, n) {
			int tmp = i;
			REPP(j, 1, K) tmp = a[tmp - 1], num[i].push_back(tmp);
		}
		REPP(i, 1, n) {
			REPP(j, 1, n) {
				REP(k, K) {
					if (num[i][k] == num[j][k]) {
						mp[i][j] = mp[j][i] = 1;
					}
				}
			}
		}
		REPP(i, 1, n) if (!vis[i]) {
			ans = 1LL * (dfs(i) + 1) * ans % MO;
		}
		return ans;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 8; verify_case(0, Arg2, wayscnt(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 4; verify_case(1, Arg2, wayscnt(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2,1}	; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 42; int Arg2 = 4; verify_case(2, Arg2, wayscnt(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,3,4,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 9; verify_case(3, Arg2, wayscnt(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {4,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 18; verify_case(4, Arg2, wayscnt(Arg0, Arg1)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	Autogame ___test;
	clock_t st = clock(), ed;

	___test.run_test(1);
	
	ed = clock();
	cout << endl << "Time: " << fixed << setprecision(7) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
	return 0;
}
// END CUT HERE
