#line 2 "PotentialArithmeticSequence.cpp"

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
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define INF 0x3f3f3f3f

using namespace std;

int d[1111];
VI a;

void Init() {
	REPP(i, 1, (1 << 10)) {
		int j = i;
		while (!(j & 1)) d[i]++, j >>= 1;
	}
}

bool cool(int st, int en, int ty) {
	if (ty > 0) {
		for (int i = 1, j = st; j <= en; ++j, ++i) {
			if (a[j] != d[i]) return 0;
		}
		return 1;
	}
	else {
		for (int i = 1023, j = en; j >= st; --j, --i) {
			if (a[j] != d[i]) return 0;
		}
		return 1;
	}
}

bool match(int st, int en) {

	REPP(i, 1, 1024) {
		if (d[i] == a[st]) {
			int bad = 0;

			REPP(j, st, en) {
				if (d[i + j - st] != a[j]) {
					bad = 1;
					break;
				} 
			}
			if (!bad) return 1;
		}
	}

	return 0;
}

bool go(int st, int en) {
	int mx = -1;
	REPP(i, st, en) mx = max(mx, a[i]);
	if (mx >= 10) {
		REPP(i, st, en) if (a[i] == mx) {
			if (i == st) return cool(i + 1, en, 1);
			else if (i == en) return cool(st, i - 1, -1);
			else return cool(st, i - 1, -1) && cool(i + 1, en, 1);
		}
	}
	else return match(st, en);
}

class PotentialArithmeticSequence {
	public:
	int numberOfSubsequences(vector <int> A) {
		int n = SZ(A);
		int  ans = n;
		mem(d);
		Init();

		a = A;

		REP (i, n) {
			REPP(j, i + 1, n - 1) {
				if (go(i, j)) ans++;
			}
		}
		return ans;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,0,2,0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(0, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_1() { int Arr0[] = {0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_2() { int Arr0[] = {0,0,0,0,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(2, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_3() { int Arr0[] = {0,100,0,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(3, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_4() { int Arr0[] = {1,11,3,0,1,0,1,0,1,0,1,0,3,0,2,0,0,0,0,1,2,3,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 49; verify_case(4, Arg1, numberOfSubsequences(Arg0)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	PotentialArithmeticSequence ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
