#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

int main() {
	ios :: sync_with_stdio(0);

	int L, S1, S2, Q;
	cin >> L >> S1 >> S2 >> Q;
	if (S1 > S2) swap(S1, S2);
	while (Q--) {
		long long S;
		cin >> S;
		double x = sqrt(1.0 * S);
		x = 1.0 * L - x;
		cout << fixed << setprecision(10) << sqrt(2.0) * x / (S2 - S1) << endl;
	}

	return 0;
}
