#include <fstream>
#include <vector>
#include <list>
using namespace std;

int N, M, K, a, b, cities[10000], groups[10000];
bool vis[10000];
vector<int> lista;
list<int> adj[10000];

void DFS(int n)
{
	while(!adj[n].empty()){
		int k = adj[n].front();
		if(!vis[k]){
			lista.push_back(k);
			vis[k] = true;
			DFS(k);
		}
		adj[n].pop_front();
	}
	return;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    in >> N;
    in >> M;
    for(int i=0; i<M; i++){
    	in >> a;
    	in >> b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }
    for(int i=0; i<N; i++){
    	if(!vis[i]){
    		vis[i] = true;
    		lista.push_back(i);
    		DFS(i);
    		int k = lista.size();
    		while(!lista.empty()){
				  cities[lista.back()] = k;
    			  lista.pop_back();
		    }
    	}
    }
    for(int i=0; i<N; i++) groups[cities[i]]++;
    for(int i=1; i<=N; i++) K += groups[i]/i;
    out << K-1 << endl;
    
    return 0;
}
