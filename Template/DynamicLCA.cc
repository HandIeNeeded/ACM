int getLca(int a, int b, int rt) {
    int c = get(a, b);
    if (get(c, rt) != c) return c;
    int x = get(a, rt), y = get(b, rt);
    if (dep[x] > dep[y]) return x;
    return y;
}

