#include <bits/stdc++.h>

const int N = 2000 + 5;
int pos[N];
int n;
int ptr;
int m;

std::vector<std::pair<int,int>> blocks;

int get(int len) {
    for (int i = 0; i + 1 < blocks.size(); ++ i) {
        if (blocks[i].first + blocks[i].second + len <= blocks[i + 1].first) {
            return blocks[i].first + blocks[i].second;
        }
    }
    return -1;
}

void remove(int pos) {
    for (int i = 0; i < blocks.size(); ++ i) {
        if (blocks[i].first == pos) {
            for (int j = i + 1; j < blocks.size(); ++ j) {
                blocks[j - 1] = blocks[j];
            }
            return ;
        }
    }
}

void solve(int id,int b) {
    int p = -1;
    while (true) {
        p = get(b);
        if (p == -1) {
            ++ ptr;
            remove(pos[ptr]);
        } else {
            break;
        }
    }
    pos[id] = p;
    blocks.push_back({p,b});
    std::sort(blocks.begin(),blocks.end());
}

int main() {
    scanf("%d%d",&n,&m);
    blocks.push_back({-1,1});
    blocks.push_back({m,1});
    for (int i = 1; i <= n; ++ i) {
        int x;
        scanf("%d",&x);
        solve(i,x);
    }
    for (int i = ptr + 1; i <= n; ++ i) {
        printf("%d %d\n",i,pos[i]);
    }
}
