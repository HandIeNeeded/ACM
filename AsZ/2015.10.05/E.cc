#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

typedef pair<LL, LL> Cof;
typedef pair<Cof, Cof> Pair;

int sgn(LL x) {
    if (x < 0) return -1;
    else if (x > 0) return 1;
    return 0;
}

LL Abs(LL x) {
    return x > 0 ? x : -x;
}

void update(Cof &a) {
    LL d = Abs(__gcd(a.first, a.second));
    a.first /= d, a.second /= d;
    if (sgn(a.first) != sgn(a.second)) {
        if(a.first > 0) a.first *= -1, a.second *= -1;
    }
    else if (sgn(a.first) == sgn(a.second)) {
        if (a.first < 0) a.first *= -1, a.second *= -1;
    }
}

bool isZero(const Cof &a) {
    return a.first == 0;
}

Cof Add(const Cof &a, const Cof &b) {
    Cof ans;
    ans.first = a.first * b.second + b.first * a.second;
    ans.second = a.second * b.second;
    update(ans);
    return ans;
}

Cof Minus(const Cof &a, const Cof &b) {
    Cof ans;
    ans.first = a.first * b.second - b.first * a.second;
    ans.second = a.second * b.second;
    update(ans);
    return ans;
}

Cof Mul(const Cof &a, const Cof &b) {
    Cof ans;
    ans.first = a.first * b.first;
    ans.second = a.second * b.second;
    update(ans);
    return ans;
}

Cof Div(const Cof &a, const Cof &b) {
    Cof ans;
    ans.first = a.first * b.second;
    ans.second = a.second * b.first;
    update(ans);
    return ans;
}

bool inverse;
Pair A, B;

Pair Add(const Pair &a, const Pair &b) {
    Pair ans;
    ans.first = Add(a.first, b.first);
    ans.second = Add(a.second, b.second);
    update(ans.first), update(ans.second);
    return ans;
}

Pair Minus(const Pair &a, const Pair &b) {
    Pair ans;
    ans.first = Minus(a.first, b.first);
    ans.second = Minus(a.second, b.second);
    update(ans.first), update(ans.second);
    return ans;
}

Pair Mul(Pair &a, Pair &b) {
    Pair ans;
    if (isZero(a.first)) swap(a, b);
    ans.first = Mul(a.first, b.second);
    ans.second = Mul(a.second, b.second);
    update(ans.first), update(ans.second);
    return ans;
}

bool Div(Pair a, Pair b) {
    Pair ans;
    if (isZero(b.first)) {
        ans.first = Div(a.first, b.second);
        ans.second = Div(a.second, b.second);
        update(ans.first), update(ans.second);
        A = ans;
        return 0;
    }
    else {
        inverse = 1;
        A = a, B = b;
        update(A.first), update(A.second);
        update(B.first), update(B.second);
        return 1;
    }
}

const LL inf = LLONG_MAX;

string str = "+-*/";
vector<Pair> ans;
Pair P1 = make_pair(make_pair(inf, inf), make_pair(1, 1)), P2 = make_pair(make_pair(inf, inf), make_pair(2, 2));

void get(char *s) {
    while (*s) {
        char c = *s++;
        if (c == ' ') continue;
        else if (str.find(c) != string :: npos) {
            Pair A, B, C;
            vector<Pair> use;
            int lenB = ans.back().second.second;
            ans.pop_back();
            REP(i, lenB) {
                use.push_back(ans.back());
                ans.pop_back();
            }
            int lenA = ans.back().second.second;
            ans.pop_back();
            REP(i, lenA) {
                use.push_back(ans.back());
                ans.pop_back();
            }
            if (lenA == 1 && lenB == 2) {
                A = use[2], B = use[1], C = use[0];
                if (c == '+') {
                    Pair tmp = Mul(A, C);
                    B = Add(B, tmp);
                }
                else if (c == '-') {
                    Pair tmp = Mul(A, C);
                    B = Minus(B, tmp);
                }
                else if (c == '*') {
                    B = Mul(A, B);
                }
                else {
                    C = Mul(A, C);
                    swap(B, C);
                }
                ans.push_back(B), ans.push_back(C);
                ans.push_back(P2);
            }
            else if (lenA == 2 && lenB == 1) {
                A = use[2], B = use[1], C = use[0];
                if (c == '+') {
                    Pair tmp = Mul(B, C);
                    A = Add(A, tmp);
                }
                else if (c == '-') {
                    Pair tmp = Mul(B, C);
                    A = Minus(A, tmp);
                }
                else if (c == '*') {
                    A = Mul(A, C);
                }
                else {
                    B = Mul(B, C);
                }
                ans.push_back(A), ans.push_back(B);
                ans.push_back(P2);
            }
            else {
                Pair rhs = use[0];
                Pair lhs = use[1];
                bool tmp = 0;
                if (c == '+') lhs = Add(lhs, rhs);
                else if (c == '-') lhs = Minus(lhs, rhs);
                else if (c == '*') lhs = Mul(lhs, rhs);
                else {
                    tmp = Div(lhs, rhs);
                    lhs = ::A;
                }
                if (tmp) {
                    ans.push_back(::A), ans.push_back(::B);
                    ans.push_back(P2);
                }
                else {
                    ans.push_back(lhs);
                    ans.push_back(P1);
                }
            }
        }
        else if (c == 'X') {
            Pair now = make_pair(make_pair(1, 1), make_pair(0, 1));
            ans.push_back(now);
            ans.push_back(P1);
        }
        else {
            Pair now = make_pair(make_pair(0, 1), make_pair(c - '0', 1));
            ans.push_back(now);
            ans.push_back(P1);
        }
    }
}

string r;
char s[100];

int main() {
#ifdef HOME
    freopen("E.in", "r", stdin);
#endif

    Cof A, B;
    //gets(s);
    getline(cin, r);
    REP(i, r.size()) {
        s[i] = r[i];
    }
    s[r.size()] = 0;
    get(s);
    //cout << inverse << endl;
    if (inverse) {
        Pair up = ans[0], down = ans[1];
        //up is 0
        if (isZero(up.first) && isZero(up.second)) {
            puts("MULTIPLE");
        }
        else if (isZero(up.first) && !isZero(up.second)) {
            puts("NONE");
        }
        //up is not 0
        else {
            Cof ans = Mul(up.second, make_pair(-1, 1));
            ans = Div(ans, up.first);
            Cof tmp = Mul(ans, down.first);
            tmp = Add(tmp, down.second);
            if (isZero(tmp)) {
                puts("NONE");
            }
            else {
                printf("X = %lld/%lld\n", ans.first, ans.second);
            }
        }
    }
    else {
        Pair ans = ::ans[0];
        A = ans.first, B = ans.second;
        if (isZero(A) && !isZero(B)) {
            puts("NONE");
        }
        else if (isZero(A) && isZero(B)) {
            puts("MULTIPLE");
        }
        else {
            B = Mul(B, make_pair(-1, 1));
            Cof ans = Div(B, A);
            printf("X = %lld/%lld\n", ans.first, ans.second);
        }
    }
    return 0;
}
