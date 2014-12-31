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
#define AC 0
const int Mod = 1000000007;
const int N = 12;
using namespace std;

LL a[N], cnt[1 << N], dp[N][1 << N][N * N], s[1 << N], tot, n, kk;

int dfs(int st, int cn, int h){
	for (i = h; i <= n; ++i){
		if ((st & (1 << i)) == 0 && (st & (1<< (i - 1))) == 0 && (st & (1 << (i + 1))) == 0){
			s[++tot] = st + (1 << i), cnt[tot] = cn + 1;
			dfs(st + (1 << i), cnt + 1, i + 2);
		}
	}
}

int main(){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w",stdout);*/
	LL re, mi, ma, i, j, k, t;
	cin >> n >> kk;
	dfs(0, 0, 1);
	for (i = 1; i <= tot; ++i) dp[1][s[i]][cnt[i]] = 1;
	for (i = 2; i <= n; ++i){
		for (j = 1; j <= tot; ++j)
			for (k = 1; k <= tot; ++k)
				for (t = cnt[j]; t <= kk; ++t){
					if((s[j]&s[k]) || (s[j]&(s[k]>>1)) || (s[j]&s[k]<<1)) continue; 
					else{
						if (t >= cnt[k])
							dp[i][s[j]][t] += dp[i - 1][s[k]][t - cnt[k]];
					}
				}
	}
	for (i = 1, re = 0; i <= n; ++i) re += dp[n][s[i]][kk];
	cout << re << endl;
	return AC;
}

