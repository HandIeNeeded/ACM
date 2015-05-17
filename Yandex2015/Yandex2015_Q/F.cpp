#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1005;
int cnt[N];
pair<int, int> p[N];

int main() {
    ios :: sync_with_stdio(0);
    int n;
    cin >> n;
    REPP(i, 1, n) cin >> p[i].first >> p[i].second;
    int m;
    cin >> m;
    REP(i, m) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    REPP(i, 1, n) {
        if (cnt[i] < p[i].first) {
            cout << "Green" << endl;
        }
        else if (cnt[i] > p[i].second) {
            cout << "Red" << endl;
        }
        else {
            cout << "Orange" << endl;
        }
    }

    return 0;
}


