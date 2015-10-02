#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    pair<int, int> A[3];
    int S = 0;
    REP(i, 3) {
        int x, y;
        cin >> x >> y;
        A[i] = {x, y};
        S += x * y;
    }
    int L = sqrt(1.0 * S + 0.5);
    if (L * L != S) {
        cout << "-1" << endl;
    }
    else {
        int id = -1, bad = 0, cnt = 0;
        REP(i, 3) {
            int z = max(A[i].first, A[i].second);
            if (z == L) {
                id = i;
                cnt++;
            }
        }
        if (cnt > 1) {
            if (cnt == 2) {
                cout << "-1" << endl;
                return 0;
            }
            else if (cnt == 3) {
                REP(i, 3) if (A[i].first > A[i].second) swap(A[i].first, A[i].second);
                int S = 0;
                REP(i, 3) S += A[i].first;
                if (S != L) {
                    cout << "-1" << endl;
                    return 0;
                }
                else {
                    cout << L << endl;
                    REPP(i, 1, L) {
                        REP(j, 3) {
                            REPP(k, 1, A[j].first) {
                                cout << char('A' + j);
                            }
                        }
                        cout << endl;
                    }
                    return 0;
                }
            }
            else {
                cout << "-1" << endl;
                return 0;
            }
        }
        if (id == -1) {
            bad = 1;
        }
        int W = 2 * L - (A[id].first + A[id].second);
        int H = 0;
        vector<int> h;
        REP(i, 3) {
            if (i != id) {
                if (A[i].first == W) {
                    H += A[i].second;
                    h.push_back(A[i].second);
                }
                else if (A[i].second == W) {
                    H += A[i].first;
                    h.push_back(A[i].first);
                }
                else {
                    bad = 1;
                }
            }
        }
        if (H != L) bad = 1;
        if (bad) {
            cout << "-1" << endl;
        }
        else {
            cout << L << endl;
            char c = 'A' + id;
            REPP(i, 1, L - W) {
                REPP(j, 1, L) {
                    cout << c;
                }
                cout << endl;
            }
            char b, a;
            if (id == 0) {
                a = 'B', b = 'C';
            }
            else if (id == 1) {
                a = 'A', b = 'C';
            }
            else {
                a = 'A', b = 'B';
            }
            REPP(i, L - W + 1, L) {
                REPP(j, 1, h[0]) {
                    cout << a;
                }
                REPP(j, 1, h[1]) {
                    cout << b;
                }
                cout << endl;
            }
        }
    }

    return 0;
}


