#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 600005;
const int MOD = 1e9 + 7;
int tot;
LL number[N];

void dfs(LL now, int dep, int limit) {
	if (limit == dep) {
		number[tot++] = now;
		return ;
	}
	dfs(now * 10 + 2, dep + 1, limit);
	dfs(now * 10 + 3, dep + 1, limit);
}

void Init() {
	number[tot++] = 0;
	REPP(i, 1, 18) {
		dfs(0, 0, i);
	}
	number[tot++] = 2222222222222222222LL;
}

void add(LL &x, LL y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

LL getnext(LL x) {
	LL ans = 0;
	int pos = upper_bound(number, number + tot, x) - number;
	REPP(i, 1, pos - 1) {
		add(ans, (number[i] - number[i - 1]) % MOD * (number[i] % MOD) % MOD); 
	}
	add(ans, (x - number[pos - 1]) % MOD * (number[pos] % MOD) % MOD);
	return ans;
}

LL getpre(LL x) {
	LL ans = 0;
	int pos = upper_bound(number, number + tot, x) - number;
	REPP(i, 1, pos - 1) {
		add(ans, (number[i] - number[i - 1]) % MOD * (number[i - 1] % MOD) % MOD);
	}
	add(ans, (x - number[pos - 1] + 1) % MOD * (number[pos - 1] % MOD) % MOD);
	return ans;
}

LL calculate(LL l, LL r) {
	LL ans = 0;
	ans = getnext(r);
	add(ans, MOD - getnext(l - 1));
	LL tmp = getpre(r);
	add(tmp, MOD - getpre(l - 1));
	add(ans, MOD - tmp);
	return ans;
}

int main(){
	// freopen("1416.in", "r", stdin);
	// freopen("1416.ans", "w", stdout);
	ios :: sync_with_stdio(0);
	//clock_t st = clock(), ed;

	Init();

	//ed = clock();
	//cout << 1.0 * (ed - st) / CLOCKS_PER_SEC;
	//cout << number[tot - 1] << endl;
	
	int t;
	cin >> t;
	while(t--){
		LL l, r;
		cin >> l >> r;
		cout << calculate(l, r) << endl;
	}
	//ed = clock();
	//cout << 1.0 * (ed - st) / CLOCKS_PER_SEC;

	return 0;
}
