#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 55;

vector<int> num[N];

int main() {
    freopen("easy.in", "r", stdin);
#ifndef HOME
    freopen("easy.out", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    REPP(i, 1, n) {
        int x;
        cin >> x;
        REP(j, x) {
            int y;
            cin >> y;
            num[i].push_back(y);
        }
    }
    int sum = 0, turn = 0;
    while (k) {
        REPP(i, 1, n) {
            if (k == 0) break;
            if (turn < int(num[i].size()) && sum > num[i][turn]) continue;
            if (turn >= int(num[i].size()) || sum > num[i][turn]) {
                sum += 50;
                k--;
                continue;
            }
            if (sum <= num[i][turn]) {
                sum += num[i][turn];
                //cout << num[i][turn] << ' ' << sum << endl;
                k--;
                continue;
            }
        }
        turn++;
    }
    cout << sum << endl;

    return 0;
}


