#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)

using namespace std;

int quick_pow(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) {
			ans  = 1LL * ans * a % MOD;
		}
		b >>= 1;
		a = 1LL * a * a * MOD;
	}
	return ans;
}

int main(){

	
	return 0;
}

