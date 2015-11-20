#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 105;
long long a[N];

void Gauss(int n, int &now) {
	now = 1;
	REP(i, 60) {
		if (now > n) break;
		long long bit = 1LL << (59 - i);
		bool flag = 0;
		REPP(j, now, n) {
			if (a[j] & bit) {
				swap(a[j], a[now]);
				flag = 1;
				now++;
				break;
			}
		}
		if(flag) {
			REPP(j, 1, n) {
				if (j != now - 1 && (a[j] & bit)) {
					a[j] ^= a[now - 1];
				}
			}
		}
	}
}

int main() {
	ios :: sync_with_stdio(0);
	int n;
	cin >> n;
	REPP(i, 1, n) {
		cin >> a[i];
	}
	int now;
	Gauss(n, now);
	long long ans = 0;
	REPP(i, 1, now) ans ^= a[i];
	cout << ans << endl;
	
	return 0;
}
