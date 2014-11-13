int p[N], vis[N], tot;
vector<int> fac[N];

void GetPrime() {
	for (int i = 2; i < N; ++i){
		if (!vis[i]) p[tot++] = i;
		for (int j = 0; j < tot && i * p[j] < N; ++j) {
			vis[i * p[j]] = p[j];
			if (i % p[j] == 0) {
				break;
			}
		}
	}
	for (int i = 2; i < N; ++i) {
		if (!vis[i]) fac[i].push_back(i);
		else {
			int tmp = i;
			while (tmp % vis[i] == 0) {
				tmp /= vis[i];
			}
			fac[i].push_back(vis[i]);
			REP(j, fac[tmp].size()) {
				fac[i].push_back(fac[tmp][j]);
			}
		}
	}
}
//fac prime factor