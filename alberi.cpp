#include <cstdio>

void solve(int,int,int,int);
int k=0, n;
int *pre, *post, *simm;
void visita(int,int*,int*,int*);
/*
int main()
{
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	
	int pre[10005], post[10005], simm[10005];
	
	fscanf(in,"%d", &n);
	for(int i=0; i<n; i++) fscanf(in,"%d", &pre[i]);
	for(int i=0; i<n; i++) fscanf(in,"%d", &post[i]);
	
	visita(n, pre, post, simm);
	
	for(int i=0; i<n; i++) fprintf(out,"%d ", simm[i]);
	
	return 0;
}
*/
void visita(int N, int* PRE, int* POST, int* SIMM)
{
	n=N;
	pre=PRE; post=POST; simm=SIMM;
	solve(0,N-1,0,N-1);
	
	return;
}

void solve(int l1, int r1, int l2, int r2)
{
	if(l1>r1) return;
	if(l1==r1){
		simm[k++]=pre[l1];
		return;
	}
	
	int x1=l1+1, y1=l1, x2=l2, y2=r2;
	
	while(y1<r1 && pre[y1+1]!=post[r2-1]) y1++;
	while(y2>0 && post[y2]!=pre[x1]) y2--;
	
	solve(x1,y1,x2,y2);
	simm[k++]=pre[l1];
	
	x1=y1+1; y1=r1; y2=r2-1; x2=y2;
	while(post[x2-1]!=pre[l1+1]) x2--;
	
	solve(x1,y1,x2,y2);
	
	return;
}
