#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int X1 = 4243;
const int MOD1 = 1e9 + 7;
const int X2 = 10007;
const int MOD2 = 1034567891;
const int N = 6e5 + 5;

struct myhash {
    int a, b;

    myhash() {}
    myhash(int a) : a(a), b(a) {}
    myhash(int a, int b) : a(a), b(b) {}
};

bool operator < (const myhash& a, const myhash& b) {
    if (a.a != b.a) {
        return a.a < b.a;
    }
    return a.b < b.b;
}

bool operator == (const myhash& a, const myhash& b) {
    return a.a == b.a && a.b == b.b;
}

myhash operator * (const myhash& a, const myhash& b) {
    return myhash((1LL * a.a * b.a) % MOD1, (1LL * a.b * b.b) % MOD2);
}

myhash operator + (const myhash& a, const myhash& b) {
    myhash c(a.a + b.a, a.b + b.b);
    if (c.a >= MOD1) {
        c.a -= MOD1;
    }
    if (c.b >= MOD2) {
        c.b -= MOD2;
    }
    return c;
}

const myhash X(X1, X2);
myhash dict[N], prefix[N], suffix[N], pw[N] = {{1, 1}};

inline void init() {
    pw[0] = myhash(1);
    for (int i = 1; i < N; ++i) {
        pw[i] = pw[i - 1] * X;
    }
}

int n, m;

bool check(string s) {
	int nn = s.size();
	REP(i, nn) {
		REP(j, 3) {
			if ('a' + j == s[i]) continue;
			else {
				myhash tmp = (i == 0 ? myhash(0) : prefix[i - 1]) + ('a' + j) * pw[i] + (i + 1 < (int) s.size() ? suffix[i + 1] : myhash(0));
				int pos = lower_bound(dict, dict + n, tmp) - dict;
				if (pos < n && dict[pos] == tmp) return 1;
			}
		}
	}
	return 0;
}

int main() {
	ios :: sync_with_stdio(0);
	init();
	cin >> n >> m;
	REP(i, n) {
		string s;
		cin >> s;
		myhash cur(0);
		REP(i, s.size()) {
			cur = cur + s[i] * pw[i];
		}
		dict[i] = cur;
	}
	sort(dict, dict + n);
	REPP(i, 1, m) {
		string s;
		cin >> s;
		REP(j, s.size()) {
			prefix[j] = (j == 0 ? myhash(0) : prefix[j - 1]) + s[j] * pw[j];
		}
		for (int j = s.size() - 1; j >= 0; j--) {
			suffix[j] = (j + 1 == (int) s.size() ? myhash(0) : suffix[j + 1]) + s[j] * pw[j];
		}
		cout << (check(s) ? "YES" : "NO") << endl;
	}


	return 0;
}
