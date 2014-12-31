#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <bitset>
#include <ctime>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <map>
#pragma warning (disable : 4996)
#define mem(a) memset(a, 0, sizeof(a))
#define dou double
#define LL long long
#define N 5
#define Mod 1000000007
#define sl(a) strlen(a)
#define eps 1e-8
#define inf 2000000000
using namespace std;

int a[N][N], ori[N][N], now[N][N], tem[N][N];

void init(){
	int i, j;
	for (i = 1; i < 4; ++i) for (j = 1; j < 4; ++j) now[i][j] = tem[i][j];
}

int check(int x, int y, int v){
	int cnt = 0;
	for (i = 1; i < 4; ++i) for (j = 1; j < 4; ++j) tem[i][j] = now[i][j];
	if (a[x - 1][y] > v) now[x][y]++, cnt++;
	else if (a[x - 1][y] < v) now[x - 1][y]++;
	if (a[x][y - 1] > v) now[x][y]++, cnt++;
	else if (a[x][y - 1] < v) now[x][y - 1]++;
	if (now[x- 1][y] > ori[x - 1][y]) {
		init(); return 0;
	}
	if (now[x][y - 1] > ori[x][y-  1]) {
		init(); return 0;
	} 
	if (cnt > ori[x][y]) {
		inti();return 0;
	}
	return 1;
}

int dfs(int st){
	int i, j, x, y, k, tem;
	if (st == 10) return 1;
	else{
		x = st / 3 + 1, y = (st - 1) % 3 + 1;
		for (i = 0; i <= 9; ++i) {
			if (check(x, y, i)) {
				a[x][y] = i;
				if (dfs(st + 1)) {
					if (now[x][y] == ori[x][y]) return 1;
				}
				else a[x][y] = 0;
			}
		}
		return 0;
	}
}

int main(){
	int n, t, ca = 1, i, j, k, cnt, re;
	//freopen("in,txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios :: sync_with_stdio(false);
	for (i = 0; i < 5; ++i) for (j = 0; j < 5; ++j) a[i][j] = -1;
	for (i = 1; i < 4; ++i) for (j = 1; j < 4; ++j) a[i][j] = 1;
	for (i = 1; i < 4; ++i) for (j = 1; j < 4; ++j) cin >> ori[i][j];
	if (dfs(1)) {
		for (i = 1; i < 4; ++i){
			for (j = 1; j < 4; ++j) cout << a[i][j] << ' ';
			cout << endl;
		}
	}
	else cout << "NO SOLUTION\n";

	return 0;
}

