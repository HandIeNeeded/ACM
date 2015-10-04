int tsize[N], key[N], cnt[N], weight[N] = {INT_MAX}, son[N][2], node = 1;

void maintain(int x) {
    tsize[x] = tsize[son[x][0]] + cnt[x] + tsize[son[x][1]];
}

void rotate(int &x, int t) {
    int y = son[x][t];	
    son[x][t] = son[y][1 ^ t];
    son[y][1 ^ t] = x;
    maintain(x), maintain(y);
    x = y;
}

void insert(int &x, int y) {
    if (x) {
        if (key[x] == y) {
            cnt[x]++;
        }
        else {
            int t = key[x] < y;
            insert(son[x][t], y);
            if (weight[x] > weight[son[x][t]]) rotate(x, t);
        }
    }
    else {
        x = node++;
        key[x] = y;
        MST(son[x], 0);
        weight[x] = rand();
        cnt[x] = 1;
    }
    maintain(x);
}

void erase(int &x, int y) {
    if (!x) return ;
    if (key[x] == y) {
        if (cnt[x] > 1) {
            cnt[x]--;
        }
        else {
            if (!tsize[son[x][0]] && !tsize[son[x][1]]) {
                x = 0;
                return ;
            }
            rotate(x, weight[son[x][0]] > weight[son[x][1]]);
            erase(x, k);
        }
    }
    else {
        erase(son[x][key[x] < y], y);
    }
    maintain(x);
}

int select(int &x, int y) {
    if (tsize[son[x][0]] >= y) {
        return select(son[x][0], y);
    }
    else if (tsize[son[x][0]] + cnt[x] >= y) {
        return key[x];
    }
    else {
        return select(son[x][1], y - cnt[x] - tsize[son[x][0]]);
    }
}
