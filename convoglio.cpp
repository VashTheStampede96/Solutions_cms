#include <cstdio>
#include <vector>
using namespace std;

vector<int> adj[200005],
			ciclo;
int padri[200005], sol[100005],
	N, M, x, y;
bool occ[200005];

bool visita(int,int);

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d %d", &N, &M);
	
	for(int i=0; i<N; i++){
		scanf("%d %d", &x, &y);
		adj[x].push_back(y+N);
	}
	for(int i=0; i<M-N; i++){
		scanf("%d %d", &x, &y);
		adj[y+N].push_back(x);
	}
	
	for(int i=0; i<N; i++){
		if(padri[i]>0) continue;
		if(visita(i,i)){
			for(int i=1; i<ciclo.size(); i+=2){
				x=ciclo[i-1]; y=ciclo[i];
				sol[x]=y;
			}
			for(int i=0; i<N; i++)
					if(!sol[i]) sol[i]=adj[i][0];
			for(int i=0; i<N; i++)
					printf("%d %d\n", i, sol[i]-N);
			return 0;
		}
	}
	printf("-1\n");
	
	return 0;
}

bool visita(int nodo, int padre)
{
	int n=adj[nodo].size();
	
	occ[nodo] = true;
	padri[nodo]=padre+1;
	
	for(int i=0; i<n; i++){
		int f=adj[nodo][i];
		if(occ[f]){
			padri[f]=nodo+1;
			ciclo.push_back(f);
			do{
				ciclo.push_back(padri[f]-1);
				f=padri[f]-1;
			}while(padri[f]-1!=adj[nodo][i]);
			
			return true;
		}
		if(padri[f]>0) continue;
		if(visita(f,nodo)) return true;
	}
	
	return occ[nodo] = false;
}
