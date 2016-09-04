#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 110
#define M 50
using namespace std;

int n[N],m,mod,phi,bin[M],tot;
char ch[N];

struct Matrix{
	int a[M][M];
	int n,m;
	inline int* operator [] (int x){
		return a[x];
	}
	Matrix(int _n,int _m){
		n=_n;m=_m;
		memset(a,0,sizeof(a));
	}
	void setUnit(){
		for(int i=0;i<n;i++){
			a[i][i]=1;
		}
	}
	Matrix operator * (Matrix B){
		Matrix C(n,B.m);
		for(int i=0;i<C.n;i++){
			for(int j=0;j<C.m;j++){
				for(int k=0;k<m;k++){
					C[i][j]=(C[i][j]+(a[i][k]*B[k][j])%mod)%mod;
				}
			}
		}
		return C;
	}
};

bool judge(int x0,int x1){
	for(int i=0;i<m-1;i++){
		if(((bin[i]&x0)==(bin[i]&x1))&&
		((bin[i]&x0)==((bin[i+1]&x0)>>1))&&
		((bin[i]&x0)==((bin[i+1]&x1)>>1))){
			return false;
		}
	}
	return true;
}

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

void div(){
	for(int i=tot;i>=1;i--){
		if(n[i]&1){
			n[i-1]+=10;
			n[i]>>=1;
		}else{
			n[i]>>=1;
		}
	}
	if(n[tot]==0) tot--;
}

Matrix ksm(Matrix A){
	Matrix RET(A.n,A.m);
	RET.setUnit();
	while(tot){
		if(n[1]&1) RET=RET*A;
		A=A*A;
		div();
	}
	return RET;
}

int main(){
//	freopen("nice.in","r",stdin);
//	freopen("nice.out","w",stdout);
	bin[0]=1;
	for(int i=1;i<=10;i++) bin[i]=bin[i-1]<<1;
	scanf("%s",ch);
	scanf("%d%d",&m,&mod);
	tot=strlen(ch);
	for(int i=1;i<=tot;i++){
		n[i]=ch[i-1]-'0';
	}
	reverse(n+1,n+1+tot);
	n[1]--;
	for(int i=2;i<=tot;i++){
		if(n[i-1]<0){
			n[i-1]+=10;
			n[i]--;
		}
	}
	if(n[tot]==0) tot--;
	Matrix ans(1,1<<m);
	for(int i=0;i<ans.m;i++) ans[0][i]=1;
	Matrix trans(1<<m,1<<m);
	for(int i=0;i<trans.n;i++){
		for(int j=0;j<trans.m;j++){
			if(judge(i,j)){
				trans[i][j]=1;
			}
		}
	}
	trans=ksm(trans);
	ans=ans*trans;
	int ret=0;
	for(int i=0;i<ans.m;i++) ret=(ret+ans[0][i])%mod;
	printf("%d\n",ret);
	return 0;
}
