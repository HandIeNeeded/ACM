#include <algorithm>
#include <cstdio>
#include <utility>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

#define X first
#define Y second

const int MX = 200005;
const int INF = 2000000000;
struct Node;
typedef pair <Node*, Node*> Pair;
Node *null;

struct Node {
    int val, size;
    Node *left, *right;
    
    Node (int val, int size, Node *left, Node *right) :
        val(val), size(size), left(left), right(right) {}
    
    Node *Update() {
        size = left->size + 1 + right->size;
        return this;
    }
    
    int askLess(const int &x) {
        if (this == null) return 0;
        if (val < x) return left->size + 1 + right->askLess(x);
		else return left->askLess(x);
    }
    Pair Split(int n, int type) {
		if (this == null)
	        return make_pair(null, null);
		
		if (type == 1 && val == n) {
			return make_pair(left, right);
		}
		
	    if (!(val < n)) {
	        Pair ret = left->Split(n, type);
	        left = ret.Y;
	        return make_pair(ret.X, this->Update());
	    }
	     
	    Pair ret = right->Split(n, type);
	    right = ret.X;
	    return make_pair(this->Update(), ret.Y);
	}
};

struct BST {
	Node *root;
	
	inline int ran() {
	    static int x = 1;
	    x += (x << 1) + 1;
	    return x & 2147483647;
	}
	Node *Merge(Node *a, Node *b) {
	    if (a == null) return b;
	    if (b == null) return a;
	    
	    if (ran() % (a->size + b->size) < a->size) {
	        a->right = Merge(a->right, b);
	        return a->Update();
	    }
	    
	    b->left = Merge(a, b->left);
	    return b->Update();
	}
	
	void add(int b) {
		Pair ret = root->Split(b, 0);
		root = Merge(ret.X, Merge(new Node(b, 1, null, null), ret.Y));
	}
	void del(int b) {
		Pair ret = root->Split(b, 1);
		root = Merge(ret.X, ret.Y);
	}
	int getLess(int b) {
		return root->askLess(b);
	}
	
} tr[MX];

struct Query {
	int t, l, r, k;
	
	void in() {
		scanf("%d", &t);
		if (t == 1) scanf("%d%d", &l, &k);
		else scanf("%d%d%d", &l, &r, &k);
	}
	
} q[MX];

int a[MX];
int p[MX], pn;
int L;

void add(int p, int v) {
	for (p++; p <= pn; p += p & -p) {
		tr[p].add(v);
	}
}
void del(int p, int v) {
	for (p++; p <= pn; p += p & -p) {
		tr[p].del(v);
	}
}

int calc(int l, int r, int k) {
	int cur = 0;
	for (int i = L; i; i /= 2) {
		int u = cur + i;
		if (u > pn) continue;
		
		int cnt = tr[u].getLess(r + 1) - tr[u].getLess(l);
		if (cnt >= k) continue;
		cur = u, k -= cnt;
	}
	return cur + 1;
}

int main() {
	int n, Q;
	int i;
	//freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
	while(scanf("%d", &n)!=EOF){
	
	for (i = 1; i <= n; i++) {
		scanf("%d", a + i);
		p[pn++] = a[i];
	}
	
	scanf("%d", &Q);
	for (i = 1; i <= Q; i++) {
		q[i].in();
		if (q[i].t == 1) p[pn++] = q[i].k;
	}
	
	sort(p, p + pn);
	pn = unique(p, p + pn) - p;
	for (L = 1; L <= pn; L *= 2);
	L /= 2;
	
	null = new Node(0, 0, NULL, NULL);
	for (i = 1; i <= pn; i++)
		tr[i].root = null;
	
	for (i = 1; i <= n; i++) {
		a[i] = lower_bound(p, p + pn, a[i]) - p;
		add(a[i], i);
	}
	
	for (i = 1; i <= Q; i++)
		if (q[i].t == 1) q[i].k = lower_bound(p, p + pn, q[i].k) - p;
	
	for (i = 1; i <= Q; i++) {
		if (q[i].t == 1) {
			int u = q[i].l;
			del(a[u], u);
			a[u] = q[i].k;
			add(a[u], u);
			
		} else {
			int u = calc(q[i].l, q[i].r, q[i].k);
			printf("%d\n", p[u - 1]);
		}
	}
}
	return 0;
}
