#include <vector>
#include <cstdio>
using namespace std;

void solve(int, int);

vector< pair<int,int> > graph[100005];
bool occupated[2000005];
int N, M, A, B, a, b;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d %d %d %d", &N,&M,&A,&B);
	for(int i=0; i<M; i++){
		scanf("%d %d", &a, &b);
		graph[a].push_back( make_pair(b,i) );
		graph[b].push_back( make_pair(a,M+i) );
	}
	
	solve(B,-1);
	
	return 0;
}

void solve(int node, int from)
{
	int next=-1, k;
	
	for(int i=0; i<graph[node].size(); i++){
		if(!occupated[ graph[node][i].second ]){
			k = graph[node][i].second;
			occupated[k] = true;
			if(k<M) occupated[M+k] = true;
			else occupated[k-M] = true;
			next = graph[node][i].first;
			solve(next,node);
		}
	}
	
	if(from!=-1) printf("%d %d\n", node, from);
	return;	
}
