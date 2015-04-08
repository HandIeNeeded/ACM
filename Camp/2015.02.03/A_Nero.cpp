#include <bits/stdc++.h>

const int INF = (0x3f3f3f3f) * 2;
const int N = 200000 + 5;
int A[N],n,nq;

struct Interval {
    int l,r;
    Interval(int _l = 0,int _r = 0):
        l(_l),r(_r) {}
    void add(int c) {
        if (l != -INF) l += c;
        if (r != INF) r += c;
    }
    void update(const Interval &t) {
        if (r < t.l) {
            l = r = t.l;
        } else if (t.r < l) {
            l = r = t.r;
        } else {
            l = std::max(l,t.l);
            r = std::min(r,t.r);
        }
    }
    Interval merge(const Interval & t) const {
        return Interval(std::min(l,t.l),std::max(r,t.r));
    }
};

struct SegmentTree {
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
    Interval t[N<<2];
    Interval lazy[N<<2];
    int lazyadd[N<<2];
    void up(int rt) {
        t[rt] = t[rt<<1].merge(t[rt<<1|1]);
    }
    void down(int rt) {
        if (lazyadd[rt] != 0) {
            t[rt<<1].add(lazyadd[rt]);
            lazy[rt<<1].add(lazyadd[rt]);
            lazyadd[rt<<1] += lazyadd[rt];
            t[rt<<1|1].add(lazyadd[rt]);
            lazy[rt<<1|1].add(lazyadd[rt]);
            lazyadd[rt<<1|1] += lazyadd[rt];
            lazyadd[rt] = 0;
        }
        if (lazy[rt].l != -INF || lazy[rt].r != INF) {
            t[rt<<1].update(lazy[rt]);
            lazy[rt<<1].update(lazy[rt]);
            t[rt<<1|1].update(lazy[rt]);
            lazy[rt<<1|1].update(lazy[rt]);
            lazy[rt] = Interval(-INF,INF);
        }
    }
    void build(int l,int r,int rt) {
        lazy[rt] = Interval(-INF,INF);
        lazyadd[rt] = 0;
        if (l == r) {
            t[rt] = Interval(A[l],A[l]);
            return ;
        }
        int mid = l+r>>1;
        build(lson);
        build(rson);
        up(rt);
    }
    Interval query(int L,int R,int l,int r,int rt) {
        if (L <= l && r <= R) {
            return t[rt];
        }
        int mid = l+r>>1;
        down(rt);
        if (L <= mid && mid < R)
            return query(L,R,lson).merge(query(L,R,rson));
        if (L <= mid)
            return query(L,R,lson);
        return query(L,R,rson);
    }
    void modify_add(int L,int R,int c,int l,int r,int rt) {
        if (L <= l && r <= R) {
            t[rt].add(c);
            lazy[rt].add(c);
            lazyadd[rt] += c;
            return ;
        }
        int mid = l+r>>1;
        down(rt);
        if (L <= mid) modify_add(L,R,c,lson);
        if (mid < R)  modify_add(L,R,c,rson);
        up(rt);
    }
    void modify_min(int L,int R,int c,int l,int r,int rt) {
        if (L <= l && r <= R) {
            t[rt].update(Interval(-INF,c));
            lazy[rt].update(Interval(-INF,c));
            return ;
        }
        int mid = l+r>>1;
        down(rt);
        if (L <= mid) modify_min(L,R,c,lson);
        if (mid < R)  modify_min(L,R,c,rson);
        up(rt);
    }
    void modify_max(int L,int R,int c,int l,int r,int rt) {
        if (L <= l && r <= R) {
            t[rt].update(Interval(c,INF));
            lazy[rt].update(Interval(c,INF));
            return ;
        }
        int mid = l+r>>1;
        down(rt);
        if (L <= mid) modify_max(L,R,c,lson);
        if (mid < R)  modify_max(L,R,c,rson);
        up(rt);
    }
}sgt;

int main() {
    scanf("%d%d",&n,&nq);
    for (int i = 1; i <= n; ++ i) {
        scanf("%d",A+i);
    }
    sgt.build(1,n,1);
    while (nq--) {
        int op,l,r,c;
        scanf("%d%d%d",&op,&l,&r);
        if (op != 4) {
            scanf("%d",&c);
        }
        if (op == 1) {
            sgt.modify_add(l,r,c,1,n,1);
        } else if (op == 2) {
            sgt.modify_min(l,r,c,1,n,1);
        } else if (op == 3) {
            sgt.modify_max(l,r,c,1,n,1);
        } else {
            Interval answer = sgt.query(l,r,1,n,1);
            printf("%d %d\n",answer.l,answer.r);
        }
    }
    return 0;
}

