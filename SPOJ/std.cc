/** Micro Mezz Macro Flation -- Overheated Economy ., Last Update: Nov. 7th 2014 **/ //{

/** Header .. **/ //{
#pragma comment(linker, "/STACK:36777216")
//#pragma GCC optimize ("O2")
#define LOCAL
//#include "testlib.h"
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <climits>
#include <cassert>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

//#include <tr1/unordered_set>
//#include <tr1/unordered_map>
//#include <array>

using namespace std;

#define REP(i, n) for (int i=0;i<n;++i)
#define FOR(i, a, b) for (int i=a;i<b;++i)
#define DWN(i, b, a) for (int i=b-1;i>=a;--i)
#define REP_1(i, n) for (int i=1;i<=n;++i)
#define FOR_1(i, a, b) for (int i=a;i<=b;++i)
#define DWN_1(i, b, a) for (int i=b;i>=a;--i)
#define Ts *this
#define rTs return Ts


typedef long long LL;

int MOD = int(1e9) + 7;

// <<= '2. Number Theory .,//{
namespace NT{
#define gcd __gcd
    inline LL lcm(LL a, LL b){return a*b/gcd(a,b);}

    inline void INC(int &a, int b){a += b; if (a >= MOD) a -= MOD;}
    inline int sum(int a, int b){a += b; if (a >= MOD) a -= MOD; return a;}

    /* 模数两倍刚好超 int 时。
     inline int sum(uint a, int b){a += b; a %= MOD;if (a < 0) a += MOD; return a;}
     inline void INC(int &a, int b){a = sum(a, b);}
     */

    inline void DEC(int &a, int b){a -= b; if (a < 0) a += MOD;}
    inline int dff(int a, int b){a -= b; if (a < 0) a  += MOD; return a;}
    inline void MUL(int &a, int b){a = (LL)a * b % MOD;}
    //inline int pdt(int a, int b){return (LL)a * b % MOD;}
    inline int pdt(int x,int y) {
        int ret; __asm__ __volatile__ ("\tmull %%ebx\n\tdivl %%ecx\n":"=d"(ret):"a"(x),"b"(y),"c"(MOD));
        return ret;
    }


    inline int gcd(int m, int n, int &x, int &y){

        x = 1, y = 0; int xx = 0, yy = 1, q;

        while (1){
            q = m / n, m %= n;
            if (!m){x = xx, y = yy; return n;}
            DEC(x, pdt(q, xx)), DEC(y, pdt(q, yy));
            q = n / m, n %= m;
            if (!n) return m;
            DEC(xx, pdt(q, x)), DEC(yy, pdt(q, y));
        }
    }

    inline int sum(int a, int b, int c){return sum(a, sum(b, c));}
    inline int sum(int a, int b, int c, int d){return sum(sum(a, b), sum(c, d));}
    inline int pdt(int a, int b, int c){return pdt(a, pdt(b, c));}
    inline int pdt(int a, int b, int c, int d){return pdt(pdt(a, b), pdt(c, d));}

    inline int pow(int a, LL b){
        int c(1); while (b){
            if (b&1) MUL(c, a);
            MUL(a, a), b >>= 1;
        }
        return c;
    }

    template<class T> inline T pow(T a, LL b){
        T c(1); while (b){
            if (b&1) c *= a;
            a *= a, b >>= 1;
        }
        return c;
    }

    template<class T> inline T pow(T a, int b){
        return pow(a, (LL)b);
    }

    inline int _I(int b){
        int a = MOD, x1 = 0, x2 = 1, q; while (1){
            q = a / b, a %= b;
            if (!a) return x2;
            DEC(x1, pdt(q, x2));

            q = b / a, b %= a;
            if (!b) return x1;
            DEC(x2, pdt(q, x1));
        }
    }

    inline void DIV(int &a, int b){MUL(a, _I(b));}
    inline int qtt(int a, int b){return pdt(a, _I(b));}

    struct Int{
        int val;

        operator int() const{return val;}

        Int(int _val = 0):val(_val){
            val %= MOD; if (val < 0) val += MOD;
        }
        Int(LL _val):val(_val){
            _val %= MOD; if (_val < 0) _val += MOD;
            val = _val;
        }

        Int& operator +=(const int& rhs){INC(val, rhs);rTs;}
        Int operator +(const int& rhs) const{return sum(val, rhs);}
        Int& operator -=(const int& rhs){DEC(val, rhs);rTs;}
        Int operator -(const int& rhs) const{return dff(val, rhs);}
        Int& operator *=(const int& rhs){MUL(val, rhs);rTs;}
        Int operator *(const int& rhs) const{return pdt(val, rhs);}
        Int& operator /=(const int& rhs){DIV(val, rhs);rTs;}
        Int operator /(const int& rhs) const{return qtt(val, rhs);}
        Int operator-()const{return MOD-*this;}
    };

} using namespace NT;

const int N = int(1e3) + 9;
Int binom[N][N], A[N], B[N], S[N]; Int C1[N], C[N];
int n;

void gao(Int A[]){
    REP_1(i, n){
        A[i] = S[i];
        REP_1(j, i-1) A[i] -= binom[i-1][j-1]*A[j]*S[i-j];
    }
}

int main(){
    n = 1000;

    REP(i, n+1){binom[i][0] = 1; REP(j, i) binom[i][j+1] = binom[i-1][j] + binom[i-1][j+1];}

    REP_1(i, n) S[i] = pow(2, binom[i][2]); gao(A);
    REP_1(i, n) S[i] = pow(2, binom[i-1][2]); gao(B);

    S[0] = 1; REP_1(i, n){
        S[i] = 0;
        REP(j, i+1) S[i] += binom[i][j] * pow(2, j*(i-j));
    }

    REP_1(i, n){
        C1[i] = S[i]/2; REP_1(j, i-1) C1[i] -= binom[i-1][j-1]*C1[j]*S[i-j];
    }

    REP_1(i, n){
        C[i] = C1[i];
        REP_1(j, i-1) C[i] += binom[i-1][j-1] * C1[j] * C[i-j];
    }

    int T; cin >> T; while (T--){
        scanf("%d", &n);
        printf("Connected: %d\n", A[n]);
        printf("Eulerian: %d\n", B[n]);
        printf("Bipartite: %d\n", C[n]);
        puts("");
    }
}

