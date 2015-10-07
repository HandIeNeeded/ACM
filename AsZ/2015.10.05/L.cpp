#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <string>
#include <iostream>
#define LIM 1
#define MAXCHAR 35
#define MAXN 200000

using namespace std;

int wq[] = {1201, 313, 3131, 31313};

unsigned long long pw[LIM][MAXN * 10];
char st[MAXCHAR];
int son[MAXN][26], val[MAXN];
int leng[MAXN];
set<unsigned long long> mp[LIM];
unsigned long long haNum[LIM][MAXN];

int cnt = 0, ans = 0, n, tot = 0;

void trieInsert() {
    int len = strlen(st);
    int tmp = 0;
    for (int i = 0; i < len; ++i) {
        int x = st[i] - 'a';
        if (son[tmp][x] == 0) son[tmp][x] = tot++;
        tmp = son[tmp][x];
    }
    val[tmp] = 1;
}

void dfs(int x) {
    leng[x] = 2;
    for (int t = 0; t < LIM; ++t)
        haNum[t][x] = val[x] ? '[' : '(';
    for (int i = 0; i < 26; ++i) {
        if (son[x][i]) {
            int v = son[x][i];
            dfs(son[x][i]);
            leng[x] += leng[v] + 2;
            for (int t = 0; t < LIM; ++t) {
                haNum[t][x] = haNum[t][x] * pw[t][1] + '(';
                haNum[t][x] = haNum[t][x] * pw[t][leng[v]] + haNum[t][v];
                haNum[t][x] = haNum[t][x] * pw[t][1] + ')';
            }
        } else {
            leng[x] += 3;
            for (int t = 0; t < LIM; ++t) {
                haNum[t][x] = haNum[t][x] * pw[t][1] + '(';
                haNum[t][x] = haNum[t][x] * pw[t][1] + '.';
                haNum[t][x] = haNum[t][x] * pw[t][1] + ')';
            }
        }
    }

    int flag = 0;
    for (int t = 0; t < LIM; ++t) {
        haNum[t][x] = haNum[t][x] * pw[t][1] + (val[x] ? ']' : ')');
        if (!mp[t].count(haNum[t][x])) {
            mp[t].insert(haNum[t][x]);
            flag = 1;
        } 
    }
    if (flag) ans++;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("L.in", "r", stdin);
#endif
    freopen("language.in", "r", stdin);
    freopen("language.out", "w", stdout);
    int n;
    scanf("%d", &n);
    tot = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%s", st);
        trieInsert();
    }
    for (int i = 0; i < LIM; ++i) {
        pw[i][0] = 1;
        for (int j = 1; j < MAXN * 10; ++j)
            pw[i][j] = pw[i][j - 1] * wq[i];
    }
    dfs(0);
    printf("%d\n", ans);
    return 0;
}
