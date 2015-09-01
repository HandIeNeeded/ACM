#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;
const int MO = 1e9 + 7;

int pow_mod(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = 1LL * ans * a % MO;
		b >>= 1;
		a = 1LL * a * a % MO;
	}
	return ans;
}

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int main() {
#ifdef HOME
    freopen("K.in", "r", stdin);
#endif

    int t;  
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int even = n / 2, odd = n - even;
        if (n == 1) {
            puts("0");
        }
        else {
            int tmp = 1LL * (pow_mod(2, even) + MO - 1) * pow_mod(2, odd - 1) % MO;
            add(tmp, pow_mod(2, odd - 1));
            add(tmp, MO - 1);
            printf("%d\n", tmp);
        }
    }

    return 0;
}

