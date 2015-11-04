#include <bits/stdc++.h>
using namespace std;

int F[1000010];
bool flag[1000010];
int S[7][10000010];
void init()
{
    for(int i = 2; i <= 1000000; i++) if(!flag[i]){
        F[i]++;
        for(int j = i + i; j <= 1000000; j += i) {
            flag[j] = true;    
            F[j]++;
        }
    }
    for(int i = 2; i <= 1000000; i++) {
        for(int j = 0; j < 7; j++) {
            S[j][i] = S[j][i - 1] + (F[i] == j + 1);
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    init();
    int T, l, r;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &l, &r);
        assert(l != r);
        int cnt[8];
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < 7; i++) {
            cnt[i + 1] = S[i][r] - S[i][l - 1];
        }
        int ret = 1;
        if(cnt[2] + cnt[4] + cnt[6]>=2) ret = 2;
        if(cnt[3] + cnt[6] >= 2) ret = 3;
        if(cnt[4] >= 2) ret = 4;
        if(cnt[5] >= 2) ret = 5;
        if(cnt[6] >= 2) ret = 6;
        if(cnt[7] >= 2) ret = 7;
        printf("%d\n", ret);
    }
    return 0;
}
