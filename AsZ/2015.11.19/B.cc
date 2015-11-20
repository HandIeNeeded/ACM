#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 32;

string get(int x) {
    string s;
    while (x) {
        s += (x & 1) + '0';
        x >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}

bool vis[N];

void getNext(string &s) {
    string r = s;
    for (int i = 1; i < s.size() - 1; i++) {
        s[i] = (r[i - 1] != r[i + 1] ? '1' : '0');
    }
}

int getNum(string s) {
    int ans = 0;
    REP(i, s.size()) {
        ans = 2 * ans + s[i] - '0';
    }
    return ans;
}

bool good(int i) {
    memset(vis, 0, sizeof(vis));
    int now = i;
    while (!vis[now]) {
        vis[now] = 1;
        string s = '0' + get(now) + '0';
        getNext(s);
        string r = s.substr(1);
        r.pop_back();
        now = getNum(r);
    }
    return now == 0;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    REP(i, N) {
        cout << i << '\t' << get(i) << '\t' << (good(i) ? "YES" : "NO") << endl;
    }


    return 0;
}


