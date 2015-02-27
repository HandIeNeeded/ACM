const int N = 2e5 + 5;

struct Node{
	int value, size;
	Node *l, *r;

	Node* update() {
		size = l->size + 1 + r->size;
		return this;
	}
}*root, *null;

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
