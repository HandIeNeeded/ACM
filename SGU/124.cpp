#include<iostream>
#include<cstdio>
#include<cmath>
#pragma warning (disable : 4996)
using namespace std;
#define dou double
#define N 10005
#define eps 1e-6

dou sx[N], sy[N], ex[N], ey[N], x, y;

int main(){
	int n, i, j, k, cnt = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i){
		scanf("%lf%lf%lf%lf", sx + i, sy + i, ex + i, ey + i);
	}
	scanf("%lf%lf", &x, &y);
	for (i =0; i < n; ++i)
		if (abs(sx[i] - ex[i]) < eps && abs(sx[i] - x) < eps && (max(sy[i], ey[i]) - y) > -eps && (min(sy[i], ey[i]) - y) < eps) {
			printf("BORDER\n"); 
			return 0;
		}
	x += 0.1;
	for (i = 0; i < n; ++i){
		if ((sx[i] - ex[i]) < eps && sx[i] > x + 0.1){
			if (sx[i] - x + y >= min(sy[i], ey[i]) && max(sy[i], ey[i]) >= sx[i] - x + y) {
				cnt++;
			}
		}
		else if ((sy[i] - ey[i]) < eps && sy[i] > y + 0.1){
			if (sy[i] - y + x >= min(sx[i], ex[i]) && max(sx[i], ex[i]) >= sy[i] - y + x) {
				cnt++;
			}
		}
	}
	if (cnt & 1) printf("INSIDE\n");
	else printf("OUTSIDE\n");
	return 0;
}//射线法，有刚好穿过两边交点的情况，WA#16，所以一个方向移动一小段距离，dou处理
//也可以转角法