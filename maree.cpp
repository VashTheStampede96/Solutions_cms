#include <vector>
#include <queue>
using namespace std;

const int INF = 30000000;

vector<int> adj[200000];
int dist1[200000], dist2[200000];
bool visited1[200000], visited2[200000];

void BFS(int start, int mode)
{
	queue< pair<int, int> > coda;
	coda.push( make_pair(start, 0) );
	
	while(!coda.empty()){
		pair<int, int> head = coda.front();
		coda.pop();
		
		if(mode == 1){
			if(!visited1[head.first]){
				visited1[head.first] = true;
				dist1[head.first] = head.second;
				for(int i=0; i<adj[head.first].size(); i++)
						coda.push( make_pair(adj[head.first][i], head.second+1) );
			}
		}
		else{
			if(!visited2[head.first]){
				visited2[head.first] = true;
				dist2[head.first] = head.second;
				for(int i=0; i<adj[head.first].size(); i++)
						coda.push( make_pair(adj[head.first][i], head.second+1) );
			}
		}
	}
	
	return;
}

int solve(int N, int M, int T, int* S, int* E)
{
	for(int i=0; i<N; i++) dist1[i] = dist2[i] = INF;
	for(int i=0; i<M; i++) adj[ S[i] ].push_back( E[i] );
	
	BFS(0,1);
	if(dist1[N-1] <= T) return dist1[N-1];
	BFS(N-1,2);
	int MIN = INF;
	for(int i=0; i<N; i++){
		if(dist1[i] <= T && dist2[i] != INF)
					MIN = (MIN<dist2[i])? MIN : dist2[i];
	}
	if(MIN != INF) return MIN+T;
	return -1;
}
