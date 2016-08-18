#include<cstdio>
#define ll long long
#define N 10010
using namespace std;

int n,m;
ll d[N],sum;

int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		d[x]++;d[y]++;
	}
	for(int i=1;i<=n;i++){
		sum+=d[i]*d[i];
	}
	printf("%lld\n",sum);
	return 0;
}
