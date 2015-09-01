#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int> q;
#define N 100005
int a[N];
int n, x, y, h1, h2;

int main(){
   // freopen("in", "r", stdin);
    scanf("%d%d%d%d%d", &n, &x, &y, &h1, &h2);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    int now = 0, ans = 0, flag = 0;
    for (int i = 0; i < n; ++ i){
        h2 -= x;
        now ++;
        ans = max(ans, now);
        if (h2 <= 0){
            printf("Win\n%d\n", i + 1);
            flag = 1;
            break;
        }
        h1 -= a[i];
        q.push(a[i]);
        if (h1 <= 0){
            while (now > 0 && h1 <= 0){
                h2 += x;
                now --;
                if (!q.empty() && q.top() >= y){
                    h1 += q.top();
                    q.pop();
                } else {
                    h1 += y;
                }
            }
            if (h1 <= 0){
                break;
            }
        }
    }
    if (flag == 0){
        printf("Lose\n%d\n", ans * x);
    }
    return 0;
}
