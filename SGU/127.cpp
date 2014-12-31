#include <iostream>
#include <set>
#include <cmath>
#include <cstdio>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;
#define dou double
#define N 10005

int a[N], s[10];

int main(){
    	int n, re = 2, m, i, j;
    	cin >> n >> m;
    	for (i = 0; i < m; ++i) cin >> a[i];
    	sort(a, a + m);
    	for (i = 0; i < m; ++i) s[a[i] / 1000]++;
    	for (i = 1; i < 10; ++i){
    		if (i != 8){
    			re += ceil((dou) s[i] / n);
    		}
    	}
    	printf("%d\n", re);
    	return 0;
}