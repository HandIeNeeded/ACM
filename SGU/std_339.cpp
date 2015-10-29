#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<int, int> > segments;

int main() {
    char operation[2];
    int l, r;
    while (scanf("%s%d%d", operation, &l, &r) == 3) {
        if (*operation == '+') {
            int total = 0;
            for (int i = 0; i < int(segments.size()); i++) {
				pair<int, int> iter = segments[i];
                total += (l <= iter.first && iter.second <= r);
            }
            segments.push_back(make_pair(l, r));
            printf("%d\n", total);
        } else {
			vector<pair<int, int> > :: iterator it = find(segments.begin(), segments.end(), make_pair(l, r));
			if (it != segments.end()) {
				segments.erase(it);
			}
        }
    }
    return 0;
}
