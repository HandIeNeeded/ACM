#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define mem(a) memset(a, 0, sizeof(a))
#define EPS 1e-7

using namespace std;

const int N = 4;
const long double  pi = acos(-1);

struct Matrix{
    long double  a[N][N];

    Matrix (bool ident = 0) {
        mem(a);
        if (ident) {
			REP(i, N) a[i][i] = 1.0;
        }
    }

    long double * operator [] (int i) {
		return a[i];
    }

    const long double * operator [] (int i) const {
        return a[i];
    }
};

Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix c;
    REP(i, N) REP(j, N) REP(k, N) {
        c[i][j] += a[i][k] * b[k][j];
	}
	return c;
}

Matrix qp(Matrix a, int n) {
    Matrix ans(1);
    while (n) {
        if (n & 1) ans = ans * a;
        n >>= 1;
        a = a * a;
    }
    return ans;
}

Matrix Init_scale(long double  a, long double  b, long double  c) {
	Matrix ans;
    ans[0][0] = a, ans[1][1] = b, ans[2][2] = c, ans[3][3] = 1.0;
    return ans;
}

Matrix Init_trans(long double  a, long double  b, long double  c) {
	Matrix ans(1);
	ans[3][0] = a, ans[3][1] = b, ans[3][2] = c;
	return ans;
}

long double  sqr(long double  x) { return x * x; }

Matrix Init_rotate(long double  a, long double  b, long double  c, long double  d) {
    d = d * pi / 180.0;
    long double  norm = sqrt(sqr(a) + sqr(b) +sqr(c));
    long double  x = a / norm, y = b / norm, z = c / norm, cosd = cos(d), sind = sin(d);
    Matrix ans;
    ans[0][0] = cosd + (1 - cosd) * sqr(x);
    ans[1][0] = (1 - cosd) * x * y - sind * z;
    ans[2][0] = (1 - cosd) * x * z + sind * y;
    ans[0][1] = (1 - cosd) * y * x + sind * z;
    ans[1][1] = cosd + (1 - cosd) * sqr(y);
    ans[2][1] = (1 - cosd) * y * z - sind * x;
    ans[0][2] = (1 - cosd) * z * x - sind * y;
    ans[1][2] = (1 - cosd) * z * y + sind * x;
    ans[2][2] = cosd + (1 - cosd) * sqr(z);
    ans[3][3] = 1.0;
    return ans;
}

Matrix go() {
    Matrix ans(1);
    string s;
    long double  a, b, c, d;
    int k;
	while (cin >> s) {
		if (s == "end") return ans;
		else if (s == "translate") {
			cin >> a >> b >> c;
			ans = ans * Init_trans(a, b, c);
		}
		else if (s == "scale") {
            cin >> a >> b  >> c;
            ans = ans * Init_scale(a, b, c);
		}
		else if (s == "rotate") {
            cin >> a >> b >> c >> d;
            ans = ans * Init_rotate(a, b, c, d);
		}
		else if (s == "repeat") {
			cin >> k;
			ans = ans * qp(go(), k);
		}
	}
	return ans;
}

int main(){
	//freopen("G.in", "r", stdin);
    ios :: sync_with_stdio(0);

	long double  a[3];
	int n;
	int flag = 0;
	while (cin >> n, n) {
        Matrix func = go();
        Matrix ans, tmp;
        tmp[0][3] = 1.0;
        REP(k, n) {
            REP(i, 3) cin >> tmp[0][i];
			ans = tmp * func;
			REP(i, 3) if (fabs(ans[0][i]) < EPS) ans[0][i] = 0.0;
			REP(i, 3) {
				cout << fixed << setprecision(2) << ans[0][i] << " \n"[i == 2];
			}
        }
        cout << endl;
	}

	return 0;
}
