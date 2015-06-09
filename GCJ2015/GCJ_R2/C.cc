#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <cmath>
#include <sstream>
#include <map>
#define hash myhash
using namespace std;
const int N = 2001005;
const int inf = 1000000007;
struct Edge {
	int v , w , next;
}e[N << 1];
char str[N];
map<string, int> mymap;
vector <int> v[N];
int n, m , tot , head[N];
int source , sink , level[N] , cur[N];
void _add (int u , int v , int w) {
	e[tot].v = v;e[tot].w = w;e[tot].next = head[u];head[u] = tot ++;
}
void add (int u , int v , int w) {
	_add (u , v , w);
	_add (v , u , 0);
}
int hash (string &s) {
	if (mymap.find(s) == mymap.end()) mymap[s] = m ++;
	return mymap[s];
}
void get (vector <int> &A) {
	A.clear ();
	gets (str); 
	istringstream in (str);
	string t; 
	while (in>> t) {
		A.push_back (hash (t));
	}
	sort (A.begin () , A.end ());
	A.resize (unique (A.begin () , A.end ()) - A.begin ()); 
}
bool bfs(){
	queue<int> q;
	memset(level,-1,sizeof(level));
	level[source] = 0;
	q.push(source);
	while(! q.empty()){
		int u = q.front();q.pop();
		for(int i = head[u];i != -1;i = e[i].next){
			int v = e[i].v;
			if(e[i].w && level[v] == -1){
				level[v] = level[u] + 1;
				q.push(v);
			}
		}
	}
	return level[sink] != -1;
}
int dfs(int u,int flow){
	if(u == sink) return flow;
	int tmp = flow;
	for(int &i = cur[u];i != -1;i = e[i].next){
		int v = e[i].v;
		if(e[i].w && level[v] == level[u] + 1){
			int add = dfs(v,min(e[i].w,tmp));
			tmp -= add;
			e[i].w -= add;
			e[i ^ 1].w += add;
			if(! tmp) break;
		}
	}
	return flow - tmp;
}
int dinic(){
	int maxFlow = 0;
	while(bfs()){
		for(int i = 0;i < N ;i ++)
			cur[i] = head[i];
		maxFlow += dfs(source,int(1e9));
	}
	return maxFlow;
}

int main(){
	freopen ("C.in" , "r" , stdin);
	freopen ("C.out" , "w" , stdout);
	int cas = 0 , t;
	scanf ("%d" , &t);
	while (t --) {
		memset (head , -1 , sizeof (head));tot = 0;
		mymap.clear ();
		m = 2;scanf ("%d" , &n);getchar ();
		for (int i = 0 ; i < n ; i ++)
			get (v[i]);
		source = 0;sink = 1;
		add (source , m , inf);
		add (m + 1 , sink , inf);
		for (int i = 0 ; i < n ; i ++) {
			for (int j = 0 ; j < (int)v[i].size () ; j ++) {
				add (m + i , v[i][j] , 1);
				add (v[i][j] , m + i , 1);
			}
		}
		printf ("Case #%d: %d\n" , ++ cas , dinic ());
	}
	return 0;
}
