void dfs(int x, int p) {
    //stdc++11 酷炫写法
    //for (auto &y: edge[x]) {
    //
    //}
    
    REP(i, edge[x].size()) {
        int y = edge[x][i];
        if (y != p) {
        //balabala
        }
    }

    for (int go = head[x]; go; go = next[go]) {
        int y = end[go];
        //balabala
    }
}
