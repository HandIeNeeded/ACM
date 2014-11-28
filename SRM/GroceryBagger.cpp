#line 2 "GroceryBagger.cpp"

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

map<string, int> mp;

class GroceryBagger {
	public:
	int minimumBags(int strength, vector <string> itemType) {

		mp.clear();
		int tot = 0;
		int n = SZ(itemType);
		REP(i, n) {
			if (!mp.count(itemType[i])) {
				mp[itemType[i]] = 1;
			}
			else {
				mp[itemType[i]]++;
			}
		}
		int ans = 0;
		for (auto it = mp.begin(); it != mp.end(); ++it) {
			ans += (it-> second  + strength - 1) / strength;
		}
		return ans;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; string Arr1[] = {"DAIRY",
 "DAIRY",
 "PRODUCE",
 "PRODUCE",
 "PRODUCE",
 "MEAT"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, minimumBags(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; string Arr1[] = {"DAIRY",
 "DAIRY",
 "PRODUCE",
 "PRODUCE",
 "PRODUCE",
 "MEAT"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, minimumBags(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, minimumBags(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; string Arr1[] = {"CANNED",   "CANNED",  "PRODUCE",
 "DAIRY",    "MEAT",    "BREAD",
 "HOUSEHOLD","PRODUCE", "FROZEN",
 "PRODUCE", "DAIRY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(3, Arg2, minimumBags(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 2; string Arr1[] = {"CANNED",   "CANNED",  "PRODUCE",
 "DAIRY",    "MEAT",    "BREAD",
 "HOUSEHOLD","PRODUCE", "FROZEN",
 "PRODUCE", "DAIRY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(4, Arg2, minimumBags(Arg0, Arg1)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	GroceryBagger ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
