struct PT{
    struct Node{
        Node *ch[C], *suffix;
        int len;
    }bar[N], *foo, *last, *odd, *even;
    char s[N];
    int n, cnt;//cnt = foo - bar = count of palindromes, n the number of char added

    void init() {
        odd = bar, even = last = odd + 1, foo = even + 1;
        MST(odd->ch, 0), MST(even->ch, 0);
        odd->suffix = even->suffix = odd;
        odd->len = -1, even->len = 0;
        n = 0, cnt = 2;//root
    }

    Node* New_Node(int x) {
        MST(foo->ch, 0), foo->len = x;
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
            return 1;
        }
        else {
            last = p->ch[x];
            return 0;
        }
    }
};

