const int N = 2e5 + 5;

struct Node{
	int val, size;
	Node *l, *r;

	void update() {
		size = l->size + 1 + r->size;
	}
}bar[N], *foo, *null, *root;

bool gen(double p) {
	double x = rand() % RAND_MAX;
	return x < p;
}

Node* merge(Node *a, Node *b) {
	if (a == null) return b;
	if (b == null) return a;
	if (gen(1.0 * a->size / (a->size + b->size))) {
		a->r = merge(a->r, b);
		a->update();
		return a;
	}
	else {
		b->l = merge(a, b->l);
		b->update();
		return b;
	}
}

pair<Node*, Node*> split(Node *u, int s) {
	if(u == null) return {null, null};
	Node *l = u->l, *r = u->r;
	u->l = u->r = null;
	u->update();
	if (l->size >= s) {
		pair<Node*, Node*> res = split(l, s);
		return {res.first, merge(merge(res.second, u), r)};
	}
	else {
		pair<Node*, Node*> res = split(r, s - (l->size + 1));
		return {merge(l, merge(u, res.first)), res.second};
	}
}

void print(Node *u) {
	if (u != null) {
		print(u->l);
		printf("%d ", u->val);
		print(u->r);
	}
}
