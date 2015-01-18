#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define LL long long
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

LL n, m;
const int N = 160;
const int MOD = 1e9 + 7;

struct Matrix{
	LL a[N][N];

	Matrix (bool ident = 0) {
		MST(a, 0);
		if (ident) REP(i, N) a[i][i] = 1;
	}

    LL* operator [] (int i) {
		return a[i];
    }

    const LL* operator [] (int i) const {
		return a[i];
    }
}F;

Matrix mul(const Matrix &a, const Matrix &b, int N) {
	Matrix ans;
	REP(i, N) REP(j, N) REP(k, N) {
		ans[i][j] += a[i][k] * b[k][j] % MOD;
		if (ans[i][j] >= MOD) ans[i][j] -= MOD;
	}
	return ans;
}

Matrix quick_pow(Matrix a, LL b, int n) {
    Matrix ans(1);
    while (b) {
		if (b & 1) ans = mul(ans, a, n);
		b >>= 1;
		a = mul(a, a, n);
    }
    return ans;
}

const int C = 4;

struct AC_Automation{
	int tr[N][C], fail[N], val[N];
	int node;

	int New_Node() {
		MST(tr[node], 0);
		fail[node] = val[node] = 0;
		return node++;
	}

	void Init() {
		node = 0;
		New_Node();
	}

	void insert(char *s) {
		int pos = 0, now = 0, x;
		while (s[pos]) {
			x = s[pos++] - 'a';
			if (!tr[now][x]) {
				tr[now][x] = New_Node();
				val[tr[now][x]] = val[now];
			}
			now = tr[now][x];
		}
		val[now] = 1;
	}

    void getfail() {
		queue<int> q;

		REP(i, C) {
			if (tr[0][i]) {
				fail[tr[0][i]] = 0;
				q.push(tr[0][i]);
			}
		}

		while (!q.empty()) {
            int x = q.front(); q.pop();
            REP(i, C) {
				int &y = tr[x][i];
				if (!y) {
					y = tr[fail[x]][i];
					continue;
				}
				q.push(y);
				fail[y] = tr[fail[x]][i];
				val[y] |= val[fail[y]];
            }
		}
    }

	void getMatrix(Matrix &a) {
		MST(a.a, 0);
        REP(i, node) if (!val[i]) {
			REP(j, C) {
				int tmp = tr[i][j];
				if (val[tmp]) continue;
				a[i][tmp]++;
			}
        }
	}
}AC;

char s[N];

int main(){
	ios :: sync_with_stdio(0);

	int t;

	cin >> t;
	while (t--) {
		cin >> n >> m;
		AC.Init();
		REP(i, m) {
			cin >> s;
			AC.insert(s);
		}
		AC.getfail();
        AC.getMatrix(F);
		int node = AC.node;

        Matrix ans;
        ans[0][0] = 1;
        ans = mul(ans, quick_pow(F, n, node), node);
		int answer = 0;
		REP(i, AC.node) {
			answer += ans[0][i];
			answer %= MOD;
		}
        cout << answer << endl;
	}

	return 0;
}
