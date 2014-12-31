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
//Segment tree
#define LC (x << 1)
#define RC ((x << 1) | 1)
#define MID ((l + r) >> 1)
#define LB(x) ((x) & (-(x)))
#define M (N - 1000)
#pragma warning (disable : 4996)
//#pragma comment(linker, "/STACK:102400000,102400000")
#define EPS 1e-8
#define INF 2000000000
#define LIM (1ll << 60)
#define MOD 1000000007
#define N 111

using namespace std;

int n, m, now;
int mp[7][7], x[N], y[N], vis[N], cnt[7], ans[N];

void dfs(int x) {
	REPP(i, 0, 6) {
		if (mp[x][i]) {
			mp[x][i]--, mp[i][x]--;
			dfs(i);
		}
	}
	ans[now++] = x;
}


int main(){
	int t, i, j, k, a, b, ca = 1, re = 0, st = 0;
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios :: sync_with_stdio(false);
	RI(n);
	REPP(i, 1, n) {
		RII(a, b);
		x[i] = a, y[i] = b;
		mp[a][b]++, mp[b][a]++;
		cnt[a]++, cnt[b]++;
	}
	REPP(i, 0, 6) if (cnt[i] & 1) re++, st = i;
	if (re != 0 && re != 2) {
		puts("No solution");
		return 0;
	}
	if (re == 0) {
		REPP(i, 0, 6) if (cnt[i]) st = i;
	}
	now = 1;
	dfs(st);
	REPP(i, 0, 6) REPP(j, 0, 6) if (mp[i][j]) {
		puts("No solution");
		return 0;
	}
	REPP(i, 1, n) {
		int xx = ans[i], yy = ans[i + 1];
		REPP(j, 1, n) {
			if (!vis[j]) {
				if (xx == x[j] && yy == y[j]) {
					printf("%d +\n", j);
					vis[j] = 1;
					break;
				}
				else if (xx == y[j] && yy == x[j]) {
					printf("%d -\n", j);
					vis[j] = 1;
					break;
				}
			}
		}
	}

	return 0;
}
