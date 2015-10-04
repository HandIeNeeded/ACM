// a^x == b (mod p)

int BSGS(int a, int b, int p) { 
    int m, v, e = 1, i;
    m = (int) sqrt(p + 0.5) + 1;//这里不加1会出错的！
    v = pow_mod(pow_mod(a, m, p), p - 2, p);
    map<int, int> x;
    x[1] = 0;
    for (i = 1; i < m; ++i){
        e = e * a % p;
        if (!x.count(e)) x[e] = i;
    }
    for (i = 0; i < m; ++i){
        if (x.count(b)) return i * m + x[b];
        b = b * v % p;
    }
    return -1; // No solution
}
