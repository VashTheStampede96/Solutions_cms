#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

struct EDGE{
	int adj, pos, cong;
	EDGE(int a) : adj(a) { cong=0; }
};

int N, res=1001000000, MAX=-1, fans[1000001];
vector<EDGE> adj[1000001];

int DFS(int node, int prec)
{
	if(adj[node].size()==1 && prec!=-1) return fans[node];
	int x=fans[node], L=adj[node].size();
	for(int i=0; i<L; i++){
		if(adj[node][i].adj!=prec){
		   if(adj[adj[node][i].adj][adj[node][i].pos].cong == 0)
		      adj[adj[node][i].adj][adj[node][i].pos].cong=DFS(adj[node][i].adj,node);
           x+=adj[adj[node][i].adj][adj[node][i].pos].cong;
        }
	}
	MAX=max(MAX,x-fans[node]);
	return x;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d",&N);
	for(int i=0; i<N; i++)
			scanf("%d",&fans[i]);
	int a, b;
	for(int i=0; i<N-1; i++){
		scanf("%d %d",&a,&b);
		EDGE x(a), y(b);
		adj[a].push_back(y);
		adj[b].push_back(x);
		adj[a].back().pos=adj[b].size()-1;
		adj[b].back().pos=adj[a].size()-1;
	}
	for(int i=0; i<N; i++){
		DFS(i,-1);
		res=min(res,MAX);
		MAX=-1;
	}
	
	printf("%d\n",res);
	
	return 0;
}
