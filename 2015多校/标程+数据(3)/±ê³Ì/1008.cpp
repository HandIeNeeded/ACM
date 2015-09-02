#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <assert.h>
#include <time.h>
typedef long long LL;

const LL Inf = (LL)1e30;
LL n;

void search(LL l,LL r) {
    if (l < 0 || l > r) return ;

    if (l == 0) {
        n = std::min(n,r);
        return ;
    }

    LL len = r - l + 1;

    if (l < len) return ;
    search(l,r + len);
    if (len != 1) {
        search(l,r + len - 1);
    }
    search(l - len,r);
    search(l - len - 1,r);
}

LL work(int l,int r) {
    n = Inf;
    search(l,r);
    return n == Inf ? -1 : n;
}

int main() {
    freopen("SegmentTree.in","r",stdin);
    freopen("SegmentTree.out","w",stdout);
    int l,r;
    while (scanf("%d%d",&l,&r) == 2) {
        assert(0 <= l && l <= (int)1e9);
        assert(0 <= r && r <= (int)1e9);
        assert(l <= r);
        assert(l / (r - l + 1) <= 2015);
        printf("%I64d\n",work(l,r));
    }
    //fprintf(stderr,"%.10f\n",(double)clock() / CLOCKS_PER_SEC);
}

