struct SAM{
    struct Node{
        Node *parent, *ch[26];
        int val;
    };

    Node bar[N], *foo, *root, *last;

    Node* NewNode(int x) {
        MST(foo->ch, 0);
        foo->val = x;
        return foo++;
    }

    void extend(int w) {
        Node *p = last;
        Node *np = NewNode(p->val + 1);
        while (p && p->ch[w] == 0) p->ch[w] = np, p = p->parent;
        if (p == 0) np->parent = root;
        else {
            Node *q = p->ch[w];
            if (p->val + 1 == q->val) {
                np->parent = q;
            }
            else {
                Node  *nq = NewNode(p->val + 1);
                memcpy(nq->ch, q->ch, sizeof(q->ch));
                nq->parent = q->parent;
                q->parent = nq;
                np->parent = nq;
                while (p && p->ch[w] == q) p->ch[w] = nq, p = p->parent;
            }
        }
        last = np;
    }
}sam;
