#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

int main() {
	ios :: sync_with_stdio(0);
	long long a;
	cin >> a;
	int bit[20] = {0};
	int len = 0;
	while (a) {
		if (a == 9) {
			bit[len++] = 9;
			break;
		}
		bit[len++] = min(a % 10, 9 - a % 10);
		a /= 10;
	}
	while (len--) {
		cout << bit[len];
	}
	cout << endl;
	

	return 0;
}


