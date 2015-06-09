#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
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
#define REP(i, a) REPP(i, 0, a - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define hash myhash

using namespace std;

const int N = 4005;

int f[N][26], cnt[N];
char s[N];
pair<int, int> res;

const int X1 = 4243;
const int MOD1 = 1e9 + 7;

struct hash {
    int a;
    hash() {}
    hash(int a) : a(a) {}
}pw[N], h[N];

map<hash, int> mp;

bool operator < (const hash& a, const hash& b) {
	return a.a < b.a;
}

bool operator == (const hash& a, const hash& b) {
    return a.a == b.a;
}

hash operator * (const hash& a, const hash& b) {
    return hash((1LL * a.a * b.a) % MOD1);
}

hash operator + (const hash& a, const hash& b) {
    hash c(a.a + b.a);
    if (c.a >= MOD1) {
        c.a -= MOD1;
    }
    return c;
}

const hash X(X1);

inline void init() {
    pw[0] = hash(1);
    for (int i = 1; i < N; ++i) {
        pw[i] = pw[i - 1] * X;
    }
}

int main() {
    ios :: sync_with_stdio(0);
    freopen("pattern.in", "r", stdin);
    freopen("pattern.out", "w", stdout);

	init();
    cin >> (s + 1);
    int n = strlen(s + 1);
	REPP(i, 1, n) cnt[i] = 'a';
    int ans = n;
	res = {1, 2};
	REPP(i, 1, n) {
		f[i][s[i] - 'a'] = cnt[i]++;
		h[i] = hash(f[i][s[i] - 'a']);
	}
	REPP(j, 2, n) {
		REPP(i, 1, n) {
			if (i + j - 1 > n) {
				break;
			}
			else {
				int k = i + j - 1;
				if (f[i][s[k] - 'a'] == 0) {
					f[i][s[k] - 'a'] = cnt[i]++;
				}
				h[i] = h[i] * X + hash(f[i][s[k] - 'a']);
				mp[h[i]]++;
			}
		}
		int mx = -1;
		hash tmp(0);
		for (auto &h: mp) {
			if (h.second > mx) {
				mx = h.second;
				tmp = h.first;
			}
		}
		if (ans < mx * j) {
			ans = mx * j;
			REPP(i, 1, n) if (i + j - 1 <= n) {
				if (h[i] == tmp) {
					res = {i, i + j};
					break;
				}
			}
		}
		mp.clear();
	}
	for (int i = res.first; i < res.second; i++) {
		cout << s[i];
	}
	cout << endl;

    return 0;
}
