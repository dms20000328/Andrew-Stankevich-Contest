#include<cstdio>
#include<vector>
#include<algorithm>
#define N 500010
using namespace std;

struct edge{
	int to,next;
}e[N];

int ne,head[N],f[N][2],g[N],n;
vector<int> ans;

void insert(int u,int v){
	ne++;
	e[ne].to=v;
	e[ne].next=head[u];
	head[u]=ne;
}

void dfs(int x){
	f[x][0]=0;f[x][1]=1;g[x]=0;
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].to;
		dfs(v);
		if((f[v][1]-f[v][0])>(f[g[x]][1]-f[g[x]][0])) g[x]=v;
		f[x][0]+=f[v][0];
		f[x][1]+=f[v][0];
	}
	f[x][0]+=f[g[x]][1]-f[g[x]][0];
}

void print(int x,int type){
	if(type==1){
		ans.push_back(x);
	}
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].to;
		if(v==g[x]&&type==0) print(v,1);
		else print(v,0);
	}
}

int main(){
	freopen("grant.in","r",stdin);
	freopen("grant.out","w",stdout);
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		int x;
		scanf("%d",&x);
		insert(x,i);
	}
	dfs(1);
	printf("%d\n",f[1][0]*1000);
	print(1,0);
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
}
