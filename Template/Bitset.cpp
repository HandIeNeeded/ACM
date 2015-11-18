//枚举下一个二进制含有N个1的数
int getnext (int x) {
    int b, t, c, r, m;
    b = x & -x;
    t = x + b;
    c = t ^ x;
    m = (c >> 2) / b;
    r = t | m;
    return r;
}

//枚举子集 max --> min
for (int sub = all; sub; sub = all & (sub - 1)) 
