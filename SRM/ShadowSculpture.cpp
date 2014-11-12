#line 2 "ShadowSculpture.cpp"

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

const int N = 15;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0 ,0, 0, 0, 1, -1};
int mp[N][N][N] = {0}, vis[N][N][N] = {0};
char a[N][N], b[N][N], c[N][N];

class ShadowSculpture {
	public:
	string possible(vector <string> XY, vector <string> YZ, vector <string> ZX) {
		mem(mp), mem(vis), mem(a), mem(b), mem(c);
		int n = SZ(XY);
		REP(i, n) {
			REP(j, n) {
				if (XY[i][j] == 'N') {
					REP(k, n) mp[i][j][k] = 1;
				}
				if (YZ[i][j] == 'N') {
					REP(k, n) mp[k][i][j] = 1;
				}
				if (ZX[i][j] == 'N') {
					REP(k, n) mp[j][k][i] = 1;
				}
			}
		}

		REP(i, n) REP(j, n) {
			a[i][j] = b[i][j] = c[i][j] = 'N';
		}

		REP(i, n) REP(j, n) {
			REP(k, n) {
				if (mp[i][j][k] == 0) {
					a[i][j] = 'Y';
				}
				if (mp[k][i][j] == 0) {
					b[i][j] = 'Y';
				}
				if (mp[j][k][i] == 0) {
					c[i][j] = 'Y';
				}
			}
		}

		REP(i, n) {
			if (XY[i] != (string) a[i]) return "Impossible";
			if (YZ[i] != (string) b[i]) return "Impossible";
			if (ZX[i] != (string) c[i]) return "Impossible";
		}

		int cnt = 0;
		REP(i, n) REP(j, n) REP(k, n) if (!vis[i][j][k] && mp[i][j][k] == 0){
			cnt++;
			queue<int> q;
			q.push(i), q.push(j), q.push(k);
			vis[i][j][k] = cnt;
			while (!q.empty()) {
				int x = q.front(); q.pop();
				int y = q.front(); q.pop();
				int z = q.front(); q.pop();
				REP(dir, 6) {
					int tx = x + dx[dir];
					int ty = y + dy[dir];
					int tz = z + dz[dir];
					if (tx < 0 || tx >= n || ty < 0 || ty >= n || tz < 0 || tz >= n) continue;
					if (mp[tx][ty][tz] == 0 && !vis[tx][ty][tz]) {
						q.push(tx), q.push(ty), q.push(tz);
						vis[tx][ty][tz] = cnt;
					}
				}
			}

			mem(a), mem(b), mem(c);
			REP(i, n) REP(j, n) {
				a[i][j] = b[i][j] = c[i][j] = 'N';
			}
			REP(i, n) REP(j, n) {
				REP(k, n) {
					if (mp[i][j][k] == 0 && vis[i][j][k] == cnt) {
						a[i][j] = 'Y';
					}
					if (mp[k][i][j] == 0 && vis[k][i][j] == cnt) {
						b[i][j] = 'Y';
					}
					if (mp[j][k][i] == 0 && vis[j][k][i] == cnt) {
						c[i][j] = 'Y';
					}
				}
			}

			int good = 1;
			REP(i, n) {
				if (XY[i] != (string) a[i]) good = 0;
				if (YZ[i] != (string) b[i]) good = 0;
				if (ZX[i] != (string) c[i]) good = 0;
			}
			if (good) return "Possible";
		}

		return cnt <= 1 ? "Possible" : "Impossible";
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"YN","NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN","NN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YN","NN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(0, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"YN","NY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN","NY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YN","NY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Impossible"; verify_case(1, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"YYY","YNY","YYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYY","YNY","YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYY","YNY","YYY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(2, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"YYY","YNY","YYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYY","YNY","YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYY","YNY","YYN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Impossible"; verify_case(3, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"N"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"N"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(4, Arg3, possible(Arg0, Arg1, Arg2)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	ShadowSculpture ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
