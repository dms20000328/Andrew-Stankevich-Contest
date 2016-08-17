#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 210
#define M 100010
#define inf 0x7fffffff
using namespace std;

struct edge{
	int to,next,v;
}e[M<<1];

int ne=1,head[N],q[N],h[N],ans,sum,c[M],d[N],n,m,S,T;

void ins(int u,int v,int f){
	ne++;
	e[ne].to=v;
	e[ne].next=head[u];
	e[ne].v=f;
	head[u]=ne;
}

void insert(int u,int v,int f){
	ins(u,v,f);ins(v,u,0);
}

bool bfs(){
	int t=0,w=1;
	memset(h,-1,sizeof(h));
	q[0]=S;h[S]=0;
	while(t<w){
		int now=q[t++];
		for(int i=head[now];i;i=e[i].next){
			if(e[i].v&&h[e[i].to]==-1){
				h[e[i].to]=h[now]+1;
				q[w++]=e[i].to;
			}
		}
	}
	if(h[T]==-1) return 0;
	return 1;
}

int dfs(int x,int f){
	if(x==T) return f;
	int w,used=0;
	for(int i=head[x];i;i=e[i].next){
		if(e[i].v&&h[e[i].to]-h[x]==1){
			w=dfs(e[i].to,min(f-used,e[i].v));
			e[i].v-=w;
			e[i^1].v+=w;
			used+=w;
			if(used==f) return f;
		}
	}
	if(!used) h[x]=-1;
	return used;
}

void dinic(){
	while(bfs()) ans+=dfs(S,inf);
}

int main(){
	freopen("cooling.in","r",stdin);
	freopen("cooling.out","w",stdout);
	scanf("%d%d",&n,&m);
	S=0;T=n+1;
	for(int i=1;i<=m;i++){
		int u,v,l;
		scanf("%d%d%d%d",&u,&v,&l,&c[i]);
		insert(u,v,c[i]-l);
		d[u]-=l;d[v]+=l;
	}
	for(int i=1;i<=n;i++){
		if(d[i]>0) sum+=d[i];
		if(d[i]>0) insert(S,i,d[i]);
		if(d[i]<0) insert(i,T,-d[i]);
	}
	dinic();
	if(ans==sum){
		printf("YES\n");
	}else{
		printf("NO\n");
		return 0;
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",c[i]-e[i<<1].v);
	}
	return 0;
}
