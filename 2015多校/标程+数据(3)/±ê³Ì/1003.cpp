#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <functional>
#include <algorithm>
typedef long long LL;
using namespace std;

const int MOD = 1000000007;

int dp[55][55];
bool connect(int a, int b)
{
    int dig1[10], tot1=0;
    for(;a;a/=10) dig1[tot1++]=a%10;

    int dig2[10], tot2=0;
    for(;b;b/=10) dig2[tot2++]=b%10;
    int ret = -1;
    for(int len = 1; len <= min(tot1, tot2); len++) {
        bool flag = false;
        for(int i = len - 1; i >= 0; i--) {
            if(dig1[i] != dig2[tot2 - (len - i)]) {
                flag = true;
                break;
            }
        }
        if(!flag) {
            ret = len;
        }
    }
    if(ret >= 2) return true;
    return false;
}

int a[55][55];
int sz;
struct Mat
{
    int mat[50][50];
    void init() {
        memset(mat, 0, sizeof(mat));
    }
    void print() {
        for(int i = 0; i < sz; i++) {
            for(int j = 0; j < sz; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};
Mat operator * (const Mat& a, const Mat &b)
{
    Mat c; 
    for(int i = 0; i < sz; i++) {
        for(int j = 0; j < sz; j++) {
            c.mat[i][j] = 0;
            for(int k = 0; k < sz; k++) {
                c.mat[i][j] += 1LL * a.mat[i][k] * b.mat[k][j] % MOD;
                c.mat[i][j] %= MOD;
            }
        }
    }
    return c;
}
Mat operator ^ (Mat a, int k) 
{
    Mat ans; for(int i = 0; i < sz; i++) for(int j = 0; j < sz; j++) 
        ans.mat[i][j] = (i == j);
    while(k) {
        if(k & 1) {
            ans = ans * a;
        }
        a = a * a;
        k >>= 1;
    }
    return ans;
}
int solve( vector <int> num, int n)
{
    memset(a, 0, sizeof(a));
    vector<int> lucky = num;
    sort(lucky.begin(), lucky.end());
    lucky.erase(unique(lucky.begin(), lucky.end()), lucky.end());
    int m = (int) lucky.size();
    sz = m;
    Mat A, B;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            B.mat[i][j] = connect(lucky[i], lucky[j]);
        }
    }
    A.init();
    for(int i = 0; i < (int)lucky.size(); i++) {
        A.mat[0][i] = 1;
    }
    B = B ^ (n - 1);
    A = A * B;
    int ret = 0;
    for(int i = 0; i < sz; i++) {
        ret += A.mat[0][i];
        if(ret >= MOD) ret -= MOD;
    }
    return ret;
} 
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, n, m;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        vector<int> num(n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &num[i]);
        }
        printf("%d\n", solve(num, m));

        //bruteforce
        /*
        int dp[55][55];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++) {
            dp[1][i] = 1;
        }
        for(int i = 2; i <= m; i++) {
            for(int j = 0; j < n; j++) if(dp[i-1][j]) {
                for(int k = 0; k < n; k++) if(connect(num[j], num[k])) {
                    dp[i][k] += dp[i - 1][j];
                    dp[i][k] %= MOD;
                }
            }
        }
        int ret = 0;
        for(int i = 0; i <n; i++) ret += dp[m][i], ret %= MOD;
//        int ret = accumulate(dp[m], dp[m] + n, 0);
        printf("%d\n", ret);
        */
    }
    return 0;
}
