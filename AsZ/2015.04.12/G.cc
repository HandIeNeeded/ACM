#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int C = 26;
const int N = 2e5 + 5;

struct Node{
    Node *ch[C], *suffix;
    int len, dp;
};

struct PT{
    Node bar[N], *foo, *last, *odd, *even;
    char s[N];
    int n, cnt;//cnt = foo - bar = count of palindromes, n the number of char added

    void init() {
        odd = bar, even = last = odd + 1, foo = even + 1;
        MST(odd->ch, 0), MST(even->ch, 0);
        odd->suffix = even->suffix = odd;
        odd->len = -1, even->len = 0;
        n = 0, cnt = 2;
    }

    Node* New_Node(int x) {
        MST(foo->ch, 0), foo->len = x;
        foo->dp = 0;
        return foo++;
    }

    int index(char c) {
        return c - 'a';
    }

    Node* get(Node *p) {
        while (n - p->len - 2 < 0 || s[n - p->len - 2] != s[n - 1]) p = p->suffix;
        return p;
    }

    bool add(char c) {
        int x = index(c); s[n++] = c;
        Node *p = get(last);
        if (!p->ch[x]) {
            last = New_Node(p->len + 2);
            if (last->len == 1) {
                last->suffix = even;
            }
            else last->suffix = get(p->suffix)->ch[x];//guarantee proper suffix
            p->ch[x] = last;
            cnt++;
            last->dp = 1;
            return 1;
        }
        else {
            last = p->ch[x];
            last->dp++;
            return 0;
        }
    }
}A, B;

char s[N], r[N];

LL bfs(Node *a, Node *b) {
    queue<Node*> q;
    q.push(a), q.push(b);
    LL ans = 0;
    while (q.size()) {
        a = q.front(); q.pop();
        b = q.front(); q.pop();
        ans += 1LL * a->dp * b->dp;
        REP(i, C) {
            if (!a->ch[i] || !b->ch[i]) continue;
            else {
                q.push(a->ch[i]);
                q.push(b->ch[i]);
            }
        }
    }
    return ans;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
#ifndef HOME
#define lld I64d
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%s%s", s, r);
        int n = strlen(s), m = strlen(r);
        //cout << s << ' ' << r << endl;
        //cout << n << ' ' << m << endl;
        A.init(), B.init();
        REP(i, n) A.add(s[i]);
        REP(i, m) B.add(r[i]);
        for (int i = A.cnt - 1; i > 1; i--) {
            Node *tmp = A.bar + i;
            tmp->suffix->dp += tmp->dp;
        }
        for (int i = B.cnt - 1; i > 1; i--) {
            Node *tmp = B.bar + i;
            tmp->suffix->dp += tmp->dp;
        }
        REP(i, 2) A.bar[i].dp = 0, B.bar[i].dp = 0;
        LL ans = bfs(A.odd, B.odd);
        ans += bfs(A.even, B.even);
        printf("Case #%d: ", ca++);
        printf("%lld\n", ans);
    }
    return 0;
}
