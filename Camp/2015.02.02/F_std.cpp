#include <iostream>
#include <cstring>
#include <map>

#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)

typedef long long Long;

const int N = 50;
const int MOD = (int)1e9 + 7;

int n, m;
bool choosen[N];
Long power[N + 1], a[N], b[N];
std::map <Long, Long> ways[N + 1];

int calPow(int a, int n)
{
	int result = 1;
	for (; n; n >>= 1) {
		if (n & 1) {
			result = (long long)result * a % MOD;
		}
		a = (long long)a * a % MOD;
	}
	return result;
}

int popcount[1 << 16];

Long dfs(int i, int n, Long sum)
{
	if (i < n) {
		Long result = dfs(i + 1, n, sum) + dfs(i + 1, n, sum ^ a[i]);
		if (result >= MOD) {
			result -= MOD;
		}
		return result;
	} else {
		int pc = popcount[sum & 65535] + popcount[sum >> 16 & 65535] + popcount[sum >> 32];
		return power[pc];
	}
}

int main()
{
	popcount[0] = 0;
	for (int mask = 0; mask < 1 << 16; ++ mask) {
		popcount[mask] = popcount[mask >> 1] + (mask & 1);
	}
	std::cin >> n >> m;
	for (int i = 0; i <= N; ++ i) {
		power[i] = calPow(i, m);
	}
	for (int i = 0; i < n; ++ i) {
		std::cin >> a[i];
	}
	int rank = 0;
	memset(choosen, 0, sizeof(choosen));
	for (int k = 0; k < N; ++ k) {
		int pivot = rank;
		while (pivot < n && (~a[pivot] >> k & 1)) {
			pivot ++;
		}
		if (pivot < n) {
			choosen[k] = true;
			std::swap(a[pivot], a[rank]);
			for (int i = 0; i < n; ++ i) {
				if (i != rank && (a[i] >> k & 1)) {
					a[i] ^= a[rank];
				}
			}
			rank ++;
		}
	}
	memset(b, 0, sizeof(b));
	for (int k = 0; k < N; ++ k) {
		int count = 0;
		for (int i = 0; i < n; ++ i) {
			count += a[i] >> k & 1;
		}
		if (count && !choosen[k]) {
			for (int i = 0; i < n; ++ i) {
				b[i] <<= 1;
				b[i] |= a[i] >> k & 1;
			}
		}
	}
	int result = 0;
	if (rank <= 26) {
		result = dfs(0, rank, 0LL);
	} else {
		ways[0][0] = 1;
		for (int i = 0; i < rank; ++ i) {
			for (int count = i; count >= 0; -- count) {
				foreach (it, ways[count]) {
					const Long &mask = it->first;
					ways[count + 1][mask ^ b[i]] += it->second;
				}
			}
		}
		for (int count = 0; count <= rank; ++ count) {
			foreach (it, ways[count]) {
				const Long &mask = it->first;
				int pc = __builtin_popcountll(mask);
				result += (long long)power[pc + count] * (it->second % MOD) % MOD;
				if (result >= MOD) {
					result -= MOD;
				}
			}
		}
	}
	for (int i = rank; i < n; ++ i) {
		result <<= 1;
		if (result >= MOD) {
			result -= MOD;
		}
	}
	std::cout << result << std::endl;
	return 0;
}

