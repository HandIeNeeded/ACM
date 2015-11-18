struct Manacher{
    int p[N << 1], n; //p 回文向两边扩展的长度, p[i]-1就是原串对应位置的最长回文长度
    char r[N << 1]; //为了避免边界问题, r是原串的基础上间隔加上'#', 另外开始的时候加一个'$'. 所以s[i] = r[2 * (i + 1)]

    void init(char *s) {
        n = 0, r[n++] = '$';
        while (*s) {
            r[n++] = '#', r[n++] = *s++;
        }
        r[n++] = '#', r[n] = 0;
    }

    void get() {
        int id = 1, mx = 2;
        p[0] = p[1] = 1;
        REPP(i, 2, n - 1) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (r[i + p[i]] == r[i - p[i]]) p[i]++;
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
        }
    }
}M;

