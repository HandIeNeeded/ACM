#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int T = 10000;

int main() {
#ifdef HOME
    freopen("B.in", "w", stdout);
#endif

    freopen("B.in", "w", stdout);
    srand(time(0) % clock());
    int t = 5;
    cout << t << endl;
    REP(i, t) {

        int m = 6;
        printf("%d ", m);
        for (int i = 1; i <= 10; ++i)
        {
            int k = rand() % 8;
            char x;
            switch (k)
            {
                case 0: x = 'L'; break;
                case 1: x = 'R'; break;
                case 2: x = 'S'; break;
                case 3: x = 'D'; break;
                case 4: x = 'B'; break;
                case 5: x = 'C'; break;
                case 6: x = 'V'; break;
                case 7: x = rand() % 26 + 'a'; break;
            }
            printf("%c", x);

        }
        printf("\n");
    }


    return 0;
}

