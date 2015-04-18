#include<cstdio>

const int INF=1005*1005;

int k, N, M, mem[2][1005][1005], events[2][1005], sol[1005];

int solve(int,int,int);
int min(int,int);
int abs(int);

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	events[0][0]=events[1][0]=1;
	
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) scanf("%d %d", &events[0][i], &events[1][i]);
	
	/*printf("%d\n", */solve(0,1,1)/*)*/;
	for(int i=1; i<=N; i++) printf("%c\n", (sol[i]==0)? 'R':'C');
	
	return 0;
}

inline int abs(int x)
{
	return (x<0)? -x : x;
}

inline int min(int a, int b)
{
	return (a<b)? a : b;
}

int solve(int mode, int n, int other)
{
	if(n==N+1) return 0;
	if(mem[mode][n][other]) return mem[mode][n][other];
	
	int MIN=INF, a, b;
	if(mode==0){
		a=abs(events[0][n]-events[0][n-1])+solve(0,n+1,other);
		b=abs(events[1][n]-other)+solve(1,n+1,events[0][n-1]);
	}
	else{
		a=abs(events[0][n]-other)+solve(0,n+1,events[1][n-1]);
		b=abs(events[1][n]-events[1][n-1])+solve(1,n+1,other);
	}
	if(a<b) sol[n]=0;
	else sol[n]=1;
	MIN=min(a,b);
	
	return mem[mode][n][other]=MIN;
}

