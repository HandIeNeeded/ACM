#line 2 "RectangleCovering.cpp"

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

int tmp[N];

class RectangleCovering {
	public:
	int minimumNumber(int holeH, int holeW, vector <int> boardH, vector <int> boardW) {
		int n = SZ(boardW);
		int now = 0;

		REP(i, n) {
			if (boardH[i] > holeW && boardW[i] > holeW) tmp[now++] = max(boardW[i], boardH[i]);
			else if (boardH[i] > holeW) tmp[now++] = boardW[i];
			else if (boardW[i] > holeW) tmp[now++] = boardH[i];
		}
		sort(tmp, tmp + now);
		reverse(tmp, tmp + now);
		cout << "ss" << ' ' << now << endl;
		REP(i, now) cout << tmp[i] << endl;
		int tot = 0;
		int ans1 = -1, ans2 = -1;
		REP(i, now) {
			tot += tmp[i];
			if (tot >= holeH) {
				ans1 = i + 1;
				break;
			}
		}

		now = tot = 0;
		REP(i, n) {
			if (boardH[i] > holeH && boardW[i] > holeH) tmp[now++] = max(boardW[i], boardH[i]);
			else if (boardH[i] > holeH) tmp[now++] = boardW[i];
			else if (boardW[i] > holeH) tmp[now++] = boardH[i];
		}
		sort(tmp, tmp + now);
		reverse(tmp, tmp + now);
		cout << "ss" << ' ' << now << endl;
		REP(i, now) cout << tmp[i] << endl;
		REP(i, now) {
			tot += tmp[i];
			if (tot >= holeW) {
				ans2 = i + 1;
				break;
			}
		}

		cout << ans1 << ' ' << ans2 << endl;
		if (ans1 < 0 || ans2 < 0) return max(ans1, ans2);
		return min(ans1, ans2);
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {8,8,8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,3,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(0, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 10; int Arr2[] = {6,6,6,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6,6,6,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(1, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(2, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 5; int Arr2[] = {6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(3, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 10000; int Arg1 = 5000; int Arr2[] = {12345,12343,12323,12424,1515,6666,6789,1424,11111,25}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1442,2448,42,1818,3535,3333,3456,7890,1,52}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(4, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	RectangleCovering ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
