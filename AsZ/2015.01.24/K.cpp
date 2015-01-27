#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

struct point{
	long double x, y;

	point (long double x = 0, long double y = 0) : x(x), y(y) {}

	const point operator + (const point &a) const {
		return point(x + a.x, y + a.y);
	}

	const point operator * (long double a) const {
		return point(a * x, a * y);
	}

	const point operator - (const point &a) const {
		return point(x - a.x, y - a.y);
	}

	void print() {
		cout << x << ' ' << y << endl;
	}

}P, Q, R, A, B, C;

long double m[7];

int main() {
	ios :: sync_with_stdio(0);
	//freopen("K.in", "r", stdin);

	int t;
	cin >> t;
	while (t--) {
		cin >> P.x >> P.y >> Q.x >> Q.y >> R.x >> R.y;
		//P.print(), Q.print(), R.print();
		REPP(i, 1, 6) cin >> m[i];
		//REPP(i, 1, 6) cout << m[i] << endl;
		//cout << a << ' ' << b << ' ' << c << endl;
		long double tmp1 = m[1] * m[3] * m[5], tmp2 = m[2] * m[4] * m[6];
		point pr = (R - P) * ((tmp1 + m[4] * m[5] * (m[1] + m[2])) / (tmp2 - tmp1));
		point rq = (Q - R) * ((tmp1 + m[2] * m[3] * (m[5] + m[6])) / (tmp2 - tmp1));
		point qp = (P - Q) * ((tmp1 + m[1] * m[6] * (m[3] + m[4])) / (tmp2 - tmp1));
		A = R + pr, B = P + qp, C = Q + rq;
		cout << fixed << setprecision(8) << A.x << ' ' << A.y << ' ' << B.x << ' ' << B.y << ' ' << C.x << ' ' << C.y << endl;
	}

	return 0;
}

