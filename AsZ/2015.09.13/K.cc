#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e6 + 5;
const string inf = "10000000000000000000000000";

char s[30], r[30];
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

const LL BASE = 1000000000;

struct BigInteger {
    vector<LL> v; //v中倒序存放数字
    BigInteger () {}
    BigInteger (LL x) { Init(x); }
    BigInteger (string s) {Init(s); }

    void Init(LL x) {
        v.clear();
        if (x == 0) {
            v.push_back(0);
            return ;
        }
        while (x) {
            v.push_back(x % BASE);
            x /= BASE;
        }
    }

    void Init(string s) {
        v.clear();
        if (s.size() == 1 && s[0] == 0) {
            v.push_back(0);
            return ;
        }
        else {
            reverse(s.begin(), s.end());
            REP(i, s.size()) {
                int length = min(9, int(s.size()) - i);
                LL now = 0;
                string tmp = s.substr(i, length);
                reverse(tmp.begin(), tmp.end());
                REP(i, length) now = 10 * now + tmp[i] - '0';
                v.push_back(now);
                i += length;
            }
        }
    }

    int size() {
        return int(v.size());
    }

    const int size() const {
        return int(v.size());
    }

    LL operator [] (int i) {
        assert(i < int(v.size()));
        return v[i];
    }

    const LL operator [] (int i) const {
        assert(i < int(v.size()));
        return v[i];
    }

    BigInteger operator + (const BigInteger &b) const {
        LL m = max(v.size(), b.v.size()) + 1;
        BigInteger c;
        c.v.resize(m);//全0，注意不能c(m)这样写，因为这样是把c初始化成m
        LL st = 0, tmp, aa, bb;

        REP(i, m) {
            if (i >= (int) v.size()) aa = 0;
            else aa = v[i];
            if (i >= (int) b.v.size()) bb = 0;
            else bb = b.v[i];
            tmp = aa + bb + st;
            if (tmp >= BASE) st = 1, tmp -= BASE;
            else st = 0;
            c.v[i] = tmp;
        }
        while (c.v.size() > 1 && c.v.back() == 0) c.v.pop_back();
        return c;
    }

    BigInteger operator * (const BigInteger &b) const {
        BigInteger c; 
        c.v.resize(v.size() + b.v.size()); //max digit a+b 全0
        LL st = 0, tmp;
        REP(i, v.size()) {
            REP(j, b.v.size()) {
                tmp = v[i] * b.v[j] + c.v[i + j] + st; //tmp < base^2
                c.v[i + j] = tmp % BASE;
                st = tmp / BASE; //st < base
            }
            c.v[i + b.v.size()] = st, st = 0;
        }
        while (c.v.size() > 1 && c.v.back() == 0) c.v.pop_back(); 
        return c;
    }

    bool operator == (const BigInteger &b) const {
        if (int(v.size()) == b.size()) {
            REP(i, b.size()) {
                if (v[i] != b[i]) return 0;
            }
            return 1;
        }
        return 0;
    }

    bool operator < (const BigInteger &b) const {
        if (int(v.size()) == b.size()) {
            for (int i = b.size() - 1; i >= 0; i--) {
                if (v[i] != b[i]) {
                    return v[i] < b[i];
                }
            }
            return 0;
        }
        return int(v.size()) < b.size();
    }


    bool operator <= (const BigInteger &b) const {
        if (int(v.size()) == b.size()) {
            for (int i = b.size() - 1; i >= 0; i--) {
                if (v[i] != b[i]) {
                    return v[i] < b[i];
                }
            }
            return 1;
        }
        return int(v.size()) < b.size();
    }

    BigInteger operator - (const BigInteger &b) const {
        if (*this == b) return BigInteger(0);
        BigInteger ans;
        LL tmp, add = 0;
        REP(i, b.size()) {
            tmp = v[i] - add;
            add = 0;
            if (tmp < b[i]) {
                tmp += BASE;
                add++;
            }
            ans.v.push_back(tmp - b[i]);
        }
        for (int i = b.size(); i < int(v.size()); i++) {
            tmp = v[i] - add;
            add = 0;
            if (tmp < 0) {
                tmp += BASE;
                add++;
            }
            ans.v.push_back(tmp);
        }
        while (ans.size() > 1 && ans.v.back() == 0) ans.v.pop_back();
        return ans;
    }

    BigInteger operator / (const BigInteger &b) const {
        BigInteger lo = BigInteger(0), hi = *this + BigInteger(1);
        while (lo + BigInteger(1) < hi) {
            BigInteger mid = lo + hi;
            mid = mid / 2;
            if (mid * b <= *this) {
                lo = mid;
            }
            else hi = mid;
        }
        return lo;
    }

    BigInteger operator / (const LL &n) const { //n != 0
        if (n == 0) {
            cout << "Error!" << endl;
            return 0;
        }

        BigInteger b;
        b.v.resize(v.size());
        LL st = 0, tmp;
        for (int i = v.size() - 1, j = 0; i >= 0; --i, j++) {
            tmp = st * BASE + v[i];
            b.v[j] = tmp / n;
            st = tmp % n;
        }
        reverse(b.v.begin(), b.v.end());
        while (b.v.size() > 1 && b.v.back() == 0) b.v.pop_back();
        return b;
    }

    BigInteger operator % (const BigInteger &b) const {
        return *this - *this / b * b;
    }

    LL operator % (const LL &n) const { //n != 0
        if (n == 0) {
            cout << "Error!" << endl;
            return 0;
        }

        LL st = 0, tmp;
        for (int i = v.size() - 1, j = 0; i >= 0; --i, j++) {
            tmp = st * BASE + v[i];
            st = tmp % n;
        }
        return st;
    }
};

void output(const BigInteger &num) {
    cout << num.v.back(); //最前面没有前导0，后面都是有前导零的
    int n = num.v.size() - 1;
    while (n) {
        cout << setw(9) << setfill('0') << num.v[--n]; //这里改变了cout对于固定宽度的输出的设置
    }
    cout << endl;
}

BigInteger gcd(const BigInteger &a, const BigInteger &b) {
    if (BigInteger(0) == b) return a;
    else {
        BigInteger k = a / b;
        BigInteger c = a - k * b;
        return gcd(b, c);
    }
}

BigInteger zero = BigInteger(0);
BigInteger one = BigInteger(1);

LL calc(BigInteger x, BigInteger d) {
    map<BigInteger, int> mp;
    for (int i = 0; i < tot && BigInteger(1LL * i * i) <= x; i++) {
        BigInteger now = BigInteger(p[i]);
        if (x % now == zero) {
            x = x / now;
            int cnt = 1;
            while (x % now == zero) {
                cnt++;
                x = x / now;
            }
            mp[now] += cnt;
        }
    }
    if (one < x) {
        mp[x]++;
    }

    for (int i = 0; i < tot && BigInteger(1LL * i * i) <= d; i++) {
        BigInteger now = BigInteger(p[i]);
        if (d % now == zero) {
            d = d / now;
            int cnt = 1;
            while (d % now == zero) {
                cnt++;
                d = d / now;
            }
            mp[now] += cnt;
        }
    }
    if (one < d) {
        mp[d]++;
    }

    LL ans = 1;
    for (auto &x: mp) {
        ans *= x.second;
    }
    return ans;
}

int main() {
#ifdef HOME
    freopen("K.in", "r", stdin);
#endif

    prime();

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s%s", s, r);
        BigInteger A, B;
        A.Init(s), B.Init(r);
        //output(A), output(B);
        BigInteger d = gcd(A, B);
        //output(d);
        A = A / d, B = B / d;
        printf("%lld %lld\n", calc(A, d), calc(B, d));
    }
    return 0;
}

