#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 1e5 + 5;

struct Node{
    Node *l, *r;
    int value, size;

    Node* update() {
        size = 1 + l->size + r->size;
        return this;
    }
}bar[N * 40], *rt[N << 3], *null, *foo;

int n, m, tot;
vector<int> num;
int a[N], b[N], c[N], d[N], type[N];

void init() {
    null = foo = bar;
    null->l = null->r = null;
    foo++;
    REPP(i, 1, tot * 4) rt[i] = null;
}

bool gen(int a, int b) {
    return rand() % (a + b) < a;
}

Node* New_Node(int x) {
    return new (foo++) (Node) {null, null, x, 1};
}

Node* merge(Node *a, Node *b) {
    if (a == null) return b;
    if (b == null) return a;
    if (gen(a->size, b->size)) {
        a->r = merge(a->r, b);
        return a->update();
    }
    else {
        b->l = merge(a, b->l);
        return b->update();
    }
}

#define PNN pair<Node*, Node*> 

PNN split(Node *u, int s) {
    if (u == null) return {null, null};
    if (u->l->size >= s) {
        PNN res = split(u->l, s);
        u->l = res.second;
        return make_pair(res.first, u->update());
    }
    else {
        PNN res = split(u->r, s - u->l->size - 1);
        u->r = res.first;
        return make_pair(u->update(), res.second);
    }
}

int find(Node *u, int num) {
    //cout << u->value << ' ' << num << endl;
    if (u == null) return 0;
    if (u->value > num) {
        return find(u->l, num);
    }
    else {
        return u->l->size + 1 + find(u->r, num);
    }
}

int ql, qr, qx, qd;

void add(Node *&u, int num) {
    int tmp = find(u, num);
    PNN res = split(u, tmp);
    u = New_Node(num);
    u = merge(res.first, u);
    u = merge(u, res.second);
}

void erase(Node *&u, int num) {
    int tmp = find(u, num);
    PNN res = split(u, tmp - 1);
    PNN res2 = split(res.second, 1);
    u = merge(res.first, res2.second);
}

void show(Node *u) {
    if (u == null) {
        return ;
    }
    if (u->l) show(u->l);
    cout << u->value << ' ';
    if (u->r) show(u->r);
}

void add(int x, int l, int r) {
    if (l == r) {
        add(rt[x], qd);
    }
    else {
        if (qx <= MID) add(LC);
        else add(RC);
        add(rt[x], qd);
    }
}

void erase(int x, int l, int r) {
    if (l == r) {
        erase(rt[x], qd);
    }
    else {
        if (qx <= MID) erase(LC);
        else erase(RC);
        erase(rt[x], qd);
    }
}

int query(int x, int l, int r, int now) {
    if (l == r) {
        return num[l];
    }
    else {
        //cout << x << ' ' << l << ' ' << r << endl;
        int tmp = find(rt[L], qr) - find(rt[L], ql - 1);
        if (tmp >= now) {
            return query(LC, now);
        }
        else {
            return query(RC, now - tmp);
        }
    }
}

bool cmp(int i, int j) {
    return a[i] < a[j];
}

#define ALL(a) (a).begin(), (a).end()

int main() {
#ifdef HOME
    freopen("G.in", "r", stdin);
#endif

    while (scanf("%d", &n) > 0) {
        num.clear(), num.push_back(0);
        REPP(i, 1, n) {
            scanf("%d", a + i);
            num.push_back(a[i]);
        }
        scanf("%d", &m);
        REPP(i, 1, m) {
            int x, y;
            scanf("%d%d%d", type + i, &x, &y);
            if (type[i] == 1) {
                b[i] = x;
                c[i] = y;
                num.push_back(c[i]);
            }
            else {
                b[i] = x, c[i] = y;
                scanf("%d", &d[i]);
            }

        }
        sort(ALL(num));
        num.resize(unique(ALL(num)) - num.begin());
        tot = num.size() - 1;
        //cout << tot << endl;
        init();
        REPP(i, 1, n) a[i] = lower_bound(ALL(num), a[i]) - num.begin();
        REPP(i, 1, n) {
            qx = a[i], qd = i;
            add(1, 1, tot);
        }
        //show(rt[1]);
        REPP(i, 1, m) {
            if (type[i] == 1) {
                c[i] = lower_bound(ALL(num), c[i]) - num.begin();
            }
        }
        REPP(i, 1, m) {
            if (type[i] == 1) {
                qd = b[i], qx = a[b[i]];
                erase(1, 1, tot);
                qd = b[i], qx = a[b[i]] = c[i];
                add(1, 1, tot);
            }
            else {
                ql = b[i], qr = c[i];
                //cout << ql << ' ' << qr << ' ' << d[i] << endl;
                printf("%d\n", query(1, 1, tot, d[i]));
            }
            //show(rt[1]);
        }
    }

    return 0;
}
