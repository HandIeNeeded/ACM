struct node
{
    node *ch[2], *f;
    bool sameLazy, revLazy;
    int sum, maxSum, size;
    int maxL, maxR, value;
} *root, *null;

node *newNode(int value)
{
    node *x = new node;
    x->sameLazy = x->revLazy = 0;
    x->maxL = x->maxR = x->maxSum = x->sum = x->value = value;
    x->size = 1;
    x->ch[0] = x->ch[1] = x->f = null;
    return x;
}

void update(node *tmp)
{
    if (tmp == null) return ;
    tmp->size = tmp->ch[0]->size + tmp->ch[1]->size + 1;
    tmp->sum = tmp->ch[0]->sum + tmp->ch[1]->sum + tmp->value;
    tmp->maxSum = max(max(tmp->ch[0]->maxSum, tmp->ch[1]->maxSum), tmp->value + max(0, tmp->ch[0]->maxR) + max(0, tmp->ch[1]->maxL));
    tmp->maxL = max(tmp->ch[0]->maxL, tmp->ch[0]->sum + tmp->value + max(0, tmp->ch[1]->maxL));
    tmp->maxR = max(tmp->ch[1]->maxR, tmp->ch[1]->sum + tmp->value + max(0, tmp->ch[0]->maxR));
}

void makeSameLazy(node *x, int value)
{
    if (x == null) return ;
    x->sameLazy = true;
    x->value = value;
    x->sum = x->value * x->size;
    x->maxL = x->maxR = x->maxSum = max(value, x->sum);
}

void makeRevLazy(node *x)
{
    if (x == null) return ;
    x->revLazy = !x->revLazy;
    swap(x->ch[1], x->ch[0]);
    swap(x->maxL, x->maxR);
}

node *buildTree(int l, int r, node *troot)
{
    if (l > r) return null;
    node *mid = newNode(insArr[l + r >> 1]);
    mid->f = troot;
    mid->ch[0] = buildTree(l, (l + r) / 2 - 1, mid);
    mid->ch[1] = buildTree((l + r) / 2 + 1, r, mid);
    update(mid);
    return mid;
}

void pushdown(node *x)
{
    if (x == null) return ;
    if (x->sameLazy) 
    {
	makeSameLazy(x->ch[0], x->value);
	makeSameLazy(x->ch[1], x->value);
	x->sameLazy = 0;
    }
    if (x->revLazy)
    {
	makeRevLazy(x->ch[0]);
	makeRevLazy(x->ch[1]);
	x->revLazy = 0;
    }
}

void rotate(node *x, int k)
{
    if (x == 0) return ;
    node *y = x->f;
    pushdown(y);
    pushdown(x);
    if (y->f != null) y->f->ch[y == y->f->ch[1]] = x;
    x->f = y->f;
    y->ch[k] = x->ch[1 - k];
    x->ch[1 - k] = y;
    y->f = x;
    if (y->ch[k] != null) y->ch[k]->f = y;
    if (x->ch[1 - k] != null) x->ch[1 - k]->f = x;
    update(y);
    update(x);
}

void splay(node *x, node *troot)
{
    if (x == null) return ;
    pushdown(x);
    for (; x->f != troot; )
    {
	node *y = x->f, *z = y->f;
 	if (z == troot) rotate(x, x->f->ch[1] == x);
	else if (z->ch[0] == y) 
	    if (y->ch[0] == x) rotate(y, 0), rotate(x, 0);
	    else rotate(x, 1), rotate(x, 0);
	else if (y->ch[1] == x) rotate(y, 1), rotate(x, 1);
	else rotate(x, 0), rotate(x, 1);
    }
    if (x->f == null) root = x;
}

void select(int num, node *troot)
{
    node *now = root;
    for (; num; )
    {
	pushdown(now); //!!!!
	if (now->ch[0]->size + 1 == num) break;
	if (now->ch[0]->size + 1 < num) num -= now->ch[0]->size + 1, now = now->ch[1];
	else now = now->ch[0];
    }
    splay(now, troot);
}

void ins(int pos, int len)
{
    REP(i, len)
	RI(insArr[i]);
    select(pos, null);
    select(pos + 1, root);
    root->ch[1]->ch[0] = buildTree(0, len - 1, root->ch[1]);
    splay(root->ch[1]->ch[0], null);
}

void del(int pos, int tot)
{
    select(pos - 1, null);
    select(pos + tot, root);
    root->ch[1]->ch[0] = null;
    update(root->ch[1]);
    update(root);
    splay(root->ch[1], null);
}

void modiSame(int pos, int tot)
{
    int value;
    RI(value);
    select(pos - 1, null);
    select(pos + tot, root);
    makeSameLazy(root->ch[1]->ch[0], value);
    splay(root->ch[1]->ch[0], null);
}

void reverse(int pos, int tot)
{
    select(pos - 1, null);
    select(pos + tot, root);
    makeRevLazy(root->ch[1]->ch[0]);
    splay(root->ch[1]->ch[0], null);
}

void getSum(int pos, int tot)
{
    select(pos - 1, null);
    select(pos + tot, root);
    PI(root->ch[1]->ch[0]->sum);
    splay(root->ch[1]->ch[0], null);
}

int main()
{
    fileOpen();
    RII(n, m);
    null = newNode(-INF);
    null->size = null->sum = 0;
    root = newNode(-INF);
    root->ch[1] = newNode(-INF);
    root->ch[1]->f = root;
    update(root);
    ins(1, n);
    for (; m; --m)
    {
	char st[20];
	scanf("%s", st);
	if (st[2] == 'X') printf("%d\n", root->maxSum);
	else {
	    int pos, tot;
	    scanf("%d%d", &pos, &tot);
	    if (st[2] == 'S') ins(pos + 1, tot); 
	    else if (st[2] == 'L') del(pos + 1, tot); 
	    else if (st[2] == 'K') modiSame(pos + 1, tot);
	    else if (st[2] == 'V') reverse(pos + 1, tot);
	    else if (st[2] == 'T') getSum(pos + 1, tot);
	}
    }
    return 0;
}
