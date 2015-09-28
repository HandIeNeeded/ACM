#include <bits/stdc++.h>

const int N = 100000 + 5;
std::pair<int,int> A[N];
int n;

int C[N];

void modify(int p,int dt) {
    for (int i = p; i <= n; i += i & -i)
        C[i] += dt;
}

int query(int p) {
    int ret = 0;
    for (int i = p; i > 0; i -= i & -i) {
        ret += C[i];
    }
    return ret;
}

int Kth(int K) {
    int p = 0;
    for (int i = 18; i >= 0; -- i) {
        p += 1 << i;
        if (p > n || K <= C[p]) p -= 1 << i;
        else K -= C[p];
    }
    return p + 1;
}

int result[N];

bool work() {
    std::sort(A,A + n);
    std::fill(C,C + n + 1,0);
    for (int i = 1; i <= n; ++ i) {
        modify(i,1);
    }
    for (int i = 1; i <= n; ++ i) {
        int k = A[i - 1].second;
        int h = A[i - 1].first;
        if (k > n - i)
            return false;
        int a = Kth(k + 1);
        int b = Kth(n - i + 1 - k);
        if (a < b) {
            result[a] = h;
            modify(a,-1);
        } else {
            result[b] = h;
            modify(b,-1);
        }
    }

    for (int i = 1; i <= n; ++ i) {
        printf("%d",result[i]);
        if (i != n) putchar(' ');
    }
    puts("");
    return true;
}


int main() {
    int cas,ca = 0;
    scanf("%d",&cas);
    while (cas--) {
        scanf("%d",&n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d%d",&A[i].first,&A[i].second);
        }
        printf("Case #%d: ",++ca);
        if (!work()) {
            puts("impossible");
        }
    }
}
