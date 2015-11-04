#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <assert.h>
using namespace std;

const int N = 100000+5;
const int Mod = 998244353;

struct PP {
    int l, r, x, pre;
    PP(){}
    PP(int l, int r, int x, int pre):l(l),r(r),x(x),pre(pre){}
    bool operator < (const PP &a) const {
        if(x != a.x) return x < a.x;
        return r < a.r;
    }
}q[N*25];

int n, nxt[N];
int a[N], val[N], node[2][N], vt[N];
int sum[N], dp[N];

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int bin(int l, int r, int v, int p) {
    int ret = -1;
    while(l <= r) {
        int mid = l+r>>1;
        if(vt[mid] < p) {
            l = mid+1;
        } else if(dp[vt[mid]] >= v) {
            ret = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return ret;
}

void update(int id, int x, int y) {
    while(x <= n) {
        node[id][x] += y;
        if(node[id][x] >= Mod) node[id][x] -= Mod;
        x += x&-x;
    }
}

int query(int id, int x) {
    int ret = 0;
    while(x) {
        ret += node[id][x];
        if(ret >= Mod) ret -= Mod;
        x -= x&-x;
    }
    return ret;
}

int solve() {
    int tot = 0;
    q[tot++] = PP(1,1,a[1],1);
    nxt[1] = 1; val[1] = a[1];
    for(int i = 2;i <= n; i++) {
        nxt[i] = i; val[i] = a[i];
        int pos = i;
        while(pos > 0) {
            val[pos] = gcd(val[pos], a[i]);
            while(nxt[pos] > 1 && gcd(val[pos], val[nxt[pos]-1])==val[pos]) {
                nxt[pos] = nxt[nxt[pos]-1];
            }
            q[tot++] = PP(pos, i, val[pos], nxt[pos]);
            pos = nxt[pos]-1;
        }
    }
    sort(q, q+tot);
    /*
    for(int i = 0;i < tot; i++) {
        printf("i=%d l=%d r=%d x=%d pre=%d\n", i, q[i].l, q[i].r,q[i].x,q[i].pre);
    }
    */
    int ans1 = 0, ans2 = 0;
    for(int i = 0;i < tot; i++) {
        int top = 0;
        int j = i;
        while(j < tot && q[j].x == q[i].x) {
            int pos = 0;
            if(top > 0) {
                pos = lower_bound(vt+1, vt+top+1, q[j].l)-vt;
                pos--;
            }
//            printf("pos = %d\n", pos);
            if(pos == 0) {
                dp[q[j].r] = 1;
                sum[q[j].r] = q[j].l-q[j].pre+1;
                if(!top || dp[vt[top]] <= 1) {
                    vt[++top] = q[j].r;
                    update(0, q[j].r, sum[q[j].r]);
                    update(1, q[j].r, 1ll*sum[q[j].r]*q[j].r%Mod);
                }
            } else {
                int mx = dp[vt[pos]];
                dp[q[j].r] = dp[vt[pos]]+1;
                sum[q[j].r] = 0;
                int pos2 = bin(1, pos, mx, q[j].pre);
                int pos3 = bin(1, pos, mx, 1);
//                printf("pos2 = %d\n", pos2);
                if(pos2 != -1) {
                    int add = 1ll*q[j].l*(query(0, vt[pos])-query(0, vt[pos2]-1))%Mod;
                    if(add < 0) add += Mod;
                    add -= (query(1, vt[pos])-query(1, vt[pos2]-1)+Mod)%Mod;
                    if(add < 0) add += Mod;
                    sum[q[j].r] = add;
                    sum[q[j].r] += 1ll*(q[j].l-q[j].pre+1)*(query(0, vt[pos2]-1)-query(0, vt[pos3]-1)+Mod)%Mod;
                    if(sum[q[j].r] >= Mod) sum[q[j].r] -= Mod;
                } else {
                    sum[q[j].r] += 1ll*(q[j].l-q[j].pre+1)*(query(0, vt[pos])-query(0, vt[pos3]-1)+Mod)%Mod;
                    if(sum[q[j].r] >= Mod) sum[q[j].r] -= Mod;
                }
                if(dp[vt[top]] <= dp[q[j].r]) {
                    vt[++top] = q[j].r;
                    update(0, q[j].r, sum[q[j].r]);
                    update(1, q[j].r, 1ll*sum[q[j].r]*q[j].r%Mod);
                }
            }
            if(dp[q[j].r] > ans1) {
                ans1 = dp[q[j].r];
                ans2 = sum[q[j].r];
            } else if(dp[q[j].r] == ans1) {
                ans2 += sum[q[j].r];
                if(ans2 >= Mod) ans2 -= Mod;
            }
//            printf("top = %d j=%d q=%d dp=%d sum=%d\n", top, j, q[j].r, dp[q[j].r], sum[q[j].r]);
//            for(int ii = 1;ii <= top; ii++) printf("%d ", vt[ii]); puts("");
            j++;
        }
        while(i < j) {
            int x = q[i].r;
            while(x <= n) {
                node[0][x] = node[1][x] = 0;
                x += x&-x;
            }
            i++;
        }
        i--;
    }
    printf("%d %d\n", ans1, ans2);
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(scanf("%d", &n) == 1) {
        assert(n >= 1 && n <= 100000);
        for(int i = 1;i <= n; i++) {
            scanf("%d", &a[i]);
            assert(a[i] >= 1 && a[i] <= 2333333);
        }
        solve();
    }
    return 0;
}
