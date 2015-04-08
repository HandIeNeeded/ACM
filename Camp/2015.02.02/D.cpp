#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
const int MO = 1e9 + 7;
int p[N], vis[N], mobius[N] = {0, 1}, tot;

void prime() {
	for (int i = 2; i < N; i++) {
		if (!vis[i]) p[tot++] = i, mobius[tot - 1] = -1;
		for (int j = 0; j < tot && i * p[j] < N; j++) {
			vis[i * p[j]] = p[j];
			if (i % p[j] == 0) {
				mobius[i * p[j]] = 0;
				break;
			}
			else {
				mobius[i * p[j]] = -mobius[i];
			}
		}
	}
}

int sum(int x) {
	return 1LL * x * (x + 1) / 2 % MO;
}

int main() {
	prime();

	return 0;
}

