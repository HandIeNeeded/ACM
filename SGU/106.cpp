#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#define ceil_div(a,b) ceil(double(a)/double(b))
#define floor_div(a,b) floor(double(a)/double(b))
#pragma warning (disable : 4996)
#define N 70
#define LL long long
using namespace std;

void exgcd(LL a, LL b, LL &d, LL &x, LL &y){
	if (!b) d = a, x = 1, y = 0;
	else {exgcd(b, a % b, d, y, x), y -= x * (a / b);}
}

int main(){
	/*freopen("in.txt", "r", stdin);
	freopen("myout.txt", "w", stdout);*/
	LL a, b, c, d, x1, x2, y1, y2, re, x, y, s1, e1, s2, e2, t;
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d", &a, &b, &c, &x1, &x2, &y1, &y2);
	if (x2 < x1 || y2 < y1) {printf("0\n");return 0;}
	if (a == b && b == 0){
		if (c == 0) printf("%I64d\n", (x2 - x1 + 1) * (y2 - y1 + 1));
		else printf("0\n");
	}
	else if (a == 0){
		if (c % b == 0 && -c / b >= y1 && -c / b <= y2) printf("%I64d\n", x2 - x1 + 1);
		else printf("0\n"); 
	}
	else if (b == 0 ){
		if (c % a == 0 && -c / a >= x1 && -c / a <= x2) printf("%I64d\n", y2 - y1 + 1);
		else printf("0\n"); 
	}
	else{
		exgcd(a, b, d, x, y);
		d = abs(d);
		if (c % d) printf("0\n");
		else{
			c = -c;
			a /= d, b /= d, c/= d;
			x *= c, y *= c;
			if (b > 0) s1 = ceil_div(x1 - x, b), e1 = floor_div(x2 - x, b);
			else e1 = floor_div(x1 - x, b), s1 = ceil_div((x2 - x), b);
			if (a > 0) s2 = ceil_div(y - y2, a), e2 = floor_div(y - y1 , a);
			else e2 = floor_div(y - y2, a), s2 = ceil_div((y - y1) , a);
			re = min(e2, e1) - max(s1, s2);
			if (re >= 0) re++;
			else re = 0;
			printf("%I64d\n", re);
		}
	}	
	return 0;
}
