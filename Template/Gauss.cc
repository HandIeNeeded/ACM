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
