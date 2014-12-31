#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <bitset>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#define dou double
#define mem(a) memset(a, 0, sizeof(a))
#define memm(a) memset(a, -1, sizeof(a))
#define LL long long
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
#define FI first
#define SE second
#define RI(a) scanf("%d", &(a))
#define RII(a, b) scanf("%d%d", &(a), &(b))
#define RIII(a, b, c) scanf("%d%d%d", &(a), &(b), &(c))
#define RL(a) scanf("%I64d", &(a))
#define RLL(a, b) scanf("%I64d%I64d", &(a), &(b))
#define RLLL(a, b, c) scanf("%I64d%I64d%I64d", &(a), &(b), &(c)) 
#define PI(r) printf("%d\n", (r))
#define PL(r) printf("%I64d\n", (r))
#define RS(s) scanf("%s", (s))
#define SL(a) strlen(a)
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define FOR(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
//Segment tree
#define MID ((l + r) >> 1)
#define L (x << 1)
#define R ((x << 1) | 1)
#define LC L, l, MID
#define RC R, MID + 1, r
#define LB(x) ((x) & (-(x)))
#pragma warning (disable : 4996)
//#pragma comment(linker, "/STACK:102400000,102400000")
#define EPS 1e-8
#define INF 2000000000
#define LIM (1ll << 60)
#define MOD 1000000007
#define N 111111

using namespace std;

int n, m, lim;
int ans;

void dfs(int col, int l, int r, int row, int cnt) {
	if (cnt == m) ans++;
	else if (row > n) return ;
	else {
		dfs(col, (l << 1) & lim, r >> 1, row + 1, cnt);
		int can = (col | l | r) ^ lim;
		while (can) {
			int pos = LB(can);
			dfs(col | pos, ((l | pos) << 1) & lim, (r | pos) >> 1, row + 1, cnt + 1);
			can &= (can - 1);
		}
	}
}

int main(){
	int t, x, y, z, ca = 1;
	//freopen("D:/Contest/in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios :: sync_with_stdio(false);
	RII(n, m);
	if (m > n) puts("0");
	else {
		lim = (1 << n) - 1;
		dfs(0, 0, 0, 1, 0);
		PI(ans);
	}

	return 0;
}
//n queen
