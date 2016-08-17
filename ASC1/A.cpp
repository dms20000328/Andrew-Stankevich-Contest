#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 2010
using namespace std;

char s[N];

struct Bignum{
	short a[N];
	int len;
	Bignum(){
		len=1;
		memset(a,0,sizeof(a));
	}
	void read(){
		scanf("%s",s);
		len=strlen(s);
		for(int i=0;i<len;i++){
			a[i]=s[i]-'0';
		}
		reverse(a,a+len);
	}
	void print(){
		for(int i=len-1;i>=0;i--){
			printf("%d",(int)a[i]);
		}
	}
}n;

void div2(Bignum &a){
	for(int i=0;i<a.len;i++){
		if(a.a[i]&1){
			a.a[i]/=2;
			a.a[i-1]+=5;
		}else{
			a.a[i]/=2;
		}
	}
	if(a.a[a.len-1]==0) a.len--;
}

int main(){
	freopen("china.in","r",stdin);
	freopen("china.out","w",stdout);
	n.read();
	if(n.a[0]&1){
		n.a[0]--;
		div2(n);
		n.print();
	}else{
		int k=n.a[1]*10+n.a[0];
		n.a[0]-=k%4;
		if(n.a[0]<0){
			n.a[0]+=10;
			n.a[1]-=1;
		}
		if(n.a[n.len-1]==0) n.len--;
		div2(n);
		n.a[0]--;
		if(n.a[0]<0){
			n.a[0]+=10;
			n.a[1]-=1;
		}
		if(n.a[n.len-1]==0) n.len--;
		n.print();
	}
	return 0;
}
