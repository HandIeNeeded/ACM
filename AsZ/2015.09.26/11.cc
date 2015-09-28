#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define PII pair<int, int>

using namespace std;

const int N = 2e5 + 5;

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
	for (int i = 2; i * i <= phi; i++) {
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
	REPP(g, 2, p - 1) {
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

vector<PII> ans;

int main() {
#ifdef HOME
    freopen("11.in", "r", stdin);
#endif

    int ca = 1;
    int k1, b1, k2;
    while (scanf("%d%d%d%d", &p, &k1, &b1, &k2) > 0) {
        ans.clear();
        printf("Case #%d:\n", ca++);
        if (p == 2) {
            puts("1 1");
        }
        else {
            int g = primitive_root(p);
            //cout << "p: " << p << endl;
            //cout << "phi: " << phi << endl;
            //cout << "g: " << g << endl;
            //REP(i, phi) {
            //    cout << i << ' ' << pow_mod(g, i, p) << endl;
            //}
            if (g < 0) {
                cout << 1 / 0 << endl;
            }
            int d1 = __gcd(k1, phi), d2 = __gcd(k2, phi);
            //cout << "d: " << d1 << ' ' << d2 << endl;
            int t1 = phi / d1, t2 = phi / d2;
            //cout << "t: " << t1 << ' ' << t2 << endl;
            int a = 1, A = pow_mod(g, t2, p), B = pow_mod(g, t1, p);
            b1 %= phi;
            for (int i = 0; i < phi; i += t2) {
                int b = 1;
                for (int j = 0; j < phi; j += t1) {
                    if (1LL * b1 * j % phi == (phi / 2 + i) % phi) {
                        ans.push_back({b, a});
                    }
                    b = 1LL * b * B % p;
                }
                a = 1LL * a * A % p;
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

