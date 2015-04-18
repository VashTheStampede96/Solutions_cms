#include <cstdio>
#include <algorithm>
using namespace std;

int N, m[5000005], res=2000500000, i;
int x[5000005], y[5000005];

int main()
{
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");

    fscanf(in,"%d",&N);

    for(i=0; i<N; i++) fscanf(in,"%d", m+i);

	x[N]=m[N-1]; y[N]=x[N]+(m[N-1]-m[N-2]);
	for(int i=N-1; i>0; i--){
		x[i]=max(2*m[i]-y[i+1], m[i-1]);
		y[i]=min(2*m[i]-x[i+1], m[i]);
		if(y[i]-x[i]<0) break;
		else res=min(res,y[i]-x[i]+1);
	}
	x[0]=max(2*m[0]-y[1], 2*m[0]-m[1]);
	y[0]=min(2*m[0]-x[1], m[0]);
	res=min(res,y[0]-x[0]+1);

	if(res < 0) res=0;

    fprintf(out,"%d\n",res);

    return 0;
}
