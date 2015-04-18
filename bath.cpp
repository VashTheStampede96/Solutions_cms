#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=10005;
int P, N, val, last, monete[MAXN];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d", &P);
	for(int i=0; i<P; i++){
		scanf("%d", &N);
		for(int j=0; j<N; j++) scanf("%d", monete+j);
		sort(monete,monete+N);
		
		if(monete[0]!=1) printf("1\n");
		else{
			last=1;
			for(int n=1; n<N; n++){
				val=monete[n];
				if(val>last+1) break;
				last+=val;
			}
			printf("%d\n",last+1);
		}
	}
	
	return 0;
}
