#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int fac[30] = {-2, -3, -5, -7, -11, -13, -17, -19, -23, -29, -31, -37, -41, -43, -47, -53, -59, -61, -67};

ll N;
int R;
vector<int> S;

void init () {
	S.clear();
	scanf("%lld%d", &N, &R);

	for (int i = 0; abs(fac[i]) <= R; i++) {
		int tmp = S.size();
		for (int j = 0; j < tmp; j++) {
			if (abs(fac[i] * S[j]) <= 63)
				S.push_back(fac[i] * S[j]);
		}
		S.push_back(fac[i]);
	}
}

ll get(ll n) {
	if (n == 1)
		return 0;
	ll ret = n;
	for (int i = 0; i < S.size(); i++) {
		ll tmp = (ll)(pow(n + 0.5, 1.0 / abs(S[i]))) - 1;
		if (S[i] < 0)
			ret -= tmp;
		else
			ret += tmp;
	}
	return ret - 1;
}

void solve () {
	ll ret = N;
	while (true) {
		ll tmp = get(ret);
		if (tmp == N)
			break;
		ret += N - tmp;
	}
	printf("%lld\n", ret);
}

int main () {
	int cas;
	scanf("%d", &cas);
	for (int i = 1; i <= cas; i++) {
		init();
		solve();
	}
	return 0;
}
