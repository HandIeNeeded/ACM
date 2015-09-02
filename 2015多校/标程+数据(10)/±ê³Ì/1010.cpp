#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define sz(x) (int((x).size()))

typedef long long LL;
const int MX = 100005;
const int MC = 26;

inline int get(char c) {
    return c - 'a';
}

struct Node;
typedef Node* PNode;

struct Node {
    int l, r, pardp, ccnt;
    PNode par, slink;
    PNode chd[MC];
    
    inline int len() {
        return r - l;
    }
    
    inline int depth() {
        return pardp + len();
    }
    
    inline bool inEdge(int pos) {
        return pardp <= pos && pos < depth();
    }
    
    bool DFS();
};

struct SuffixTree {
    char *s;
    int dn, sn, jj;
    bool needWalk;
    PNode root, cur, need;
    Node d[MX * 2];
    queue<PNode> que;
    LL tot;
    
    PNode newNode() {
        d[dn] = Node();
        return &d[dn++];
    }
    
    void add_edge(PNode p, PNode q, int l, int r) {
        p->chd[get(s[l])] = q;
        p->ccnt++;
        q->par = p;
        q->pardp = p->depth();
        q->l = l, q->r = r;
    }
    
    void walk_down(int j, int i) {
        if (i < j) return;
        for (int h = j + cur->depth(); !(cur->inEdge(i - j)); h += cur->len()) cur = cur->chd[get(s[h])];
    }
    
    void add_slink() {
        if (need) need->slink = cur;
        need = 0;
    }
    
    void extend(int i) {
        int k, pos;
        char c = s[i + 1];
        PNode leaf, split;
        
        for (; jj <= i + 1; jj++) {
            if (needWalk) {
                if (!cur->slink && cur->par) cur = cur->par;
                cur = (cur->slink) ? cur->slink : root;
                walk_down(jj, i);
            }
            needWalk = 1;
            k = i - jj + 1;
            if (k == cur->depth()) {
                add_slink();
                if (cur->chd[get(c)]) {
                    cur = cur->chd[get(c)];
                    needWalk = 0;
                    break;
                }
                leaf = newNode();
                add_edge(cur, leaf, i + 1, sn);
                que.push(leaf);
            }
            else {
                pos = cur->l + (k - cur->pardp);
                if (s[pos] == c) {
                    add_slink();
                    if (pos != i + 1) {
                        needWalk = 0;
                        break;
                    }
                }
                else {
                    split = newNode();
                    leaf = newNode();
                    add_edge(cur->par, split, cur->l, pos);
                    cur->par->ccnt--;
                    add_edge(split, cur, pos, cur->r);
                    add_edge(split, leaf, i + 1, sn);
                    que.push(leaf);
                    cur = split;
                    add_slink();
                    if (cur->depth() == 1) cur->slink = root;
                    else need = cur;
                }
            }
        }
        tot += sz(que);
    }
    
    void erase(int i) {
        int k;
        PNode tmp;
        
        tmp = que.front();
        que.pop();
        while (!(tmp->ccnt)) {
            if (cur == tmp) {
                k = (i - jj + 1) - cur->pardp;
                tot -= min(cur->r, i + 1) - cur->l - k;
                cur->l = i + 1 - k;
                cur->r = sn;
                que.push(cur);
                break;
            }
            tmp->par->chd[get(s[tmp->l])] = 0;
            tmp->par->ccnt--;
            tot -= min(tmp->r, i + 1) - tmp->l;
            tmp = tmp->par;
        }
        if (!(tmp->ccnt)) {
            cur = cur->par;
            if (cur != root) cur = cur->slink;
            walk_down(++jj, i);
            needWalk = 0;
        }
    }
    
    void init(char *t, int tn) {
        s = t, sn = tn;
        dn = 0;
        root = newNode();
        cur = newNode();
        add_edge(root, cur, 0, sn);
        need = 0;
        jj = 1;
        needWalk = 1;
        while (!que.empty()) que.pop();
        que.push(cur);
        tot = 1;
    }
    
    void build(char *t, int tn) {
        init(t, tn);
        for (int i = 0; i < tn - 1; i++) extend(i);
    }
};

char s[MX];
int n, k;
SuffixTree t1, t2;
LL a[MX], ans;
int st;

bool Node::DFS() {
    if (!ccnt) {
        if (depth() < k) return 0;
        st = n - depth();
        return a[st] == ans;
    }
    for (int i = 0; i < MC; i++) {
        PNode p = chd[i];
        if (!p) continue;
        if (p->DFS()) return 1;
    }
    return 0;
}

int main() {
    int q, i;
    char c;
    
    while(scanf("%s", s)!=EOF)
{
    n = strlen(s);
    t1.build(s, n);
    for (scanf("%d", &q); q--; ) {
        scanf("%d", &k);
        t2.init(s, n);
        for (i = 0; i < k - 1; i++) t2.extend(i);
        a[0] = t2.tot;
        for (i = k; i < n; i++) {
            t2.extend(i - 1);
            t2.erase(i);
            a[i - k + 1] = t2.tot;
        }
        ans = *max_element(a, a + n - k + 1);
        st = -1;
        t1.root->DFS();
        c = s[st + k];
        s[st + k] = 0;
        printf("%s %lld\n", s + st, ans);
        s[st + k] = c;
    }
}
    return 0;
}
