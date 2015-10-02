#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define PII pair<int, int>

using namespace std;

void exgcd( LL a, LL b, LL &d, LL &x, LL &y){
	if (!b) d = a, x = 1, y = 0;
	else exgcd(b, a % b, d, y, x), y -= (a / b) * x;
}

//p^k, 2*p^k, 2, 4
int phi, p;

vector<int> fac;

int pow_mod(int x, int y, int mod) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1LL * ans * x % mod;
		y >>= 1;
		x = 1LL * x * x % mod;
	}
	return ans;
}

void getfac(int phi) {
    fac.clear();
	for (int i = 2; i * i <= phi; i ++) {
		if (phi % i == 0) {
			fac.push_back(i);
			while (phi % i == 0) {
				phi /= i;
			}
		}
	}
	if (phi > 1) fac.push_back(phi);
}

int primitive_root(int p) {
	phi = p - 1, getfac(phi);
	REPP(g, 1, p - 1) {
		bool bad = 0;
		REP(i, fac.size()) {
			if (pow_mod(g, phi / fac[i], p) == 1) {
				bad = 1;
				break;
			}
		}
		if (!bad) return g;
	}
	return -1;
}

int main() {
#ifdef HOME
    //freopen("11.in", "r", stdin);
#endif

    int ca = 1;
    int k1, b1, k2;
    while (scanf("%d%d%d%d", &p, &k1, &b1, &k2) > 0) {
        vector<PII> ans;
        printf("Case #%d:\n", ca++);
        if (p == 2) {
            puts("1 1");
        }
        else {
            int g = primitive_root(p);
            int half = phi >> 1;
            REP(i, phi) {
                int mod = phi;
                int lhs = (k1 + b1) % mod;
                int rhs = (i + half) % mod;
                int d = __gcd(lhs, mod);
                if (rhs % d) {
                    continue;
                }
                else {
                    lhs /= d, rhs /= d, mod /= d;
                    LL a, b, c;
                    exgcd(lhs, mod, a, b, c);
                    b = 1LL * rhs * b % mod;
                    if (b < 0) b += mod;
                    REP(j, d) {
                        if (1LL * k1 * b % phi != 1LL * k2 * i % phi) {
                            b += mod;
                            continue;
                        }
                        ans.push_back({pow_mod(g, b, p), pow_mod(g, i, p)});
                        b += mod;
                    }
                }
            }
            if (ans.size() == 0) {
                puts("-1");
            }
            else {
                sort(ans.begin(), ans.end());
                for (auto &p: ans) {
                    printf("%d %d\n", p.first, p.second);
                }
            }
        }
    }
    return 0;
}

