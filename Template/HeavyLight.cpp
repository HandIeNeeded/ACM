int top[N], pos[N], l[N], r[N], pre[N], son[N], size[N], inv[N], dep[N], now;

void dfs(int x, int p) {
    pre[x] = p, size[x] = 1, son[x] = 0;
    dep[x] = dep[p] + 1;
    for (int go = fi[x]; go; go = ne[go]) {
        int y = en[go];
        if (y != p) {
            dfs(y, x);
            size[x] += size[y];
            if (size[y] > size[son[x]]) {
                son[x] = y;
            }
        }
    }
}

void divide(int x, int tp) {
    top[x] = tp, pos[x] = l[x] = now, inv[now++] = x;
    if (son[x]) divide(son[x], tp);
    for (int go = fi[x]; go; go = ne[go]) {
        int y = en[go];
        if (y != pre[x] && y != son[x]) {
            divide(y, y);
        }
    }
    r[x] = now - 1;
}

int query(int a, int b) {
    int ans = -INT_MAX;
    while (top[a] - top[b]) {
        if (dep[top[a]] > dep[top[b]]) {
            swap(a, b);
        }
        ql = pos[top[b]], qr = pos[b];
        ans = max(ans, query(1, 1, n));
        b = pre[top[b]];
    }
    //if (a == b) return ans; edge
    if (dep[a] > dep[b]) swap(a, b);
    //ql = pos[son[a]], qr = pos[b]; edge
    ql = pos[a], qr = pos[b];
    ans = max(ans, query(1, 1, n));
    return ans;
}
