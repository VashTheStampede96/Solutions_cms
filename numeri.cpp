#include <cstdio>
const int MAXN=1000005;

int v[MAXN], index1, index2, hSum, Sum, M, N, S;

void equal(int i)
{
	hSum=Sum;
	index2=index1;
	while(hSum==M && index2<=i){
		S++;
		hSum-=v[index2++];
	}
	
	return;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d %d", &M, &N);
	
	for(int i=0; i<N; i++){
		scanf("%d", v+i);
		Sum+=v[i];
		if(Sum==M) equal(i);
		else if(Sum>M){
			while(Sum>M && index1<=i) Sum-=v[index1++];
			if(Sum==M) equal(i);
		}
	}
	
	printf("%d\n", S);
	
	return 0;
}
