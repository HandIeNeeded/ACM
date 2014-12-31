#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define N 10005
#define mem(a) memset(a, 0, sizeof(a))
using namespace std;
struct po{
	int x, y;
	bool operator < (const po &t)const{
		if (x == t.x) return y < t.y;
		return x < t.x;
	}
}ans[N];

int gcd(int a, int b){return (!b) ? a : gcd(b, a % b);}

int main(){
	int i, n, a, b, d, c, j;
	cin >> n >> a >> b;
	d = gcd(a, n);
	c = gcd(n, b);
	i = n / d, j = n / c;
	c = i *j / gcd(i, j);
	for (i = 0; i < c; ++i) ans[i].x = i * a % n, ans[i].y = i * b % n;
	sort(ans, ans + c);
	printf("%d\n", c);
	for (i = 0; i < c; ++i) printf("%d %d\n", ans[i].x, ans[i].y);
	//system("pause");
	return 0;
}//ans[i].x = i * a % n, ans[i].y = i * b % n; 这种都满足，防止重复
