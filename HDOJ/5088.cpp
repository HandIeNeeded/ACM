#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1005;
long long a[N];

int Gauss(int n) {
	long long bit = 1LL << 60;
	int rank = 1;
	REP(turn, 60) {
		bit >>= 1;
		int find = 0;
		REPP(i, rank, n) {
			if (a[i] & bit) {
				find = 1;
				swap(a[rank], a[i]);
				break;
			}
		}
		if (!find) continue;
		REPP(i, 1, n) {
			if (i != rank && (a[i] & bit)) {
				a[i] ^= a[rank];
			}
		}
		rank++;
	}
    rank--;
	return rank;
}

int main() {
	ios :: sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		REPP(i, 1, n) cin >> a[i];
		if (n > 60) {
			cout << "Yes" << endl;
			continue;
		}
		int rank = Gauss(n);
		cout << (rank == n ? "No" : "Yes") << endl;
	}

	return 0;
}

