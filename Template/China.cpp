LL a[N], mod[N]; //x == a[i] (mod mod[i]), i = 0, 1, ... , n - 1

void exgcd( LL a, LL b, LL &d, LL &x, LL &y){
    if (!b) d = a, x = 1, y = 0;
    else exgcd(b, a % b, d, y, x), y -= (a / b) * x;
}

LL china (LL n, LL *a, LL *mod){// i = 0, 1, ... , n - 1
    LL re = 0, M = 1;
    REP(i, n) M *= mod[i];
    REP(i, n) {
        LL d, x, y;
        exgcd(M / mod[i], mod[i], d, x, y);
        if (x < 0) x += M;
        re = (re + M / mod[i] * x * a[i]) % M; //be careful overflow
    }
    return (re + M) % M;
}
