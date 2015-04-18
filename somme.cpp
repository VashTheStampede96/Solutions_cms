#include <cstdio>
#include <list>
#include <limits>
using namespace std;
const int MAXN = 505,
	  	  INF = numeric_limits<int>::max();

int N, x, mem[MAXN][MAXN], sequence[MAXN],
	prefixSum[MAXN];

int abs(int);
int min(int,int);
int max(int,int);
int solve(int,int);
int max3(int,int,int);

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", sequence+i );
		prefixSum[i]=prefixSum[i-1]+sequence[i];
	}
	
	printf("%d\n", solve(1,N));
	
	return 0;
}

inline int abs(int x){ return (x<0)? -x : x; }
inline int min(int a, int b){ return (a<b)? a : b; }
inline int max(int a, int b){ return (a>b)? a : b; }
int max3(int a, int b, int c)
{
	a=max(a,b);
	a=max(a,c);
	return a;
}

int solve(int l, int r)
{
	if(l==r) return 0;
	if(r==l+1) return mem[l][r]=abs(sequence[l]+sequence[r]);
	if(mem[l][r]) return mem[l][r];
	
	int MIN=INF, Y=prefixSum[r]-prefixSum[l-1], left, right;
	for(int i=l+1; i<=r; i++){
		left=solve(l,i-1);
		right=solve(i,r);
		MIN=min(MIN, max3(abs(Y),left,right) );
	}
	
	return mem[l][r] = MIN;
}
