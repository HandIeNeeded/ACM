#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
int tmp[N];

int main() {
	ios :: sync_with_stdio(0);
    freopen("tmp.in", "w", stdout);
	srand(time(0) % clock());
    REPP(i, 1, 300) {
		cout << rand() % 101 << ",";
    }
	return 0;
}

