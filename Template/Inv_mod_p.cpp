//O(n)
inv[0] = inv[1] = 1;
REPP(i, 2, N - 1) inv[i] = ((-MOD / i * inv[MOD % i]) % MOD + MOD) % MOD;
