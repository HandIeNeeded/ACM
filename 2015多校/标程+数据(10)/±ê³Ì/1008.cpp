#include <bitset>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define sz(x) ((int)(x.size()))

typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 20005;
const int ME = 100005;
bitset<MX> b[MX];
vi adj[MX], radj[MX];
int q[MX], dg[MX];

int main() {
	int T, n, m;
	int i, j, k, u, v;
	// freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
	for (scanf("%d", &T); T--; ) {
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++) {
			adj[i].clear();
			radj[i].clear();
			dg[i] = 0;
			b[i].reset();
		}
		
		while (m--) {
			scanf("%d%d", &u, &v);
			adj[u].pb(v);
			dg[v]++;
		}
		
		int hd = 0, tl = 0;
		for (i = 1; i <= n; i++)
			if (!dg[i]) q[tl++] = i;
		
		while (hd < tl) {
			u = q[hd++];
			for (i = 0; i < sz(adj[u]); i++) {
				v = adj[u][i];
				radj[v].pb(u);
				
				dg[v]--;
				if (!dg[v]) q[tl++] = v;
			}
		}
		
		int rn = 0;
		for (i = 1; i <= n; i++) b[i][i] = 1;
		for (i = 1; i <= n; i++) {
			u = q[i - 1];
			
			for (int k = sz(radj[u]) - 1; k >= 0; k--) {
				v = radj[u][k];
				
				if (b[u][v] == 1) {
					rn++;
				} else {
					b[u] |= b[v];
				}
			}
		}
		
		printf("%d\n", rn);
	}
	return 0;
}
