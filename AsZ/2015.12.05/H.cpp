#include <bits/stdc++.h>
#define MAXN 2123
#define MAXM 212345
#define ll long long

using namespace std;

struct point {
    ll x, y, z;
    point(ll x = 0, ll y = 0, ll z = 0) : x(x), y(y), z(z) {}
    bool operator < (point v) const {
        return x < v.x || (x == v.x && y < v.y) || (x == v.x && y == v.y && z < v.z);
    }
    point operator + (point p)
    {
        return point(x + p.x, y + p.y, z + p.z);
    }
    point operator - (point p)
    {
        return point(x - p.x, y - p.y, z - p.z);
    }
    point operator * (int k)
    {
        return point(x * k, y * k, z * k);
    }
    point operator / (int k)
    {
        return point(x / k, y / k, z / k);
    }
    void prt() {
        printf("%lld %lld %lld\n", x, y, z);
    }
}A, B, meth[MAXN * 10];

point det(point v1, point v2)
{
    return point(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}

ll dot(point v1, point v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

typedef int arrayN[MAXN * 5], arrayM[MAXM];

int tot;
map <point, int> mp;
int num;
arrayM e, nxt;
arrayN fir, pre, vis;

ll sqr(ll x)
{
    return x * x;
}

ll length(point v)
{
    return sqrt(sqr(v.x) + sqr(v.y) + sqr(v.z));
}

bool rev(point v1, point v2)
{
    if (v1.x < 0 && v2.x > 0 || v1.x > 0 && v2.x < 0)
        return true;
    if (v1.y < 0 && v2.y > 0 || v1.y > 0 && v2.y < 0)
        return true;
    if (v1.z < 0 && v2.z > 0 || v1.z > 0 && v2.z < 0)
        return true;
    return false;
}

struct node {
    point p[6];
    vector <point> ep;

    void readp(int x) {
        scanf("%lld %lld %lld", &p[x].x, &p[x].y, &p[x].z);
    }
    int checkIn(point q) {
        // return 1 if in
        point v1 = p[1] - p[0];
        point v2 = p[2] - p[0];
        point n = det(v1, v2);
       // n.prt();
        point v = q - p[0];
       // v.prt();
        if (dot(v, n) != 0)
            return 0;
//        ll s1 = length(det(p[0] - q, p[1] - q)) + length(det(p[1] - q, p[2] - q)) + length(det(p[2] - q, p[0] - q));
//        ll s2 = length(det(p[1] - p[0], p[2] - p[0]));
        n = det(p[0] - q, p[1] - q);
//        n.prt();
//        det(p[1] - q, p[2] - q).prt();
        if (rev(n, det(p[1] - q, p[2] - q)))
            return 0;
//        det(p[2] - q, p[0] - q).prt();
        if (rev(n, det(p[2] - q, p[0] - q)))
            return 0;
        return 1;
    }

    point getPointBelow(point u, point v, int limz) {
        //u.z < v.z
        // return  point  <= limz
        point dv = v - u;
        ll g = __gcd(abs(dv.x), abs(dv.y));
        g = __gcd(g, abs(dv.z));
        point unit = dv / g;
        //unit.prt();

        if (unit.z == 0) return v;
      //  if (dv.y < 0)
        //    unit.y *= -1;
       // if (dv.x < 0)
         //   unit.x *= -1;
        //assert(unit.z);

        ll par = (limz - u.z) / unit.z;
        par = min(g, par);
        par = max(0LL, par);


        point tmp = u + unit * par;
    /*    if (tmp.x >= 1000000 || tmp.y >= 1000000) {

        printf("%lld %lld\n!!!\n", par, g);
        printf("u:");
        u.prt();
        printf("v:");
        v.prt();

        printf("w:");
        tmp.prt();

        printf("unit:");
        unit.prt(); } */
        return tmp;
    }

    void getAllPoint(int limz) {
        for (int i = 0; i < 3; ++i) {
            point u = p[i];
            if (u.z <= limz) {
                ep.push_back(u);
            }
        }
        for (int i = 0; i < 3; ++i) {
            point u = p[i];
            point v = p[(i + 1) % 3];
            if (u.z > v.z) swap(u, v);
            if (u.z >= limz && v.z >= limz) continue;
            if (u.z <= limz && v.z <= limz) continue;
            point w = getPointBelow(u, v, limz);
           // w.prt();
            ep.push_back(w);
        }
    }
} g[MAXN];

int getFromMap(point x) {
    if (mp.count(x)) return mp[x];
    mp[x] = ++tot;
    meth[tot] = x;
    return tot;
}

void link(int u, int v) {
    e[++num] = v, nxt[num] = fir[u];
    fir[u] = num;
}


//int flag = 0;

void handleMap(vector <point> &vec) {
    for (int i = 0; i < vec.size(); ++i)
        for (int j = 0; j < vec.size(); ++j)
            if (i != j) {
                int u = getFromMap(vec[i]);
                int v = getFromMap(vec[j]);
                if (u != v) link(u, v);
              //  if (flag && mp[meth[u]] == mp[B] && mp[meth[v]] == mp[A]) {
                //    printf("\n");
                  //  meth[u].();
                   // meth[v].prt();
                //}

            }
}


int check(int limz, int n) {
    tot = 0;
    mp.clear();
    memset(fir, 0, sizeof(fir));
    num = 0;
    for (int i = 1; i <= n; ++i) {
        g[i].ep.clear();
        if (g[i].checkIn(A)) {
            g[i].ep.push_back(A);
            //printf("A %d\n", i);
        }
        if (g[i].checkIn(B)) {
            g[i].ep.push_back(B);
            //printf("B %d\n", i);
        }
        g[i].getAllPoint(limz);
        handleMap(g[i].ep);
    }

    int s = mp[A];
    int t = mp[B];
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= tot; ++i) vis[i] = 0;
    deque <int> deq;
    vis[s] = 1;
    deq.push_back(s);
    for (; !deq.empty(); ) {
        int u = deq.front();
        deq.pop_front();
        for (int p = fir[u]; p; p = nxt[p]) {
            int v = e[p];
            if (!vis[v]) {
                vis[v] = 1;
                pre[v] = u;
                deq.push_back(v);
            }
            if (v == t) return 1;
        }
    }
    return 0;
}

void printAns() {
    int s = mp[A];
    int t = mp[B];
    vector <point> vec;
    for (int tmp = t; tmp != s; tmp = pre[tmp])
        vec.push_back(meth[tmp]);
    vec.push_back(meth[s]);
    reverse(vec.begin(), vec.end());
    printf("%d\n", vec.size());
    for (int i = 0; i < vec.size(); ++i)
        vec[i].prt();
}

int main() {
    freopen("hiking.in", "r", stdin);
#ifndef HOME
    freopen("hiking.out", "w", stdout);
#endif // HOME
    int n;
    scanf("%d", &n);
    ll l = 0, r = 1000000;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j)
            g[i].readp(j);
    }
    scanf("%lld %lld %lld", &A.x, &A.y, &A.z);
    scanf("%lld %lld %lld", &B.x, &B.y, &B.z);
    //A, B belong to the same surface
    for (int i = 1; i <= n; ++i) {
        if (g[i].checkIn(A) && g[i].checkIn(B)) {
            printf("2\n");
            //printf("haha\n");
            A.prt();
            B.prt();
            return 0;
        }
    }

    l = max(l, max(A.z, B.z));
    for (; l < r; ) {
        ll mid = (l + r) >> 1;
        if (check(mid, n)) {
            r = mid;
        } else l = mid + 1;
    }
    //flag = 1;
    check(l, n);
    //printf("%d %d\n", l, tot);
 //   for (int i = 1; i <= tot; ++i) {
   //     meth[i].prt();
    //}
    printAns();
    return 0;
}
