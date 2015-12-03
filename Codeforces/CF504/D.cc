#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 2005;
const int L = 605;

bitset<N> num[N];
vector<bitset<N>> g, f;
char s[L];

pair<vector<int>, int> divide(vector<int> &a) {
    vector<int> ans;
    int step = 0;
    REP(i, a.size()) {
        int x = (a[i] + step * 10) % 2;
        ans.push_back((a[i] + step * 10) / 2);
        step = x;
    }
    reverse(ans.begin(), ans.end());
    while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
    reverse(ans.begin(), ans.end());
    return {ans, step};
}

void get(vector<int> &a, int id) {
    int now = 0;
    while (a.size() > 1 || a[0] != 0) {
        int x;
        tie(a, x) = divide(a);
        num[id].set(now++, x);
    }
}

void Gauss(int n) {
    int bit = N - 1;
    bitset<N> now = num[n], need;
    need.reset();
    //cout << "xixi " << n << ' ' << now.to_string() << ' ' << need.to_string() << endl;
    REP(i, n) {
        while (bit >= 0 && !g[i].test(bit)) bit--;
        if (bit < 0) break;
        if (now.test(bit)) {
            now ^= g[i];
            need ^= f[i];
        }
    }
    if (now.any()) {
        puts("0");
        int bit = N - 1;
        int pos = N - 1, find = 0;
        while (pos >= 0 && !now.test(pos)) pos--;
        REP(i, n) {
            while (bit > pos && !g[i].test(bit)) bit--;
            if (bit == pos) {
                find = 1;
                pos = i;
                break;
            }
        }
        if (!find) pos = n;
        need.set(n);
        g.insert(g.begin() + pos, now);
        f.insert(f.begin() + pos, need);
    }
    else {
        printf("%d", int(need.count()));
        REP(i, N) if (need.test(i)) {
            printf(" %d", i);
        }
        puts("");
        need.set(n);
        g.push_back(now), f.push_back(need);
    }
}

int main() {
#ifdef HOME
    freopen("D.in", "r", stdin);
#endif

    cerr << "hehe" << endl;
    int n;
    cin >> n;
    REP(i, n) {
        scanf("%s", s);
        int n = strlen(s);
        vector<int> tmp;
        REP(i, n) tmp.push_back(s[i] - '0');
        get(tmp, i);
        //cout << num[i].to_string() << endl;
    }
    REP(i, n) {
        Gauss(i);
        //REP(i, g.size()) {
        //    cout << g[i].to_string() << ' ' << f[i].to_string() << endl;
        //}
        //cout << "***************************************************" << endl;
    }
    return 0;
}


