int match[N], vis[N]; 
//vis[x] 右边x有没有被访问过 match[x] 右边x所匹配的边

bool dfs(int x) {//x为来自左边的点
    for (int go = fi[x]; go; go = ne[go]) if (!vis[en[go]]) {
        vis[en[go]] = 1;
        if (!match[en[go]] || dfs(match[en[go]])) {
            match[en[go]] = x;
            return true;
        }
    }
    return false;
}

int Hungarian(){
    int ans = 0;
    MST(match, 0);
    REPP(i, 1, n) {
        MST(vis);
        if (dfs(i)) ans++;
    }
    return ans;
}
