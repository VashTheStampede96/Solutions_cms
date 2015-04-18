#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN=100005;

vector<int> adj[MAXN];
int N, M, i, j, triadi;
bool occ[MAXN];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d %d", &M, &N);
	for(int n=0; n<M; n++){
		scanf("%d %d", &i, &j);
		adj[i].push_back(j);
		adj[j].push_back(i);
	}
	
	for(int i=1; i<=N; i++) sort(adj[i].begin(),adj[i].end());
	
	for(int i=1; i<=N; i++){
		for(int j=0; j<adj[i].size(); j++){
			if(!occ[ adj[i][j] ]){
				for(int k=j+1; k<adj[i].size(); k++){
					if(binary_search(adj[ adj[i][j] ].begin(),adj[ adj[i][j] ].end(),adj[i][k]) && !occ[ adj[i][k] ]){
						triadi++;
					}
				}
			}
		}
		occ[i]=true;
	}
	
	printf("%d\n", triadi);
	
	return 0;
}
