#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAXCHAR 35
#define MAXN 200000
#include <map>
#include <string>
#include <iostream>
#define LIM 4
#define MO 1234567891LL

using namespace std;


int wq[LIM] = {1201, 313, 3131, 31313};

long long pw[LIM][MAXN * 10];
int n, tot = 0;
char st[MAXCHAR];
int son[MAXN][26];
int leng[MAXN];
map <long long, int> mp[LIM];
long long haNum[LIM][MAXN];


int cnt = 0, ans = 0;


void trieInsert() {
    int len = strlen(st);
    int tmp = 0;
    for (int i = 0; i < len; ++i) {
        int x = st[i] - 'a';
        if (son[tmp][x] == 0) son[tmp][x] = tot++;
        tmp = son[tmp][x];
    }
}

void dfs(int x) {
    leng[x] = 2;
    for (int t = 0; t < LIM; ++t)
        haNum[t][x] = '(';
    for (int i = 0; i < 26; ++i) {
        if (son[x][i]) {
            int v = son[x][i];
            dfs(son[x][i]);
            leng[x] += leng[v] + 2;
            for (int t = 0; t < LIM; ++t) {
                haNum[t][x] = (haNum[t][x] * pw[t][1] % MO + '(') % MO;
                haNum[t][x] = (haNum[t][x] * pw[t][leng[v]] % MO + haNum[t][v]) % MO;
                haNum[t][x] = (haNum[t][x] * pw[t][1] % MO + ')') % MO;
            }
           // dep[x] = max(dep[x], dep[son[x][i]] + 1);
        } else {
            leng[x] += 3;
            for (int t = 0; t < LIM; ++t) {
                haNum[t][x] = (haNum[t][x] * pw[t][1] % MO + '(') % MO;
                haNum[t][x] = (haNum[t][x] * pw[t][1] % MO + '.') % MO;
                haNum[t][x] = (haNum[t][x] * pw[t][1] % MO + ')') % MO;
            }
        }
    }

  //  cout << ha[x] << endl;
    int flag = 0;
    for (int t = 0; t < LIM; ++t) {
        haNum[t][x] = (haNum[t][x] * pw[t][1] % MO + ')') % MO;
        if (!mp[t].count(haNum[t][x])) {
            mp[t][haNum[t][x]] = ++cnt;
        } else flag = 1;
    } //haNum[x] = mp[ha[x]];
    if (!flag) ans++;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("L.in", "r", stdin);
#endif
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
            pw[i][j] = pw[i][j - 1] * wq[i] % MO;
    }
    dfs(0);
    //cout << tot << endl;
   // for (int i = 0; i < tot; ++i)
     //   lab[i] = i;
   // sort(lab, lab + tot, com);
   // for (int i = 0; i < tot; ++i) {
     //   int u = lab[i];
      //  int j = i;
      //  for (; j + 1 < tot && dep[lab[j + 1]] == dep[u]; ++j);

   // }
    printf("%d\n", ans);
    return 0;
}
