#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

#define PII pair<LL, LL>
set<PII> s;
const LL inf = LLONG_MAX;

PII operator + (const PII &a, const PII &b) {
    return {a.first, b.second};
}

void update(PII &a, LL pos) {
    LL length = a.second - a.first;
    a.first = pos;
    a.second = pos + length;
}

pair<PII, PII> split(PII a, PII b) {
    LL length = a.second - a.first + 1 - (b.first - a.first);
    PII res1 = {a.first, b.first - 1};
    PII res2 = {b.second + 1, b.second + 1 + length - 1};
    return {res1, res2};
}

void mergeL(PII a, PII &b) {
    if (a.second + 1 == b.first) {
        PII tmp = a + b;
        s.erase(a);
        b = tmp;
    }
}

void mergeR(PII &a, PII b) {
    if (a.second + 1 == b.first) {
        PII tmp = a + b;
        s.erase(b);
        a = tmp;
    }
}

int main() {
#ifdef HOME
    //freopen("tmp.in", "r", stdin);
#endif

    ios :: sync_with_stdio(0);
    //PII a = {1, 5}, b = {2, 4};
    //PII c, d;
    //tie(c, d) = split(a, b);
    int n;
    cin >> n;
    s.insert({-inf, -inf});
    s.insert({inf, inf});
    REPP(i, 1, n) {
        LL L, R, length;
        cin >> L >> length;
        //cout << L << ' ' << length << endl;
        R = L + length - 1;
        PII now = {L, R};
        LL last = -1;
        while (length) {
            auto pos = s.lower_bound(now);
            PII suffix = *pos;
            pos--;
            PII prefix = *pos;
            if (L <= prefix.second) {
                update(now, prefix.second + 1);
                tie(L, R) = now;
            }
            if (R >= suffix.first) {
                PII a, b;
                tie(a, b) = split(now, suffix);
                if (now.first == prefix.second + 1) {
                    PII tmp = prefix + suffix;
                    s.erase(prefix);
                    s.erase(suffix);
                    s.insert(tmp);
                }
                else {
                    mergeR(a, suffix);
                    s.insert(a);
                }
                now = b;
            }
            else {
                last = R;
                //merge with prefix
                mergeL(prefix, now);
                //merge with suffix
                mergeR(now, suffix);
                s.insert(now);
                now = {1, 0};
            }
            tie(L, R) = now;
            length = R - L + 1;
        }
        assert(last != -1);
        cout << last << endl;
        //for (auto &x: s) {
        //    cout << x.first << ' ' << x.second << endl;
        //}
        //cout << i << ' ' << "hehe" << "************************************" << endl;
    }
    return 0;
}

