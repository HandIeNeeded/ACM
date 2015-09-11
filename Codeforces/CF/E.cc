#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define MST(a, b) memset(a, b, sizeof(a))
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define debug(x) cout << #x << "is: " << x << endl

#define FI first
#define SE second
#define VI vector<int>
#define VP vector<PII>
#define VS vector<string>
#define PII pair<int, int>
#define ALL(a) (a).begin(), (a).end()
#define pb push_back
#define make make_pair

const int inf = 0x3f3f3f3f;
const double eps = 1e-9;

using namespace std;

const int N = 6;
int f[N];
int p[N];

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

int main() {
	ios :: sync_with_stdio(0);

    REP(i, 4) p[i] = i;



	return 0;
}

