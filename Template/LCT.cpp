struct node
{
    bool rev;
    int value, vLazy, max;
    node *f, *son[2];
} g[N], *null;
    
void origin()
{
    null = new node;
    null->f = null->son[0] = null->son[1] = null;
    null->max = null->value = null->vLazy = 0;
    null->rev = false;
    REP(i, n + 1)
    {
	g[i].f = g[i].son[0] = g[i].son[1] = null;
	g[i].max = g[i].value = g[i].vLazy = 0;
	g[i].rev = false;
    }
}

void makeRev(node *x)
{
    if (x == null) return ;
    swap(x->son[0], x->son[1]);
    x->rev = !x->rev;
}

void makeVLazy(node *x, int value)
{
    if (x == null) return ;
    x->max += value;
    x->value += value;
    x->vLazy += value;
}

void update(node *x)
{
    if (x == null) return ;
    x->max = max(x->value, max(x->son[0]->max, x->son[1]->max));
}

void pushDown(node *x)
{
    if (x == null) return ;
    if (x->rev) 
    {
	makeRev(x->son[0]);
	makeRev(x->son[1]);
	x->rev = false;
    }
    if (x->vLazy)
    {
	makeVLazy(x->son[0], x->vLazy);
	makeVLazy(x->son[1], x->vLazy);
	x->vLazy = 0;
    }
}

bool ifRoot(node *x)
{
    if (x->f == null) return true;
    return (x->f->son[0] != x) && (x->f->son[1] != x);
}

void rotate(node *x, node *y, int p)
{
    node *z = y->f;
    x->f = z;
    if (!ifRoot(y)) z->son[z->son[1] == y] = x;
    y->son[p] = x->son[1 - p];
    x->son[1 - p] = y;
    if (y->son[p] != null)
	y->son[p]->f = y;
    if (x->son[1 - p] != null)
	x->son[1 - p]->f = x;
    update(y);
    update(x);
    update(z);
}

void splay(node *x)
{
    if (x == null) return ;
    pushDown(x);
    for (;!ifRoot(x);)
    {
	node *y = x->f, *z = y->f;
	pushDown(z);
	pushDown(y);
	pushDown(x);
	int p = (y->son[1] == x);
	int q = (z->son[1] == y);
	if (ifRoot(y)) rotate(x, y, p);
	else if (p == q) rotate(y, z, p), rotate(x, y, p);
	else rotate(x, y, p), rotate(x, z, q);
    }
}

node* access(node* u)
{
    node* v = null;
    for (; u != null; u = u->f)
    {
	splay(u);
	u->son[1] = v;
	v = u;
	update(u);
    }
    return v;
}

void evert(node * x)
{
    node *tmp = access(x);
    makeRev(tmp);
    splay(x);
}

node* getRoot(node *x)
{
    access(x);
    splay(x);
    node *tmp = x;
    for (; tmp->son[0] != null; tmp = tmp->son[0])
	pushDown(tmp);
    return tmp;
}

void link(node * const x, node * const y)
{
    if (getRoot(x) == getRoot(y))
    {
	PI(-1);
	return ;
    }
    evert(x);
    x->f = y;
    access(x);
}

void cut(node *x, node *y)
{
    if ((x == y) || (getRoot(x) != getRoot(y)))
    {
	PI(-1);
	return ;
    }
    evert(x);
    access(y);
    splay(y);
    y->son[0]->f = null;
    y->son[0] = null;
    update(y);
}

void add(node *x, node *y, int w)
{
    if (getRoot(x) != getRoot(y))
    {
	PI(-1);
	return ;
    }
    evert(x);
    access(y);
    splay(x);
    makeVLazy(x, w);
}

void ask(node *x, node *y)
{
    if (getRoot(x) != getRoot(y))
    {
	PI(-1);
	return ;
    }
    evert(x);
    access(y);
    splay(x);
    PI(x->max);
}

int main()
{
    for (;scanf("%d", &n) != EOF;)
    {
	origin();
	REP(tt, n - 1)
	{
	    int u, v;
	    RII(u, v);
	    link(u + g, v + g);
	}
	REPP(i, 1, n)
	{
	    int w;
	    RI(w);
	    access(g + i);
	    splay(g + i);
	    g[i].value = w;
	    g[i].max = max(g[i].max, w);
	}
}
