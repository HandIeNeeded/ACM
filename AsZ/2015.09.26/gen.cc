#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 1e5 + 5;
int tmp[N];

const int M = 8;
int p[N], vis[N], tot;

void prime() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) p[tot++] = i;
        for (int j = 0; j < tot && i * p[j] < N; j++) {
            vis[i * p[j]] = p[j];
            if (i % p[j] == 0) break;
        }
    }
}

int main() {
	ios :: sync_with_stdio(0);
    //freopen("tmp.in", "w", stdout);
	srand(time(0) % clock());
    prime();
    int t = 2;
    REP(i, t) {
        int mod = p[rand() % 30 + 1];
        int a = rand() % 100, b = rand() % 100, c = rand() % 100;
        cout << mod << ' ' << a << ' ' << b << ' ' << c << endl;
    }
	return 0;
}

