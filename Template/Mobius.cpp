int m[N] = {0, 1}, vis[N], p[N], cnt;

void mobius(int n){
    for (int i = 2; i <= n; ++i){
        if (!vis[i]){
            m[i] = -1;
            p[cnt++] = i;
        }
        for (int j = 0; j < cnt && i * p[j] <= n; ++j){
            if (i % p[j] == 0) {
                vis[i * p[j]] = 1, m[i * p[j]] = 0;
                break;
            }
            else vis[i * p[j]] = 1, m[i * p[j]] = -m[i];
        }
    }
}

