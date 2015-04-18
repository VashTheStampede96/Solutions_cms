#include <cstdio>
#include <algorithm>
#include <vector>
#include <assert.h>
using namespace std;
const int MAXM=10005;

vector<int> spon[MAXM];

int N, M, Q, m;

int solve(int N, int M, int* Q, int** sponsors, int* A, int* B)
{
	for(int i=0; i<N; i++)
		for(int j=0; j<Q[i]; j++){
			assert(sponsors[i][j]>0);
			spon[ sponsors[i][j] ].push_back(i+1);
		}
	
	for(int i=1; i<=M; i++)
			sort(spon[m].begin(),spon[m].end());
	
	for(int i=1; i<=M; i++){
		int dim1=spon[i].size();
		
		for(int j=i+1; j<=M; j++){
			int dim2=spon[j].size();
			int a, b, c=0;
			
			if(dim1<dim2){
				a=i;
				b=j;
			}
			else{
				a=j;
				b=i;
			}
			
			for(int k=0; k<spon[a].size(); k++)
					if(binary_search(spon[b].begin(),spon[b].end(),spon[a][k])) c++;
			if(c!=spon[a].size() && c!=0){
				A[0]=a; B[0]=b;
				return 0;
			}
		}
	}
	
	return 1;
}
/*
int s[50][50], q[50], a[10], b[10];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%d", q+i);
		for(int j=0; j<q[i]; j++) scanf("%d", &(s[i][j]));
	}
	
	printf("%d ", solve(N,M,q,s,a,b));
	printf("%d %d\n", a[0], b[0]);
	
	return 0;
}*/
