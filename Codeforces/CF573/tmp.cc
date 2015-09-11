#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < int(n); i++)

const int N = 1e5 + 5;
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
    prime();
    REP(i, 10) cout << p[i] << ' ';
    cout << endl;

    return 0;
}

