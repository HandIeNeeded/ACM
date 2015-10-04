struct Edge{
    int dist, next, ed;
}e[M];

int edge, head[N], start[N];

void add(int x, int y) {
    e[++edge].next = head[x];
    head[x] = edge;
    e[edge].ed = y;
}

void add(int x, int y, int z) {
    e[++edge].next = start[x];
    start[x] = edge;
    e[edge].ed = y;
    e[edge].dist = z;
}

int n, m;
int vis[N], size[N], maxsub[N], root;
int dist[N];

void dfs_size(int x, int p = 0) {
    size[x] = 1, maxsub[x] = 0;
    for (int go = head[x]; go; go = e[go].next) {
        int y = e[go].ed;
        if (y != p && !vis[y]) {
            dfs_size(y, x);
            size[x] += size[y];
            if (size[y] > maxsub[x]) maxsub[x] = size[y];
        }
    }
}

void dfs_root(int x, int tot, int p = 0) {
    if (tot - size[x] > maxsub[x]) maxsub[x] = tot - size[x];
    if (maxsub[x] < maxsub[0]) maxsub[0] = maxsub[x], root = x;
    for (int go = head[x]; go; go = e[go].next) {
        int y = e[go].ed;
        if (y != p && !vis[y]) {
            dfs_root(y, tot, x);
        }
    }
}

void dfs_dist(int x, int p = 0, int dep = 0) {
    add(x, root, dep);
    for (int go = head[x]; go; go = e[go].next) {
        int y = e[go].ed;
        if (!vis[y] && y != p) {
            dfs_dist(y, x, dep + 1);
        }
    }
}

void divide(int x) {
    maxsub[0] = N;
    dfs_size(x);
    dfs_root(x, size[x]);
    dfs_dist(root);
    vis[root] = 1;
    for (int go = head[root]; go; go = e[go].next) {
        int y = e[go].ed;
        if (!vis[y]) divide(y);
    }
}
