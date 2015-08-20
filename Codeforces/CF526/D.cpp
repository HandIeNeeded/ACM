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
#define hash myhash

using namespace std;

const int N = 1e6 + 5;

int f[N], n, k;
char s[N];
bool good[N];

void getfail(){
	int i, j;
	f[0] = f[1] = 0;
	for (i = 1; i < n; ++i){
		j = f[i];
		while (j && s[j] != s[i]) j = f[j];
		f[i + 1] = s[j] == s[i] ? j + 1 : 0; 
	}
}

const int X1 = 4243;
const int MOD1 = 1e9 + 7;
const int X2 = 10007;
const int MOD2 = 42424243;
const int LEN = 1e6 + 5;

struct hash {
    int a, b;

    hash() {}
    hash(int a) : a(a), b(a) {}
    hash(int a, int b) : a(a), b(b) {}
};

bool operator < (const hash& a, const hash& b) {
    if (a.a != b.a) {
        return a.a < b.a;
    }
    return a.b < b.b;
}

bool operator == (const hash& a, const hash& b) {
    return a.a == b.a && a.b == b.b;
}

hash operator * (const hash& a, const hash& b) {
    return hash((1LL * a.a * b.a) % MOD1, (1LL * a.b * b.b) % MOD2);
}

hash operator + (const hash& a, const hash& b) {
    hash c(a.a + b.a, a.b + b.b);
    if (c.a >= MOD1) {
        c.a -= MOD1;
    }
    if (c.b >= MOD2) {
        c.b -= MOD2;
    }
    return c;
}

const hash X(X1, X2);
hash h[N], pw[N];

inline void init() {
    pw[0] = hash(1);
    for (int i = 1; i < LEN; ++i) {
        pw[i] = pw[i - 1] * X;
    }
}

void hashinit() {
	h[n] = {0, 0};
	for (int i = n - 1; i >= 0; i--) {
		h[i] = h[i + 1] * X + hash(s[i]);
	}
}

hash gethash(int start, int len) {
	hash tmp = h[start + len] * pw[len];
	return h[start] + hash(MOD1 - tmp.a, MOD2 - tmp.b);
}

int main() {
	ios :: sync_with_stdio(0);
	cin >> n >> k;
	cin >> s;
	if (k == 1) {
		REP(i, n) {
			cout << 1;
		}
		cout << endl;
		return 0;
	}
	getfail();
	init();
	hashinit();
	REPP(i, 1, n - 1) {
		int tot = i + 1;
		int j = f[i + 1];
		while (1) {
			int len = i + 1 - j;
			int lena = tot - k * len;
			if (lena < 0) break;
			if (lena >= 0 && lena <= len && gethash(0, len) == gethash(len, len) && gethash(k * len, lena) == gethash(0, lena)) {
				good[i] = 1;
				break;
			}
			else j = f[j];
			if (j == f[j]) break;
		}
	}
	REP(i, n) {
		cout << (good[i] ? 1 : 0);
	}
	cout << endl;

	return 0;
}
