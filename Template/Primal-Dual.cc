#include <cstdio>
#include <cstring>
#include <deque>
#include <algorithm>
using namespace std;
const int V=440, E=V*2, maxint=0x3F3F3F3F;
struct etype {
    int t, c, u;
    etype *next, *pair;
    etype() {}
    etype(int T, int C, int U, etype* N): t(T), c(C), u(U), next(N) {}
    void* operator new(unsigned, void* p){return p;}
} *e[V], Te[E+E], *Pe;
int S, T, n, piS, cost;
bool v[V];
void addedge(int s, int t, int c, int u) {
    e[s] = new(Pe++) etype(t, +c, u, e[s]);
    e[t] = new(Pe++) etype(s, -c, 0, e[t]);
    e[s]->pair = e[t];
    e[t]->pair = e[s];
}
int aug(int no, int m) {
    if (no == T) return cost += piS * m, m;
    v[no] = true;
    int l = m;
    for (etype *i = e[no]; i; i = i->next)
        if (i->u && !i->c && !v[i->t]) {
            int d = aug(i->t, l < i->u ? l : i->u);
            i->u -= d, i->pair->u += d, l -= d;
            if (!l) return m;
        }
    return m - l;
}
bool modlabel() {
    static int d[V]; memset(d, 0x3F, sizeof(d)); d[T] = 0;
    static deque<int> Q; Q.push_back(T);
    while(Q.size()) {
        int dt, no = Q.front(); Q.pop_front();
        for(etype *i = e[no]; i; i = i->next)
            if(i->pair->u && (dt = d[no] - i->c) < d[i->t])
                (d[i->t] = dt) <= d[Q.size() ? Q.front() : 0]
                    ? Q.push_front(i->t) : Q.push_back(i->t);
    }
    for(int i = 0; i < n; ++i)
        for(etype *j = e[i]; j; j = j->next)
            j->c += d[j->t] - d[i];
    piS += d[S];
    return d[S] < maxint;
}
int ab[V], *pab[V], w[V];
struct lt {
    bool operator()(int* p1,int* p2) {return *p1 < *p2;}
};
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        memset(e,0,sizeof(e));
        Pe = Te;
        static int m, k;
        scanf("%d %d", &m, &k);
        int abz = 0;
        for(int i = 0; i < m; ++i) {
            scanf("%d", pab[abz] = &ab[abz]), abz++;
            scanf("%d", pab[abz] = &ab[abz]), abz++;
            scanf("%d", &w[i]);
        }
        sort(&pab[0], &pab[abz], lt());
        int c=0xDEADBEEF; n=0;
        for(int i = 0; i < abz; ++i) {
            if(c != *pab[i]) c = *pab[i], ++n;
            *pab[i] = n;
        }
        ++n, S = 0, T = n++;
        for(int i = 0; i < T; ++i) addedge(i, i+1, 0, k);
        for(int i = 0; i < m; ++i) addedge(ab[i+i], ab[i+i+1], -w[i], 1);
        piS = cost = 0;
        while(modlabel())
            do memset(v, 0, sizeof(v));
            while(aug(S, maxint));
        printf("%d\n", -cost);
    }
    return 0;
}


#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

const int MAXV=100*100*20;
const int MAXE=100*100*100;
const int INF=0x3f3f3f3f;

struct edge{
	int t,v,u;edge *nxt,*op;
	void init(const int s,const int t,const int u,const int v,edge *op);
}E[MAXE],*V[MAXV],*PE;

void edge::init(const int s,const int t,const int u,const int v,edge *op){
	this->t=t;
	this->u=u;
	this->v=v;
	this->op=op;
	this->nxt=V[s];
	V[s]=this;
}

void addedge(int x,int y,int u,int v){
	PE->init(x,y,u,v,PE+1);
//	if(u!=INF) cout<<"!!!"<<x<<" "<<y<<" "<<u<<" "<<v<<endl;
	++PE;
	PE->init(y,x,0,-v,PE-1);
//	if(u!=INF) cout<<"!!!"<<y<<" "<<x<<" "<<0<<" "<<-v<<endl;
	++PE;
}

int S,T;
int dist[MAXV];
bool in[MAXV];
int Q[MAXV],QH,QT;

bool modlabel(){
	for(int i=0;i<=T;++i) dist[i]=INF,in[i]=false;
	dist[T]=0;
	QH=QT=-1;
	Q[++QT]=T;
	in[T]=true;
	while(QH++!=QT){
		if(QH==MAXV) QH=0;
		int x=Q[QH];
		for(edge *ii=V[x];ii;ii=ii->nxt) if(ii->op->u){
			if(dist[ii->t]>dist[x]+ii->op->v){
				dist[ii->t]=dist[x]+ii->op->v;
				if(!in[ii->t]){
					in[ii->t]=1;
					if(++QT==MAXV) QT=0;
					Q[QT]=ii->t;
				}
			}
		}
		in[x]=false;
	}
	return dist[S]!=INF;
}

int mincost;
int maxflow;

int aug(int x,int limit){
	if(x==T){
		maxflow+=limit;
		mincost+=limit*dist[S];
		return limit;
	}
	int ll=limit,kk;
	in[x]=1;
	for(edge *ii=V[x];ii;ii=ii->nxt) if(ii->u&&!in[ii->t]&&ii->v+dist[ii->t]==dist[x]){
		kk=aug(ii->t,min(ll,ii->u));
		ii->u-=kk,ii->op->u+=kk;
		ll-=kk;
		if(!ll){
			return in[x]=0,limit;
		}
	}
	return limit-ll;
}
int N,K,M;

int f[101][101];

int q[1001];

const int Num=322;
const int All=101;

inline int getId(int x,int y){
	return x*Num+y;
}

vector<int> Sel[111];
int ans[101][101];

void getMethod(){
	int ret=0;
	for(edge *ii=V[0];ii;ii=ii->nxt){
		if(K-ii->u&&ii->t!=S){
			for(int j=0;j<K-ii->u;++j) Sel[ii->t%Num].push_back(++ret);
		}
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=f[i][0];++j){
			int nsel=-1;
			{
				int x=getId(i,j);
				for(edge *ii=V[x];ii;ii=ii->nxt) if(ii->t!=T){
					if(ii->u){
						nsel=Sel[ii->t%Num].back();
						Sel[ii->t%Num].pop_back();
					}
				}
				ans[i][j]=nsel;
			}
		}
		for(int j=1;j<=f[i][0];++j){
			{
				int x=getId(i,j+All);
				for(edge *ii=V[x];ii;ii=ii->nxt) if(ii->t!=S){
					if(!ii->u){
						Sel[ii->t%Num].push_back(ans[i][j]);
					}
				}
			}
		}
	}
}

int main(){
	PE=E;
	scanf("%d%d%d",&N,&K,&M);
	//tot = N * (max(M, K) + K + 1) + S + S' + K + T' + T
	int _maxflow=K;
	S=(N+1)*Num+1;
	T=S+2;
	addedge(S,0,K,0);// S'=0 S -> S'
	for(int i=1;i<=M;++i){
		addedge(0,getId(0,All*2+i),K,0);
	}
	for(int i=1;i<=M;++i){
		scanf("%d",q+i);
	}
	for(int i=1;i<=N;++i){
		scanf("%d",f[i]);
		for(int j=1;j<=f[i][0];++j){
			scanf("%d",f[i]+j);
			addedge(getId(i-1,All+All*2),getId(i,j),1,q[f[i][j]]); // arb - > now
			addedge(getId(i-1,f[i][j]+All*2),getId(i,j),1,0);// same -> now
			addedge(getId(i,j),T,1,0); // now - > T
			addedge(S,getId(i,j+All),1,0);// S -> now'
			addedge(getId(i,j+All),getId(i,f[i][j]+All*2),1,0); // now' - > same
			addedge(getId(i,j+All),getId(i,All+All*2),1,0);// now' - >arb
		}
		for(int j=1;j<=All;++j){
			addedge(getId(i-1,j+All*2),getId(i,j+All*2),INF,0);// same -> same
		}
		_maxflow+=f[i][0];
	}
	for(int j=1;j<=All;++j){
		addedge(getId(N,j+All*2),T-1,INF,0);
	}
	addedge(T-1,T,K,0);
	while(modlabel()){
		do{
			memset(in,0,sizeof(in));
		}while(aug(S,INF));
	}
	printf("%d\n",mincost);
	getMethod();
	for(int i=1;i<=N;++i){
		for(int j=1;j<=f[i][0];++j){
			if(j!=1) printf(" ");
			printf("%d",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
