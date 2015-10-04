#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e4 + 5;
double a[N];

bool cmp(int i, int j) {
    return abs(a[i]) < abs(a[j]);
}

int main() {
#ifdef HOME
    freopen("E.in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    vector<int> A, B, C;
    REPP(i, 1, n) {
        scanf("%lf", a + i);
        if (fabs(a[i]) < 1e-7) B.push_back(i);
        else if (a[i] > 0) A.push_back(i);
        else C.push_back(i);
    }
    sort(A.begin(), A.end(), cmp);
    sort(C.begin(), C.end(), cmp);
    if (A.size() == 0u && B.size() == 0u) {
        vector<int> ans;
        while (C.size() > 1) {
            int x = C[C.size() - 1], y = C[C.size() - 2];
            double tmp = a[x] * a[y];
            if (tmp > 1) {
                ans.push_back(x);
                ans.push_back(y);
                REP(i, 2) C.pop_back();
            }
            else break;
        }
        if (ans.size() == 0u) {
            int x = -1, y = -1;
            double tmp = -100;
            if (C.size() > 1) {
                x = C.back(), y = C[C.size() - 2];
                tmp = a[x] * a[y];
            }
            if (tmp < a[C[0]]) {
                ans.push_back(C[0]);
            }
            else {
                ans.push_back(x);
                ans.push_back(y);
            }
        }
        sort(ans.begin(), ans.end());
        printf("%d ", int(ans.size()));
        double tmp = 1;
        REP(i, ans.size())  {
            tmp *= a[ans[i]];
        }
        printf("%.3lf\n", tmp);
        //printf("%d%c", ans[i], " \n"[i == int(ans.size()) - 1]);
    }
    else if (A.size() == 0u && C.size() == 0u) {
        puts("1");
        printf("%d\n", B[0]);
    }
    else {
        vector<int> ans;
        while (A.size()) {
            if (a[A.back()] > 1) {
                ans.push_back(A.back());
                A.pop_back();
            }
            else break;
        }
        while (C.size() > 1) {
            int x = C[C.size() - 1], y = C[C.size() - 2];
            double tmp = a[x] * a[y];
            if (tmp > 1) {
                ans.push_back(x);
                ans.push_back(y);
                REP(i, 2) C.pop_back();
            }
            else break;
        }
        if (ans.size() == 0u) {
            double tmp = -100, tmp2 = -100;
            int x = -1, y = -1;
            if (C.size() > 1u) {
                x = C[C.size() - 1], y = C[C.size() - 2];
                tmp = a[x] * a[y];
            }
            if (A.size()) {
                tmp2 = a[A.back()];
            }
            if (tmp < -50) {
                if (tmp2 > 0) {
                    ans.push_back(A.back());
                }
            }
            else if (tmp2 < -50) {
                ans.push_back(x);
                ans.push_back(y);
            }
            else if (tmp > tmp2) {
                ans.push_back(x);
                ans.push_back(y);
            }
            else {
                ans.push_back(A.back());
            }
        }
        if (ans.size() == 0u) {
            if (B.size()) {
                ans.push_back(B[0]);
            }
        }
        sort(ans.begin(), ans.end());
        printf("%d ", int(ans.size()));

        double tmp = 1;
        REP(i, ans.size()) {
            //printf("%d%c", ans[i], " \n"[i == int(ans.size()) - 1]);
            tmp *= a[ans[i]];
        }
        printf("%.3f\n", tmp);
    }


    return 0;
}


