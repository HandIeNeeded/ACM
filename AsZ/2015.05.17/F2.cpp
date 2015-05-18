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

const int N = 10005;
int vis[N] = {0, 1, 0};

int main() {
    ios :: sync_with_stdio(0);
    REPP(i, 3, N - 1) {
        int x = sqrt(i);
        REPP(j, 1, x) {
            if (!vis[i - j]) {
                vis[i] = 1;
                break;
            }
        }
        if (!vis[i]) cout << i << endl;
    }


    return 0;
}


