#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
int tmp[N];
int f[N], vis[N];

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

int main() {
	ios :: sync_with_stdio(0);
	srand(time(0) % clock());
    
    cout << 2 << endl;
    REP(i, 2) {

    int n = 10000;
    cout << n << endl;
    int cnt = n;
    REPP(i, 1, n) f[i] = i;
    while (cnt > 1) {
        int x = rand() % n + 1, y = rand() % n + 1;
        int tx = find(x), ty = find(y);
        if (tx != ty) {
            f[tx] = ty;
            cnt--;
            cout << x << ' ' << y << ' ' << rand() % 10000 + 1 << endl;
        }
    }
    int m = 10000;
    while (m--) {
        int ty = rand() & 1;
        if (ty) {
            cout << "Query " << rand() % n + 1 << ' ' << rand() % n + 1 << endl;
        }
        else {
            cout << "Change " << rand() % (n - 1) + 1 << ' ' << rand() % 10000 + 1 << endl;
        }
    }
    cout << "Done" << endl;
    }
	return 0;
}

