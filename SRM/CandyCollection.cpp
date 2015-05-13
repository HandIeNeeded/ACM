#include <bits/stdc++.h>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)

using namespace std;

const int N = 4005;
vector<pair<int, int> > edge[N];
int n, tmp[N << 1], dp[N << 1][2], m;
bool vis[N];

void dfs(int x, int p) {
    vis[x] = 1;
    for (auto now: edge[x]) {
        int y = now.first, z = now.second;
        if (!vis[y]) {
            tmp[++m] = z;
            dfs(y, x);
        }
        else if (y != p) {
            tmp[++m] = z;
        }
    }
}

int godp() {
    REPP(i, 1, m) tmp[i + m] = tmp[i];
    tmp[m + m + 1] = tmp[1];
    REPP(i, 1, 2 * m) tmp[i] = tmp[i + 1];
    int ans = INT_MAX;
    for (int start = 2; start <= m; start += 2) {
        for (int i = start; i <= m + start; i += 2) dp[i][0] = dp[i][1] = 0;
        dp[start][0] = tmp[start] + 1;
        dp[start][1] = max(tmp[start - 1], tmp[start]) + 1;
        for (int i = start + 2; i < m + start; i += 2) {
            dp[i][0] = min(dp[i - 2][1], dp[i - 2][0] + tmp[i] + 1);
            dp[i][1] = min(dp[i - 2][1] + tmp[i - 1] + 1, dp[i - 2][0] + max(tmp[i - 1], tmp[i]) + 1);
        }
        ans = min(dp[m + start - 2][0], ans);
    }
    return ans;
}

class CandyCollection {
	public:
	int solve(vector <int> Type1, vector <int> Number1, vector <int> Type2, vector <int> Number2) {
        n = Type1.size();
        REP(i, n) {
            int x = Type1[i] + n;
            edge[i].push_back({x, Number1[i]});
            edge[x].push_back({i, Number1[i]});
        }
        REP(i, n) {
            int x = Type2[i] + n;
            edge[i].push_back({x, Number2[i]});
            edge[x].push_back({i, Number2[i]});
        }
        int ans = 0;
        REP(i, n) {
            if (!vis[i]) {
                m = 0;
                dfs(i, edge[i][1].first);
                ans += godp();
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
	void test_case_0() { int Arr0[] = {0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(0, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(1, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0,0,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,3,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,2,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 5; verify_case(2, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,5,10,13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {8,8,10,15}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 20; verify_case(3, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {12,9,0,16,9,18,12,3,6,0,8,2,10,6,5,2,14,10,5,13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {895,704,812,323,334,674,665,142,712,254,869,548,645,663,758,38,860,724,742,530}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,4,7,11,15,8,18,13,17,17,19,14,7,11,4,1,15,19,3,16}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {779,317,36,191,843,289,107,41,943,265,649,447,806,891,730,371,351,7,102,394}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 5101; verify_case(4, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	CandyCollection ___test;
	clock_t st = clock(), ed;

	___test.run_test(-1);
	
	ed = clock();
	cout << endl << "Time: " << fixed << setprecision(7) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
	return 0;
}
// END CUT HERE
