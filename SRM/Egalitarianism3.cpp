#line 2 "Egalitarianism3.cpp"

#include <bits/stdc++.h>
#define dou double
#define LL long long
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define SZ(a) ((int) a.size())
#define ALL(a) a.begin(), a.end()
#define PII pair<int, int>
#define mem(a) memset(a, 0, sizeof(a))
#define memm(a) memset(a, -1, sizeof(a))
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define N 55

using namespace std;

vector<int> e[55], v[55];

int vis[55], d[55][55], n;

int go(int rt) {
	mem(vis);

	vis[rt] = 1; d[rt][rt] = 0;
	queue<int> q;

	q.push(rt);
	int x;
	while (!q.empty()) {
		x = q.front(); q.pop();
		REP(i, SZ(e[x])) if (!vis[e[x][i]]) {
			d[rt][e[x][i]] = d[rt][x] + v[x][i];
			vis[e[x][i]] = 1;
			q.push(e[x][i]);
		}
	}
	return 0;
}

int cal(int x, int y) {
	vector<int> can, good;
	REPP(i, 1, n) if (i != x && i != y && d[x][i] == d[y][i] && d[x][i] == d[x][y]) can.push_back(i);
	//cout << "ss" << x << ' ' << y << ' ' << SZ(can) << endl;
	good.push_back(x), good.push_back(y);
	int now = 2;
	REP(i, SZ(can)) {
		int bad = 0;
		REP(j, now) {
			if (d[can[i]][good[j]] != d[x][y]) {
				bad = 1;
				break;
			}
		}
		if (!bad) good.push_back(can[i]), now++;
	}
	return now;
}

class Egalitarianism3 {
	public:
	int maxCities(int nn, vector <int> a, vector <int> b, vector <int> len) {
		REPP(i, 1, nn) e[i].clear(), v[i].clear();
		REP(i, nn - 1) {
			e[a[i]].push_back(b[i]), v[a[i]].push_back(len[i]);
			e[b[i]].push_back(a[i]), v[b[i]].push_back(len[i]);
		}
		n = nn;
		if (n == 1) return 1;
		int ans = 0;
		REPP(i, 1, n) go(i);
		// REPP(i, 1, n) {
		// 	REPP(j, 1, n) cout << d[i][j] << ' ';
		// 	cout << endl;
		// }
		REPP(i, 1, n) REPP(j, i + 1, n) {
			//cout << i << ' ' << j << ' ' << cal(i, j) << endl;
			ans = max(ans, cal(i, j));
		}

		return ans;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(0, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 6; int Arr1[] = {1,2,3,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,5,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,1,3,2,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(1, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arr1[] = {1,1,1,1,1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,5,6,7,8,9,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 9; verify_case(2, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(3, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	Egalitarianism3 ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
