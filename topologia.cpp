#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<int> adj[100005];
int N, M, n, Int, Mid, Ext,
	Linear, Circular, Star,
	x, y;
bool occ[100005];

void analyze(int);

void Analizza(int N, int M, int A[], int B[], int T[])
{
	for(int i=0; i<M; i++){
		adj[ A[i] ].push_back( B[i] );
		adj[ B[i] ].push_back( A[i] );
	}

	for(int i=1; i<=N; i++){
		if(!occ[i]){
			Int = Mid = Ext = n = 0;
			analyze(i);
			if(n != 1){
				if(Mid == n-2 && Ext == 2) T[0]++;
				if(Mid == n) T[1]++;
				if(Mid == 0 && Int == 1 && Ext == n-1) T[2]++;
			}
		}
	}

	return;
}

void analyze(int node)
{
	queue<int> coda;
	int numb, head;

	coda.push(node);
	while(!coda.empty()){
		head=coda.front();
		coda.pop();
		numb=adj[head].size();
		if(!occ[head]){
			occ[head] = true;
			n++;
			if(numb == 1) Ext++;
			else if(numb == 2) Mid++;
				 else Int++;
		    for(int k=0; k<numb; k++)
		    		coda.push(adj[head][k]);
		}
	}

	return;
}
