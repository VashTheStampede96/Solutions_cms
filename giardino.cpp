#include <cstdio>
#include <algorithm>
#include <cstring>

int N, M, I, J, S=1000000000,
	stemma[20][2], giardino[500][500];
	
void solve(int i, int j)
{
	int s=0;
	for(int g=0; g<M; g++){
		if(stemma[g][0]+i<0 || stemma[g][0]+i>=N || stemma[g][1]+j<0 || stemma[g][1]+j>=N) return;
		s+=giardino[ stemma[g][0]+i ][ stemma[g][1]+j ];
		if(s>=S) return;
	}
	I=i; J=j; S=s;
	return;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d %d",&N,&M);
	for(int i=0; i<M; i++)
		scanf("%d %d",&stemma[i][0],&stemma[i][1]);
	for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
					scanf("%d",&giardino[i][j]);
	
	for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
					solve(i,j);
	printf("%d %d %d\n",I,J,S);
	
	return 0;
}
