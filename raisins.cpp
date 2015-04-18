#include <cstdio>

int M, N,
	tav[55][55],
	sub[55][55],
	mem[55][55][55][55];
	
int solve(int,int,int,int);
int min(int,int);

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d %d",&N,&M);
	for(int i=1; i<=N; i++)
			for(int j=1; j<=M; j++)
					scanf("%d",&tav[i][j]);
	sub[1][1]=tav[1][1];
	for(int i=2; i<=M; i++) sub[1][i]=tav[1][i]+sub[1][i-1];
	for(int i=2; i<=N; i++){
		sub[i][1]=tav[i][1]+sub[i-1][1];
		for(int j=2; j<=M; j++) sub[i][j]=tav[i][j]+sub[i-1][j]+sub[i][j-1]-sub[i-1][j-1];
	}
	printf("%d\n",solve(1,N,1,M));
	
	return 0;
}

int solve(int ri, int rf, int ci, int cf)
{
	if(mem[ri][rf][ci][cf] != 0) return mem[ri][rf][ci][cf];
	if(ri == rf && ci == cf) return 0;
	int MIN=1000000000, costo=sub[rf][cf]-sub[ri-1][cf]-sub[rf][ci-1]+sub[ri-1][ci-1];
	for(int i=ri; i<rf; i++) MIN=min(MIN,solve(ri,i,ci,cf)+solve(i+1,rf,ci,cf));
	for(int i=ci; i<cf; i++) MIN=min(MIN,solve(ri,rf,ci,i)+solve(ri,rf,i+1,cf));
	return mem[ri][rf][ci][cf]=MIN+costo;
}

int min(int a, int b)
{
	if(a<b) return a;
	return b;
}
