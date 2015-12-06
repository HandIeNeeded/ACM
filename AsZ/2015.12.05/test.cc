#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

struct Unit{
    int x, y, z;

    bool operator < (const Unit &rhs) const {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
};

map<Unit, int> mp;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif


    return 0;
}


