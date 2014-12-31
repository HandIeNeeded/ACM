#include <iostream>
#include <set>
#include <cmath>
#include <cstdio>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;
#define dou double
#define LL long long
#define N 165
#define Pi 3.14159265358979323846
#define p(x) ((x) * (x))

dou f[N], x[N], y[N];

int main(){
	int a, b, i, j, k, n;
	dou d, tem, ang, r, key, sx, sy, px, py;
	cin >> n >> a >> b;
	a--, b--;
	cin >> x[a] >> y[a] >> x[b] >> y[b];
	px = x[b], py = y[b];
	ang = -2 * Pi / n;
	d = sqrt(p(x[b] - x[a]) + p(y[b] - y[a]));
	r = d * sqrt(p(1 - cos(ang)) + p(sin(ang))) / sqrt(p(1 - cos(ang * (b - a))) + p(sin(ang * (b - a))));
	key = acos(((x[b] - x[a]) * ((1 - cos(ang)) * (1 - cos((b - a) * ang)) + sin(ang) * sin((b - a) * ang)) - ((y[b] - y[a]) * (sin((b - a) * ang) * (1 - cos(ang)) - sin(ang) * (1 - cos((b - a) * ang))))) / r / (2 - 2 * cos((b - a) * ang)));
	for (i = 1, sx = sy = 0; a + i <= b; ++i){
		px = x[a] + sx + r * cos(key + (i -  1) * ang);
		py = y[a] + sy + r * sin(key + (i - 1)* ang);
		sx += r * cos(key + (i - 1) * ang);
		sy += r * sin(key + (i - 1) * ang);
	}
	if ((px - x[b]) > 1e-6 || (py - y[b]) > 1e-6) key = -key;
	for (i = 1, sx = sy = 0; i < n; ++i){
		x[(a + i) % n] = x[a] + sx + r * cos(key + (i -  1) * ang);
		y[(a + i) % n] = y[a] + sy + r * sin(key + (i - 1)* ang);
		sx += r * cos(key + (i - 1) * ang);
		sy += r * sin(key + (i - 1) * ang);
	}
	for (i = 0; i < n; ++i){
		printf("%.6lf %.6lf\n", x[i], y[i]);
	}
	//system("pause");
	return 0;
}//用复数硬算（228题目相同）精度要求高容易搞错，特别是180这种不知道取正还是负，所以先设是正的，算出b看看和原来一样么，如果不一样变成负的
