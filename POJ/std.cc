#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long val_t;
const int MAX_DIG = 10, MAX_NUM = 9, STATE = 4;
const int trans[4][10] = {
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 2, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 3, 0, 0, 0},
    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3}
};
val_t f[MAX_DIG + 1][STATE];
int T, n;

int main() {
    f[0][3] = 1;
    for (int i = 1; i <= MAX_DIG; i ++)
        for (int j = 0; j < STATE; j ++)
            for (int k = 0; k <= MAX_NUM; k ++)
                f[i][j] += f[i - 1][trans[j][k]];
    for (scanf("%d", &T); T -- && scanf("%d", &n) != EOF; ) {
        int dig = 0;
        for (int i = 1; i <= MAX_DIG; i ++)
            if (f[i][0] >= n) {
                dig = i;
                break;
            }
        int st = 0;
        for (int i = dig; i >= 1; i --) {
            int cnt = 0;
            for (int j = 0; j <= MAX_NUM; j ++) {
                cnt += f[i - 1][trans[st][j]];
                if (cnt >= n) {
                    printf("%d", j);
                    cnt -= f[i - 1][trans[st][j]];
                    n -= cnt;
                    st = trans[st][j];
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
