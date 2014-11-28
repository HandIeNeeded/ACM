// BEGIN CUT HERE

// END CUT HERE
#line 5 "Family.cpp"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <sstream>
#define dou double
#define LL long long
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
#define mem(a) memset(a, 0, sizeof(a))
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define INF 2000000000
#define MOD 1000000007

using namespace std;

int mp[111][111], vis[111], col[111], n;

bool dfs(int x) {
	vis[x] = 1;
	int bad = 0;
	REP(i, n){
		if (!vis[i] && mp[x][i]) {
			col[i] = col[x] ^ 1;
			bad |= dfs(i); //erranse!!!!!!!!!!
		}
		else if (mp[x][i] && vis[i] && !(col[i] ^ col[x])) return 1;
	}
	return bad;
}

class Family {
	public:
	string isFamily(vector <int> parent1, vector <int> parent2) {
		mem(vis), mem(col), mem(mp);
		n = parent2.size();
		REP(i, n) if (parent2[i] >= 0 || parent1[i] >= 0) mp[parent1[i]][parent2[i]] = mp[parent2[i]][parent1[i]] = 1;
		REP(i, n) if (!vis[i]) {
			col[i] = 0;
			if (dfs(i)) return "Impossible";
		}
		return "Possible";
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1,-1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(0, Arg2, isFamily(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1,-1,-1,-1,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,-1,-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(1, Arg2, isFamily(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1,-1,0,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,1,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(2, Arg2, isFamily(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1,-1,-1,-1,1,-1,0,5,6,-1,0,3,8,6}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,-1,-1,3,-1,4,6,5,-1,5,4,6,1}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(3, Arg2, isFamily(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-1,-1,-1,2,2,-1,5,6,4,6,2,1,8,0,2,4,6,9,-1,16,-1,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,-1,1,0,-1,1,4,2,0,4,8,2,3,0,5,14,14,-1,7,-1,13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(4, Arg2, isFamily(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Family ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
