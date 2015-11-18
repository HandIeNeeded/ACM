#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

vector<LL> A, B, C;

vector<LL> solve1(LL x) {
    auto pos = lower_bound(A.begin(), A.end(), x);
    if (*pos == x) return {x};
    pos = lower_bound(B.begin(), B.end(), x);
    if (*pos == x) return {x};
    return {-1};
}

vector<LL> solve2(LL x) {
    for (auto &a: A) {
        if (a > 1) {
            LL b = x - a;
            auto pos = lower_bound(B.begin(), B.end(), b);
            if (*pos == b) {
                return {a, b};
            }
        }
    }
    return {-1};
}

vector<LL> solve4(LL x) {
    REP(i, C.size()) {
        REPP(j, i + 1, C.size() - 1) {
            if (C[j] + C[i] > x) break;
            if (C[j] % C[i] != 0) {
                if (C[j] + C[i] == x) {
                    return {C[i], C[j]};
                }
            }
        }
    }
    return {-1};
}

vector<LL> solve3(LL x) {
    for (auto &a: A) {
        for (auto &b: B) {
            LL c = x - a - b;
            if (c < 0) continue;
            auto pos = lower_bound(C.begin(), C.end(), c);
            if (*pos == c) {
                return {a, b, c};
            }
            vector<LL> tmp = solve4(c);
            if (tmp[0] > 0) {
                tmp.push_back(a);
                tmp.push_back(b);
                return tmp;
            }
        }
    }
    return {-1};
}

int main() {
#ifdef HOME
    //freopen("D.in", "r", stdin);
#endif

    //freopen("distribution.in", "r", stdin);
    //freopen("distribution.out", "w", stdout);

    REPP(i, 0, 60) A.push_back(1LL << i);
    LL now = 1;
    B.push_back(now);
    REPP(i, 1, 60) {
        if (LLONG_MAX / 3 >= now) {
            B.push_back(3 * now);
        }
        else break;
        now *= 3;
    }
    for (auto &a: A) {
        for (auto &b: B) {
            if (a > 1 && b > 1) {
                if (LLONG_MAX / a >= b) {
                    C.push_back(a * b);
                }
            }
        }
    }
    sort(C.begin(), C.end());

//    for (auto &x: C) {
//        cout << x << endl;
//    }

//    for (auto &x: B) {
//        cout << x << ' ';
//    }
//    cout << endl;

    int t;
    cin >> t;
    while (t--) {
        LL n;
        cin >> n;
        //cout << t << "hehe" << endl;
        //n = t;
        LL mul = 1;
        while (n % 2 == 0) {
            n >>= 1, mul <<= 1;
        }
        while (n % 3 == 0) {
            n /= 3, mul *= 3;
        }
        vector<LL> tmp = solve1(n);
        if (tmp[0] > 0) {
            cout << tmp.size() << endl;
            for (auto &x: tmp) {
                cout << mul * x << ' ';
            }
            cout << endl;
            continue;
        }
        tmp = solve2(n);
        if (tmp[0] > 0) {
            cout << tmp.size() << endl;
            for (auto &x: tmp) {
                cout << mul * x << ' ';
            }
            cout << endl;
            continue;
        }
        tmp = solve4(n);
        if (tmp[0] > 0) {
            cout << tmp.size() << endl;
            for (auto &x: tmp) {
                cout << mul * x << ' ';
            }
            cout << endl;
            continue;
        }
        tmp = solve3(n);
        if (tmp[0] > 0) {
            cout << tmp.size() << endl;
            for (auto &x: tmp) {
                cout << mul * x << ' ';
            }
            cout << endl;
            continue;
        }
        assert(0);
    }

    return 0;
}


