#include<cstdio>
#include<stack>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3fll
#define N 70
using namespace std;

ll f[N][N];
int n,k,from[N][N];
stack<int> s[N];

void move(int u,int v){
	printf("move %d from %d to %d",s[u].top(),u,v);
	if(s[v].size()){
		printf(" atop %d\n",s[v].top());
	}else{
		printf("\n");
	}
	s[v].push(s[u].top());
	s[u].pop();
}

//表示从柱子u挪到柱子v,u中有n个盘子,可以用的柱子共有m个. 
void dfs(int u,int v,int n,int m){
	if(n==1){
		move(u,v);
		return;
	}
	if(s[u].size()<from[n][m]) return;
	stack<int> tmp;
	int x;
	for(int i=1;i<=from[n][m];i++){
		tmp.push(s[u].top());
		s[u].pop();
	}
	x=tmp.top();
	for(int i=1;i<=from[n][m];i++){
		s[u].push(tmp.top());
		tmp.pop();
	}
	for(int i=1;i<=k;i++){
		if(i==u||i==v) continue;
		if((s[i].empty())||(s[i].top()>x)){
			dfs(u,i,from[n][m],m);
			dfs(u,v,n-from[n][m],m-1);
			dfs(i,v,from[n][m],m);
			break;
		}
	}
}

int main(){
	freopen("hanoi.in","r",stdin);
	freopen("hanoi.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=2;i<=k;i++) f[1][i]=1;
	f[1][1]=0;
	for(int i=2;i<=n;i++) f[i][1]=f[i][2]=inf;
	for(int i=2;i<=n;i++){
		for(int j=3;j<=k;j++){
			f[i][j]=2*f[1][j]+f[i-1][j-1];
			from[i][j]=1;
			for(int d=2;d<=i-1;d++){
				if((2*f[d][j]+f[i-d][j-1])<(2*f[from[i][j]][j]+f[i-from[i][j]][j-1])){
					from[i][j]=d;
					f[i][j]=2*f[d][j]+f[i-d][j-1];
				}
			}
		}
	}
	printf("%I64d\n",f[n][k]);
	for(int i=n;i>=1;i--) s[1].push(i);
	dfs(1,k,n,k);
	return 0;
}
