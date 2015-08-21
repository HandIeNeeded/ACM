#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LB(x) ((x) & (-(x)))

using namespace std;

const int N = 2e5 + 5;

struct Node{
    Node *l, *r;
    int size, value;

    Node* update() {
        size = 1 + l->size + r->size;
        return this;
    }
}bar[N * 17], *foo, *rt[N << 2], *null;

void init(int tot) {
    foo = null = bar;
    null->l = null->r = null;
    REPP(i, 1, tot) rt[i] = null;
    foo++;
}

Node* New_Node(int x) {
    return new(foo++) (Node) {null, null, 1, x};
}

bool gen(int a, int b) {
    return rand() % (a + b) < a;
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
    Node *l = u->l, *r = u->r;
    if (l->size >= s) {
        PNN res = split(l, s);
        u->l = res.second;
        return {res.first, u->update()};
    }
    else {
        PNN res = split(r, s - (l->size + 1));
        u->r = res.first;
        return {u->update(), res.second};
    }
}

pair<int, bool> find(Node *u, int num) {
    if (u == null) return {0, 0};
    else {
        if (u->value > num) {
            return find(u->l, num);
        }
        else {
            pair<int, bool> tmp = find(u->r, num);
            tmp.first += u->l->size + 1;
            tmp.second |= u->value == num;
            return tmp;
        }
    }
}

void insert(Node *&u, Node *a) {
    int tmp = find(u, a->value).first;
    PNN res = split(u, tmp);
    u = a;
    u = merge(res.first, u);
    u = merge(u, res.second);
}

void erase(Node *&u, int num) {
    pair<int, bool> tmp = find(u, num);
    if (tmp.second) {
        PNN res = split(u, tmp.first - 1);
        PNN res2 = split(res.second, 1);
        u = merge(res.first, res2.second);
    }
}

int L[N], R[N], tot, n;

int query(int pos, int num) {
    int ans = 0;
    while (pos) {
        ans += rt[pos]->size - find(rt[pos], num - 1).first;
        pos -= LB(pos);
    }
    return ans;
}

int count(int pos, int num) {
    int ans = 0;
    while (pos) {
        ans += find(rt[pos], num).first - find(rt[pos], num - 1).first;
        pos -= LB(pos);
    }
    return ans;
}

void insert(int pos, int num) {
    while (pos <= tot) {
        Node* tmp = New_Node(num);
        insert(rt[pos], tmp);
        pos += LB(pos);
    }
}

void erase(int pos, int num) {
        while (pos <= tot) {
            erase(rt[pos], num);
            pos += LB(pos);
        }
}

vector<int> num;
bool type[N];
int c[N];

int main() {
#ifdef HOME
    freopen("D.in", "r", stdin);
#endif
    num.reserve(N << 1);
    int n, ca = 1;
    while (scanf("%d", &n) > 0) {
        num.clear();
        int now = 0, t, x;
        REPP(i, 1, n) {
            scanf("%d%d", &t, &x);
            type[i] = t;
            if (t == 0) {
                num.push_back(x), num.push_back(x + ++now);
                L[i] = x, R[i] = x + now;
                c[now] = x;
            }
            else {
                L[i] = c[t], R[i] = c[t] + t;
            }
        }
        //REPP(i, 1, n) {
        //    cout << i << ' ' << L[i] << ' ' << R[i] << endl;
        //}
        sort(num.begin(), num.end());
        num.resize(unique(num.begin(), num.end()) - num.begin());
        tot = num.size();
        init(tot);
        REPP(i, 1, n) {
            L[i] = lower_bound(num.begin(), num.end(), L[i]) - num.begin() + 1;
            R[i] = lower_bound(num.begin(), num.end(), R[i]) - num.begin() + 1;
        }
        //REPP(i, 1, n) {
        //    cout << i << ' ' << L[i] << ' ' << R[i] << endl;
        //}
        printf("Case #%d:\n", ca++);
        REPP(i, 1, n) {
            if (type[i] == 0) {
                printf("%d\n", query(R[i], L[i]) - query(L[i] - 1, L[i]));
                insert(R[i], L[i]);
            }
            else {
                erase(R[i], L[i]);
            }
        }
    }

    return 0;
}

