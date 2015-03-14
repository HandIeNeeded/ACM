struct Node{
	int value, size;
	Node *l, *r;

	Node* update() {
		size = l->size + 1 + r->size;
		return this;
	}
}bar[N], *foo, *rt[N], *null;

void init() {
	foo = null = bar;
	null->l = null->r = null;
	foo++;
}

Node* New_Node(int x) {
	return new(foo++) (Node) {x, 1, null, null};
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

void show(Node *u) {
	if (u == null) return ;
	else {
		show(u->l);
		printf("value: %d\n", u->value);
		show(u->r);
	}
}

pair<int, bool> find(Node *u, int x) {
	if (u == null) return {0, 0};
	if (u->value == x) {
		return {u->l->size + 1, 1};
	}
	else if (u->value < x) {
		pair<int, bool> res = find(u->r, x);
		res.first += u->l->size + 1;
		return res;
	}
	else {
		return find(u->l, x);
	}
}

void insert(Node *a, Node *&u) {
	pair<int, bool> ans = find(u, a->value);
	if (!ans.second) {
		PNN res = split(u, ans.first);
		u = a;
		u = merge(res.first, u);
		u = merge(u, res.second);
	}
}

void dfs(Node *a, Node *&b) {
	if (a == null) return ;
	else {
		dfs(a->l, b);
		dfs(a->r, b);
		a->l = a->r = null;
		insert(a->update(), b);
	}
}

Node* combine(Node *a, Node *b) {
	if (a->size > b->size) {
		swap(a, b);
	}
	dfs(a, b);
	return b;
}
