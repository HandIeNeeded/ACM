#include <bits/stdc++.h>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)

using namespace std;

const int N = 55;

int pre[N], d[N], mp[N][N], g[N][N], match[N], n;
bool vis[N];
vector<int> edge[N], e[N], val[N];
vector<int> A, B;

int dfs(int x) {
	REP(i, e[x].size()) {
		int y = e[x][i];
		if (vis[y]) continue;
		vis[y] = 1;
		if (!match[y] || dfs(match[y])) {
			match[y] = x;
			return 1;
		}
	}
	return 0;
}

int H() {
	MST(match, 0);
	int ans = 0;
	REP(i, A.size()) {
		MST(vis, 0);
		ans += dfs(A[i]);
	}
	return ans;
}

void go(int x, int p, int target, int dis = 0) {
	d[x] = dis, pre[x] = p;
	if (x == target) return ;
	else {
		REP(i, edge[x].size()) {
			int y = edge[x][i];
			if (y != p) {
				go(y, x, target, dis + val[x][i]);
			}
		}
	}
}

void getf(int rt, int x) {
	int m = A.size();
	B.clear();
	REP(i, m) {
		go(A[i], 0, rt);
		int tmp = rt;
		while (tmp != A[i]) {
			if (d[tmp] > x) B.push_back(tmp);
			tmp = pre[tmp];
		}
	}
	sort(B.begin(), B.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
}

void init(int x) {
	REP(i, A.size()) e[A[i]].clear();
	REP(i, A.size()) {
		REP(j, B.size()) {
			if (g[A[i]][B[j]] <= x) {
				e[A[i]].push_back(B[j]);
			}
		}
	}
}

bool check(int x) {
	REPP(i, 1, n) {
		getf(i, x);
		init(x);
		if (H() == int(B.size())) return 1;
	}
	return 0;
}

class FoxMeeting {
    public:

	void DFS(int rt, int x, int d = 0, int p = 0) {
		g[rt][x] = d;
		REP(i, edge[x].size()) {
			int y = edge[x][i];
			if (y != p) {
				DFS(rt, y, d + val[x][i], x);
			}
		}
	}

    int maxDistance(vector <int> A, vector <int> B, vector <int> L, vector <int> foxes) {
		n = A.size() + 1;
		::A = foxes;
		REPP(i, 1, n) edge[i].clear(), e[i].clear(), val[i].clear();
		REP(i, n - 1) {
			mp[A[i]][B[i]] = mp[B[i]][A[i]] = L[i];
			edge[A[i]].push_back(B[i]), val[A[i]].push_back(L[i]);
			edge[B[i]].push_back(A[i]), val[B[i]].push_back(L[i]);
		}
		REPP(i, 1, n) {
			DFS(i, i);
		}
		int hi = 5e6, lo = -1;
		while (lo + 1 < hi) {
			int mid = (lo + hi) >> 1;
			if(check(mid)) hi = mid;
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
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(0, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(1, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 2, 3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(2, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {10,8,3,7,2,6,9,1,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,5,8,10,5,5,6,10,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {71846,10951,42265,37832,29439,95676,83661,28186,21216}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(3, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {8,15,22,24,2,25,13,26,18,4,9,29,1,12,3,16,14,21,19,27,17,7,20,10,30,11,6,5,23}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {28,28,8,8,28,28,25,2,13,24,24,22,22,29,4,22,8,4,1,24,21,14,18,16,13,21,14,1,25}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {79374,40629,43195,73589,24200,63937,35339,7598,65109,51764,11142,84017,51078,58051,81387,22035,34883,92710,52283,57337,79309,3383,41904,35839,38242,43208,82062,24676,71838}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3,5,7,9,10,14,17,19,20,21,24,25,28}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 107013; verify_case(4, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {34,14,22,9,24,19,11,37,33,21,5,30,1,43,7,31,45,27,6,12,13,35,23,47,49,50,26,40,16,10,48,25,29,15,28,46,4,20,44,17,39,32,38,2,42,8,36,3,41}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {18,18,18,14,9,34,9,24,34,11,18,14,21,21,43,1,22,7,1,30,14,33,13,18,9,5,1,1,26,19,50,33,50,40,29,48,50,37,16,40,48,14,30,22,47,37,7,50,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {22051,11109,85275,6691,43705,47374,27748,5411,62549,84079,89542,38006,82198,24083,16847,66335,3542,72495,37378,73973,85703,51682,68688,94295,31337,
90071,99317,63484,43244,99079,55857,34503,79709,82140,91137,27033,91599,61168,52345,49569,58919,38133,43361,
40718,2115,79278,88841,40966,42023}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5,12,13,18,23,27,28,29,32,33,34,35,36,37,40,42,43,47,48,49,50}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 89342; verify_case(5, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
    FoxMeeting ___test;
    clock_t st = clock(), ed;

    ___test.run_test(-1);

    ed = clock();
    cout << endl << "Time: " << fixed << setprecision(7) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
    return 0;
}
// END CUT HERE
