#include <vector>
#include <cstdio>
using namespace std;

const int MAXN=100005;

vector<int> graph[MAXN],
			cycle;
bool occ[MAXN];
int N, M, C, a, b,
	pred[MAXN];

bool DFS(int,int);

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		scanf("%d %d %d", &a, &b, &C);
		if(C){
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
	}
	
	for(int i=1; i<=N; i++) if(DFS(i,-1)) break;
	
	printf("%d\n", cycle.size());
	for(int i=0; i<cycle.size(); i++) printf("%d ", cycle[i]);
	printf("\n");
	
	return 0;
}

bool DFS(int n, int p)
{
	occ[n]=true;
	pred[n]=p;
	
	for(int i=0; i<graph[n].size(); i++){
		if(graph[n][i]==p) continue;
		if(occ[ graph[n][i] ]){ //Ho trovato un ciclo?
			cycle.push_back(graph[n][i]);
			while(n!=cycle[0]){
				cycle.push_back(n);
				n=pred[n];
			}
			return true;
		}
		else //Altrimenti...
			if(DFS(graph[n][i],n)) return true;
	}
	
	return occ[n]=false;
}
