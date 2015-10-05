#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <stack>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <cassert>
#include <numeric>
#include <ctime>
using namespace std;
//#define Online_Judge
#define outstars cout << "***********************" << endl;
#define clr(a,b) memset(a,b,sizeof(a))
#define lson l , mid  , rt << 1
#define rson mid + 1 , r , rt << 1 | 1
#define mk make_pair
#define pb push_back
#define sz size()
#define AA first
#define BB second
#define eps 1e-10
#define deq(a , b) fabs(a - b) < eps

typedef long long LL;
const LL MAXN = 10000 + 50;
const LL MAXE = 500000 + 50;
const LL MAXQ = 1000000 + 50;
const LL sigma_size = 26;

const LL inf = 0x3f3f3f3f;
const LL INF = ~0U >> 1;
const long long LLinf = 0x3FFFFFFFFFFFFFFFLL;
const long long LLINF = (1LL << 63) - 1;
const LL IMIN = 0x80000000;


const long long MOD = (1LL << 31) - 1;
const LL mod = 10007;
const double PI = acos(-1.0);
typedef pair<LL , LL> pii;
typedef vector<pii> vec;
typedef vector<vec> mat;
#define Bug(s) cout << "s = " << s << endl;
///#pragma comment(linker, "/STACK:102400000,102400000")
LL gcd(LL a, LL b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
class fraction {
public:
    LL above;         //分子
    LL below;         //分母
    void reduction();            //约分
    fraction makeCommond(fraction); //通分


    fraction(LL a=0,LL b=1) {      //构造函数
        above=a;
        below=b;
    }
    fraction add(fraction);      //两分数相加
    fraction sub(fraction);      //本分数减去实参分数
    fraction mul(fraction);      //两分数相乘
    fraction div(fraction);      //本分数除以实参分数
    fraction reciprocal();       //求倒数
    bool equal(fraction);        //等于运算
    bool greaterThan(fraction);  //大于运算
    bool lessThan(fraction);     //小于运算
    void display();              //显示分数
    void input();                //输入分数
};

void fraction::reduction() {
//    LL i,comdiv,small,max;
//    if(this->above<this->below) {
//        small=this->above;
//        max=this->below;
//    } else {
//        small=this->below;
//        max=this->above;
//    }
//
//    for(i=small; i>1; i--) {
//        if(small%i==0 &max%i==0 )
//            break;
//    }
//    comdiv=i;//最大公约数
    LL i = __gcd(this->above , this->below);
    if(i!=0) {
        this->above/=i;
        this->below/=i;
    }
    LL sign=this->above*this->below;
    if(sign<0)sign=-1;
    else sign= 1;
    if(this->above<0)this->above*=-1;
    if(this->below<0)this->below*=-1;
    this->above*=sign;
}
fraction fraction::makeCommond(fraction frac) {
    LL b1=this->below,b2=frac.below, m,s;
    if(b1>b2) {
        m=b1%b2;
        s=b2;
    } else {
        m=b2%b1;
        s=b1;
    }

    while(m>0) {
        LL res=s%m;
        s=m,m=res;
    }


    LL small=(b1*b2)/s;
    this->above=this->above*(small/this->below);
    frac.above=frac.above*(small/frac.below);
    this->below=small;
    frac.below=small;
    return frac;
}

fraction fraction::add(fraction fr) {
    fraction myFraction;
    myFraction.above=this->above*fr.below+fr.above*this->below;
    myFraction.below=this->below*fr.below;

    myFraction.reduction();

    return myFraction;
}
fraction fraction::sub(fraction fr) {
    fraction myFraction;
    myFraction.above=this->above*fr.below-fr.above*this->below;
    myFraction.below=this->below*fr.below;

    myFraction.reduction();

    return myFraction;
}

fraction fraction::mul(fraction fr) {
    fraction myFraction;
    myFraction.above=this->above*fr.above;
    myFraction.below=this->below*fr.below;
    myFraction.reduction();

    return myFraction;
}
fraction fraction::div(fraction fr) {
    fraction myFraction;

    myFraction.above=this->above*fr.below;
    myFraction.below=this->below*fr.above;

    myFraction.reduction();

    return myFraction;
}

fraction fraction::reciprocal() {
    fraction myFraction(this->above,this->below);
    if(this->above!=0) {
        LL temp=myFraction.above;
        myFraction.above=myFraction.below;
        myFraction.below=temp;
    }
    return myFraction;
}

bool fraction::equal(fraction frac) {     //等于运算
    bool result=false;
    if(this->sub(frac).above==0)
        result=true;

    return result;
}
bool fraction::greaterThan(fraction frac) { //大于运算
    bool result=false;
    if(this->sub(frac).above>0)
        result=true;
    return result;

}
bool fraction::lessThan(fraction frac) {   //小于运算
    bool result=false;

    if(this->sub(frac).above<0)
        result=true;

    return result;

}

void fraction::display() {
    cout<<this->above;
    //if(this->below!=1)
        cout<<"/"<<this->below;
}

struct ax {
    fraction f; // ax + b + 1/(ax + b)
    LL k;
};

ax num[100000];

stack <LL> S1;
stack <pii> S2;
char s[10];


void putnone()
{
    puts("NONE");
    exit(0);
}
void putmulti()
{
    puts("MULTIPLE");
    exit(0);
}
void putf(fraction x)
{
    printf("X = ");
    x.display();
    puts("");
    exit(0);
}
int main() {
    while(!S1.empty()) S1.pop();
    while(!S2.empty()) S2.pop();
    //freopen("equation.in","r",stdin);
    //freopen("equation.out","w",stdout);
    LL t=0;
    bool boolmulti = false;
    fraction zero=fraction(0,1);
    fraction one =fraction(1,1);
    fraction fone = fraction(-1,1);
    //while(scanf("%s",s) != EOF)
    string s;
    while(cin >> s)
    {
        if(s[0] == 'E') break;
        else if(s[0] <= '9' && s[0] >= '0')
        {
            LL tmp = s[0] - '0';
            LL i = 1;
            while(i < s.sz)
            {
                tmp = tmp * 10 + (s[i] - '0');
                i++;
            }
            num[t].f = fraction(tmp,1);
            num[t].k = 0;
            S1.push(t);
            t++;
        }
        else if(s[0] == 'X')
        {
            num[t].f = one;
            num[t].k = 1;
            S1.push(t);
            t++;
        }
        else if(s[0] == '+')
        {
            LL i = S1.top(); S1.pop();
            LL j = S1.top(); S1.pop();
            if(num[i].k == 0 && num[j].k == 0)
            {
                num[i].f = num[i].f.add(num[j].f);
                S1.push(i);
            }
            else
            {
                if(num[j].k == 1) swap(i,j);
                S1.push(i);
                S2.push(mk(1,j));
            }
        }
        else if(s[0] == '-')
        {
            LL i = S1.top(); S1.pop();
            LL j = S1.top(); S1.pop();
            if(num[i].k == 0 && num[j].k == 0)
            {
                swap(i,j);
                num[i].f = num[i].f.sub(num[j].f);
                S1.push(i);
            }
            else
            {
                swap(i,j);
                LL tmp = 0;
                if(num[j].k == 1) {swap(i,j); tmp = 2;}
                S1.push(i);
                S2.push(mk(tmp,j));
            }
        }
        else if(s[0] == '*')
        {
            LL i = S1.top(); S1.pop();
            LL j = S1.top(); S1.pop();
            if(num[i].k == 0 && num[j].k == 0)
            {
                num[i].f = num[i].f.mul(num[j].f);
                S1.push(i);
            }
            else
            {
                if(num[j].k == 1) {swap(i,j);}
                S1.push(i);
                S2.push(mk(4,j));
            }
        }
        else if(s[0] == '/')
        {
            LL i = S1.top(); S1.pop();
            LL j = S1.top(); S1.pop();
            if(num[i].k == 0 && num[j].k == 0)
            {
                swap(i,j);
                num[i].f = num[i].f.div(num[j].f);
                S1.push(i);
            }
            else
            {
                swap(i,j);
                LL tmp = 3;
                if(num[j].k == 1) {swap(i,j); tmp = 5;}
                S1.push(i);
                S2.push(mk(tmp,j));
            }
        }
    }
    LL fin = S1.top();
    if(num[fin].k == 0)
    {
        if(num[fin].f.equal(zero)) putmulti();
        putnone();
    }
    else
    {
        fraction now = zero;
        while(!S2.empty())
        {
            pii i = S2.top(); S2.pop();
//            cout << i.AA << " "; num[i.BB].f.display(); cout << endl;
            if(i.AA == 0 )
            {
                now = now.add(num[i.BB].f);
            }
            else if(i.AA == 1)
            {
                now = now.sub(num[i.BB].f);
            }
            else if(i.AA == 2)
            {
                now = num[i.BB].f.sub(now);
            }
            else if(i.AA == 3)
            {
                now = now.mul(num[i.BB].f);
            }
            else if(i.AA == 4)
            {
                if(num[i.BB].f.equal(zero))
                {
                    if(now.equal(zero)) putmulti();
                    else putnone();
                }
                now = now.div(num[i.BB].f);
            }
            else if(i.AA == 5)
            {
                if(num[i.BB].f.equal(zero))
                {
                    if(now.equal(zero)) putmulti();
                    else putnone();
                }
                if(now.equal(zero))
                {
                    if(num[i.BB].f.equal(zero)) putmulti();
                    else putnone();
                }
                now = num[i.BB].f.div(now);
            }
        }
        if(now.below == 0) putmulti();
        putf(now);
    }
}
