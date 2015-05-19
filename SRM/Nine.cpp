#include <bits/stdc++.h>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)

using namespace std;

const int N = 59049;
const int MO = 1e9 + 7;

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}

int f[2][N], sum[32];
int g[5005][9];

void init(int m) {
    g[0][0] = 1;
    REPP(i, 0, m - 1) {
        REP(j, 9) {
            REP(k, 10) {
                add(g[i + 1][(j + k) % 9], g[i][j]); 
            }
        }
    }
}

int cnt[5];

void getcnt(int x) {
    REP(i, 5) {
        cnt[i] = x % 9;
        x /= 9;
    }
}

int get(int *cnt, int n) {
    int ans = 0;
    REP(i, n) {
        ans = 9 * ans + cnt[n - 1 - i];
    }
    return ans;
}

class Nine {
	public:
	int count(int n, vector <int> d) {
        MST(f, 0), MST(g, 0), MST(sum, 0);
		int m = d.size();
        REP(i, m) {
            sum[d[i]]++;
        }
        init(m);
        int cur = 0;
        f[0][0] = 1;
        REP(i, 1 << n) {
            REP(j, N) if (f[cur][j]) {
                getcnt(j);
                REP(k, 9) {
                    int tmp[5];
                    REP(ii, n) tmp[ii] = cnt[ii];
                    REP(t, n) {
                        if (i & (1 << t)) {
                            tmp[t] += k;
                            tmp[t] %= 9;
                        }
                    }
                    int ns = get(tmp, n);
                    add(f[cur ^ 1][ns], 1LL * f[cur][j] * g[sum[i]][k] % MO);
                }
            }
            MST(f[cur], 0);
            cur ^= 1;
        }
        return f[cur][0];
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 16; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {0,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 200; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arr1[] = {1,3,5,8,24,22,25,21,30,2,4,0,6,7,9,11,14,13,12,15,18,17,16,19,26,29,31,28,27,10,20,23}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 450877328; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = {31,31,31,31,31}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11112; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	Nine ___test;
	clock_t st = clock(), ed;

	___test.run_test(-1);
	
	ed = clock();
	cout << endl << "Time: " << fixed << setprecision(7) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
	return 0;
}
// END CUT HERE
