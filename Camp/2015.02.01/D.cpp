#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

struct point{
	double x, y;
};

double sqr(double x) {
	return x * x;
}

double dis(point a, point b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

int main() {
	//freopen("D.in", "r", stdin);
	point a, b, c;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;
	cout << fixed << setprecision(10) << dis(a, c) + 2 * dis(b, c) << endl;

	return 0;
}
