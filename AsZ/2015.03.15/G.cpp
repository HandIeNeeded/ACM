#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int C = 4;

char s[MAXN];
int N, ret;

namespace PT {
    struct Node {
        Node *ch[C], *fa, *sub;
        int len, full, half;
    } pool[MAXN], *last;
    char s[MAXN];
    int sz, n;
    void init(int _n) {
        memset(pool, 0, sizeof(pool[0]) * (_n + 10));
        last = &pool[1]; sz = 2; n = -1;
        pool[0].len = -1; pool[0].fa = &pool[0];
        pool[1].len = 0; pool[1].fa = &pool[0];
    }
    int IDX(char c) {
        if (c == 'A') return 0;
        else if (c == 'C') return 1;
        else if (c == 'G') return 2;
        else return 3;
    }
    Node* get(Node *p) {
        while (n - p->len - 1 < 0 || s[n] != (s[n - p->len - 1])) p = p->fa;
        return p;
    }
    bool add(char cc) {
        int c = IDX(cc); s[++ n] = cc;
        Node *cur = get(last);
        if (cur->ch[c]) return last = cur->ch[c], false;
        last = &pool[sz ++]; last->len = cur->len + 2; cur->ch[c] = last;
        if (last->len == 1) {
            last->fa = last->sub = &pool[1];
            last->full = 1;
            return true;
        }
        last->fa = get(cur->fa)->ch[c];
        if (last->len <= 2) last->sub = last->fa;
        else {
            Node *x = cur->sub;
            while (n - x->len - 1 < 0 || s[n] != s[n - x->len - 1] || (x->len + 2) * 2 > last->len) x = x->fa;
            last->sub = x->ch[c];
        }
        if (last->len % 2 == 0) {
            last->half = min(cur->half + 1, last->sub->full + last->len / 2 - last->sub->len);
            last->full = min(cur->full + 2, last->half + 1);
            last->full = min(last->full, last->fa->full + last->len - last->fa->len);
            ret = min(ret, last->full + N - last->len);
        }
        else last->full = last->len;
        return true;
    }
}

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%s", s); N = strlen(s); ret = N;
        PT::init(N);
        for (int i = 0; i < N; ++ i) PT::add(s[i]);
        printf("%d\n", ret);
    }
    return 0;
}
