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
const int N = 105;
using namespace std;

LL a[N], d[N], c[N];

LL gcd(LL a, LL b){return b ? gcd(b, a % b) : a;}

void exgcd(LL a, LL b, LL &d, LL &x, LL &y){
	if (!b) {d = a, x = 1, y = 0;}
	else{
		exgcd(b, a % b, d, y, x), y -= a / b * x;
	}
}

int main(){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w",stdout);*/
	LL re, n, m, i, j, k, x, y, p, b, dd;
	cin >> n >> p >> b;
	for (i = 1, d[0] = p; i <= n; ++i) cin >> a[i], a[i] %= p, d[i] = gcd(a[i], d[i - 1]);
	if (b == 0){
		cout << "YES\n";
		for (i = 0; i < n; ++i) cout << 0 << ' ';
	}
	else if (d[n] % p == 0){
		cout << "NO\n";
	}
	else if (b % d[n] == 0){
		cout << "YES\n";
		k = b / d[n];
		for (i = 1; i <= n; ++i) c[i] = k;
		for (i = n; i >= 1; --i){
			exgcd(a[i], d[i - 1], dd, x, y);
			c[i] = c[i] * x % p;
			for (j = 1; j < i; ++j){
				c[j] = c[j] * y % p;
			}
		}
		for (i = 1; i <= n; ++i) c[i] = (c[i] + p) % p;
		for (i = 1; i <= n; ++i) cout << c[i] << ' ';
	}
	else cout << "NO\n";
	return 0;
}//扩展欧几里得
//题库的数据太弱了，这个代码有问题，例如
// 5 22 6
// 4 8 12 16 20
//显然是YES 7 0 0 0 0
//但上面程序输出NO
//下面这个对的，d[0] = p, 把p放进去了，是重要条件了
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
const int N = 105;
using namespace std;

LL a[N], d[N], c[N];

LL gcd(LL a, LL b){return b ? gcd(b, a % b) : a;}

void exgcd(LL a, LL b, LL &d, LL &x, LL &y){
	if (!b) {d = a, x = 1, y = 0;}
	else{
		exgcd(b, a % b, d, y, x), y -= a / b * x;
	}
}

int main(){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w",stdout);*/
	LL re, n, m, i, j, k, x, y, p, b, dd;
	cin >> n >> p >> b;
	for (i = 1, d[0] = p; i <= n; ++i) cin >> a[i], a[i] %= p, d[i] = gcd(a[i], d[i - 1]);//*****//
	if (b == 0){
		cout << "YES\n";
		for (i = 0; i < n; ++i) cout << 0 << ' ';
	}
	else if (d[n] % p == 0){
		cout << "NO\n";
	}
	else if (b % d[n] == 0){
		cout << "YES\n";
		k = b / d[n];
		for (i = 1; i <= n; ++i) c[i] = k;
		for (i = n; i >= 1; --i){
			exgcd(a[i], d[i - 1], dd, x, y);
			c[i] = c[i] * x % p;
			for (j = 1; j < i; ++j){
				c[j] = c[j] * y % p;
			}
		}
		for (i = 1; i <= n; ++i) c[i] = (c[i] + p) % p;
		for (i = 1; i <= n; ++i) cout << c[i] << ' ';
	}
	else cout << "NO\n";
	return 0;
}//扩展欧几里得


