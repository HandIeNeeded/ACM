#include <iostream>
#include <set>
#include <cmath>
#include<cstdlib>
#include <cstdio>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;
#define dou double
#define LL long long
#define N 10005

LL  gcd(LL a, LL b){return (!b) ? a : gcd(b, a % b);}

int main(){
    	LL n, m, re = 1, tem, fl = 0, d;
    	cin >> n >> m;
    	d = gcd(n, m);
    	n /= d, m /= d;
    	if (n * m == 0) printf("0\n");
    	else{
                if ((n + m) & 1){
                        printf("-1\n");
                }
                else{
                        while (n != m){
                                if (n > m){
                                        n -= m;
                                        m = 2 * m;
                                        while ((n & 1) == 0 && (m & 1) == 0) n >>= 1, m >>= 1;
                                        if (((n * m) & 1) == 0) {
                                                fl = 1; break;
                                        }
                                        re++;
                                }
                                else {
                                        tem = n, n = m, m = tem;
                                        n -= m;
                                        m = 2 * m;
                                        while ((n & 1) == 0 && (m & 1) == 0) n >>= 1, m >>= 1;
                                        if (((n * m) & 1) == 0) {
                                                fl = 1; break;
                                        }
                                        re++;
                                }
                        }
                        if (fl) printf("-1\n");
                        else printf("%lld\n", re);
                }
    	}
    	//system("pause");
    	return 0;
}
