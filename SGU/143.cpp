#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<stack>
#include<deque>
#include<list>
#include<set>
#include<vector>
#include<iomanip>
#include<cctype>
#include<string>
#include<memory>
#include<map>
#include<sstream>
#pragma warning (disable : 4996)
#define mem(a) memset(a, 0, sizeof(a))
#define sl(a) strlen(a)
#define LL long long
#define dou double
const int Mod = 1000000007;
const int N = 17777;
using namespace std;

int fi[N], ne[2 * N], en[2 * N], tot, dm[N], v[N], s[N];

void add(int x, int y){
	ne[++tot] = fi[x], fi[x] = tot, en[tot] = y;
}

void dfs(int x, int p){
	dm[x] = v[x], s[x] = v[x];
	for (int go = fi[x]; go; go = ne[go]){
		if (en[go] != p){
			dfs(en[go], x);
			dm[x] = max(dm[x], dm[x] + dm[en[go]]);
			s[x] = max(s[x], s[x] + s[en[go]]);
		}
	}
}

void dfs1(int x, int p){
	for (int go = fi[x]; go; go = ne[go]){
		if (en[go] != p){
			if (s[en[go]] >= 0) dm[en[go]] = max(s[x] - s[en[go]] + dm[x] , dm[x]), s[en[go]] = s[x];
			else dm[en[go]] = max(s[x] + dm[x], dm[x]), s[en[go]] += s[x];
			dfs1(en[go], x);
		} 
	}
}

int main(){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w",stdout);*/
	int re, n, m, i, j, k, x, y;
	ios :: sync_with_stdio(false);
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> v[i];
	for (i = 0; i < n - 1; ++i){
		cin >> x >> y;
		add(x, y), add(y, x);
	}
	dfs(1, 0);
	dfs1(1, 0);
	for (i = 1, re = 0; i <= n; ++i){
		re = max(dm[i], re);
	}
	cout << re << endl;
	return 0;
}//树DP

