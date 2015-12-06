#include <bits/stdc++.h>
#define MAXN 512345

using namespace std;

struct node {
    int v, lab;
    long long sum;
} p[MAXN], d[MAXN];

int com(node A, node B) {
    return A.v > B.v;
}

int randomx() {
    return rand() % 50000;
}

int main() {
    freopen("buffcraft.in", "r", stdin);
//#ifndef HOME
    freopen("buffcraft.out", "w", stdout);
//#endif // HOME
    int b, k, cd, cp;
    scanf("%d%d%d%d", &b, &k, &cd, &cp);
  //  for (int ca = 1; ca <= 100; ++ca) {
   // b = randomx();
   // k = randomx();
    //cd = randomx();
    //cp = randomx();

    for (int i = 1; i <= cd; ++i) {
        scanf("%d", &d[i].v);

  //      d[i].v = randomx();
        d[i].lab = i;
    }
    for (int i = 1; i <= cp; ++i) {
        scanf("%d", &p[i].v);

      //  p[i].v = randomx();
        p[i].lab = i;
    }
    sort(d + 1, d + cd + 1, com);
    sort(p + 1, p + cp + 1, com);

    for (int i = 1; i <= cd; ++i)
        d[i].sum = d[i - 1].sum + d[i].v;
    for (int i = 1; i <= cp; ++i)
        p[i].sum = p[i - 1].sum + p[i].v;

    long long ans = 0;
    int ansKd = 0, ansKp = 0;
    for (int kd = 0; kd <= min(k, cd); ++kd) {
        int kp = min(cp, k - kd);
        //kp = max(kp, 0);
        long long sd = d[kd].sum;
        long long sp = p[kp].sum;
        long long tmp = (sd + b) * (100 + sp);
        if (tmp > ans) {
            ansKd = kd;
            ansKp = kp;
            ans = tmp;
        }
    }
    printf("%d %d\n", ansKd, ansKp);
    for (int i = 1; i <= ansKd; ++i)
        printf("%d%c", d[i].lab, " \n"[i == ansKd]);

    for (int i = 1; i <= ansKp; ++i)
        printf("%d%c", p[i].lab, " \n"[i == ansKp]);
//    }
    return 0;
}
