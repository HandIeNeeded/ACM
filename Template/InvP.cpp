//O(n)
inv[0] = 0, inv[1] = 1;
REPP(i, 2, N - 1) inv[i] = 1LL * (MO - MO / i) * inv[MO % i] % MO;
