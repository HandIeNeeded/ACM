#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <time.h>
#include <assert.h>

const int N = 50000 + 5;

int L[N],R[N],idx[N],next[N],best[N];
int n;

struct San : std::vector<int> {
    void prepare() {
        std::sort(begin(),end());
        erase(std::unique(begin(),end()),end());
    }

    int get(int x) {
        return std::lower_bound(begin(),end(),x) - begin();
    }
} sl,sr;

bool cmp(int a,int b) {
    return L[a] < L[b];
}

struct Bit {
    std::pair<int,int> C[N];

    void modify(int p,std::pair<int,int> dt) {
        for (int i = p; i >= 0; i -= ~i & i + 1) C[i] = dt;
    }

    void update(int p,std::pair<int,int> dt) {
        for (int i = p; i >= 0; i -= ~i & i + 1) C[i] = std::max(C[i],dt);
    }

    std::pair<int,int> query(int p) {
        std::pair<int,int> ret(0,-n);
        for (int i = p; i < N; i += ~i & i + 1) ret = std::max(ret,C[i]);
        return ret;
    }
} bit;

void divide(int l,int r) {
    if (l == r) return ;
    int mid = l + r >> 1;
    divide(mid + 1,r);
    for (int i = l; i <= r; ++ i) {
        idx[i] = i;
    }
    std::sort(idx + l,idx + mid + 1,cmp);
    std::sort(idx + mid + 1,idx + r + 1,cmp);
    for (int i = l,j = mid + 1; i <= mid; ++ i) {
        while (j <= r && L[idx[j]] <= L[idx[i]]) {
            bit.update(R[idx[j]],std::make_pair(best[idx[j]],-idx[j]));
            ++ j;
        }
        std::pair<int,int> tmp = bit.query(R[idx[i]]);
        if (tmp.first + 1 > best[idx[i]] || tmp.first + 1 == best[idx[i]] && -tmp.second < next[idx[i]]) {
            best[idx[i]] = tmp.first + 1;
            next[idx[i]] = -tmp.second;
        }
    }
    for (int i = mid + 1; i <= r; ++ i) {
        bit.modify(R[i],std::make_pair(0,-n));
    }
    divide(l,mid);
}

void work() {
    sl.clear();
    sr.clear();
    for (int i = 0; i < n; ++ i) {
        best[i] = 1;
        next[i] = n;
        sl.push_back(L[i]);
        sr.push_back(R[i]);
    }
    sl.prepare();
    sr.prepare();
    for (int i = 0; i < n; ++ i) {
        L[i] = sl.get(L[i]);
        R[i] = sr.get(R[i]);
    }
    std::fill(bit.C,bit.C + N,std::make_pair(0,-n));
    divide(0,n - 1);

    int p = 0;
    for (int i = 0; i < n; ++ i) {
        if (best[i] > best[p]) {
            p = i;
        }
    }
    printf("%d\n",best[p]);
    std::vector<int> answer;
    for (int i = p; i < n; i = next[i]) {
        answer.push_back(i);
    }
    for (int i = 0; i < answer.size(); ++ i) {
        if (i) putchar(' ');
        printf("%d",answer[i] + 1);
    }
    puts("");
}

int main() {
    freopen("Simple.in","r",stdin);
    freopen("Simple.out","w",stdout);
    while (scanf("%d",&n) == 1) {
        assert(1 <= n && n <= 50000);
        for (int i = 0; i < n; ++ i) {
            scanf("%d",L + i);
            assert(1 <= L[i] && L[i] <= (int)1e9);
        }
        for (int i = 0; i < n; ++ i) {
            scanf("%d",R + i);
            assert(1 <= R[i] && R[i] <= (int)1e9);
        }
        work();
    }
    //fprintf(stderr,"%.10f\n",clock() * 1. / CLOCKS_PER_SEC);
}
