#include<cstdio>
#include<queue>
#define ll long long
#define N 500010
using namespace std;

int n;
priority_queue<ll,vector<ll>,greater<ll> > heap;

int main(){
	freopen("huffman.in","r",stdin);
	freopen("huffman.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		ll x;
		scanf("%I64d",&x);
		heap.push(x);
	}
	ll ans=0;
	while(heap.size()>1){
		ll x=heap.top();
		heap.pop();
		ll y=heap.top();
		heap.pop();
		heap.push(x+y);
		ans+=x+y;
	}
	printf("%I64d\n",ans);
	return 0;
}
