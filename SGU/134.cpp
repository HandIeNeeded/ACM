#include<map>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include <cstdio>
using namespace std;
#define N 17111
#define Mod 10007
#define mem(a) memset(a, 0, sizeof(a))

int fi[N], ne[2 * N], en[2 * N], tot, q[N], d[N], s[N], cnt, re[N], ans;

void add(int x, int y){
	ne[++tot] = fi[x], fi[x] = tot, en[tot] = y;
}

void dfs(int x, int p){
	s[x] = 1, d[x] = 0;
	for (int go = fi[x]; go; go = ne[go]){
		if (en[go] != p){
			dfs(en[go], x);
			s[x] += s[en[go]];
			d[x] = max(d[x], s[en[go]]);
		}
	}
}

void dfs1(int x, int p){
	for (int go = fi[x]; go; go = ne[go]){
		if (en[go] != p){
			d[en[go]] = max(d[en[go]], s[x] - s[en[go]]);
			s[en[go]] = s[x];
			dfs1(en[go], x);
		}
	}
}


int main(){
	int n, i, j, k, x, y;
	ios :: sync_with_stdio(false);
	cin >> n;
	for (i = 0; i < n - 1; ++i) {
		cin >> x >> y;
		add(x , y), add(y, x);
	}
	dfs(1, 0);
	//for (i = 1; i <= n; ++i) cout << i << ' ' << s[i] << ' ' << d[i] << endl;
	dfs1(1, 0);
	//for (i = 1; i <= n; ++i) cout << i << ' ' << s[i] << ' ' << d[i] << endl;
	for (i = 1, ans = n + 1; i <= n; ++i) ans = min(ans, d[i]);
	for (i = 1; i <= n; ++i) if (d[i] == ans) re[cnt++] = i;
	cout << ans << ' ' << cnt << endl;
	for (i = 0; i < cnt; ++i) cout << re[i] << ' ';
	//system("PAUSE");
	return 0;
}
