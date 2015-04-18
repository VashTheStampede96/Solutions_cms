#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN=1000005;
int N, T, K, pos, M[MAXN], amici[MAXN], amiciDove[2][MAXN], a[MAXN];
bool occ[MAXN];
vector<int> adj[MAXN];


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d %d %d", &N, &K, &T);
	for(int i=1; i<=N; i++) scanf("%d", M+i);
	for(int i=1; i<=K; i++) scanf("%d", amici+i);

	sort(amici+1,amici+K+1);

	int i, j;
	for(i=1, j=0; i<=N; i++){
		if(occ[i]) continue;

		int k=i; occ[k]=true;
		adj[j].push_back(k);

		if(binary_search(amici+1,amici+K+1,k)){
			amiciDove[0][k]=j;
			amiciDove[1][k]=0;
		}

		while(M[k]!=adj[j][0]){
			k=M[k];
			occ[k]=true;
			adj[j].push_back(k);

			if(binary_search(amici+1,amici+K+1,k)){
				 amiciDove[0][k]=j;
				 amiciDove[1][k]=adj[j].size()-1;
			}
		}

		j++;
	}

	for(int i=1; i<=K; i++){
		int x=amiciDove[0][ amici[i] ];
		int y=amiciDove[1][ amici[i] ]+T;
		int z=adj[ x ].size();
		a[i]=adj[ x ][ y%z ];
	}

	sort(a+1,a+K+1);
	pos=a[1];

	for(int i=2; i<=K; i++){
		if( a[i]-pos >1){
			pos=a[i];
			break;
		}
		else pos=a[i];
	}

	if(pos==a[K]) pos=a[1];

	printf("%d\n", pos);

	return 0;
}
