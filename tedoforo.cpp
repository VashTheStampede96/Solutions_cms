#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <list>

using namespace std;
const int maxn = 1005, oo = 1e9;

int n, m, dist[maxn];
vector< pair<int,int> > adj[maxn];

int solve( )
{
    priority_queue< pair<int,int> > pq;
    pq.push( {0,1} );
    pair<int,int> head;

    while( !pq.empty() ){
        head = pq.top();
        pq.pop();
        head.first *= -1;

        if( dist[ head.second ]>head.first ){
            dist[ head.second ]=head.first;
            for( auto x : adj[ head.second ] )
                pq.push( { -( head.first+x.second ), x.first } );
        }
    }

    int ans = 0;
    for( int x=1; x<=n; ++x )
        if( dist[x]<=10*x )
            ++ans;
    return ans;
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	for( int x=0; x<maxn; ++x )
        dist[x] = oo;

	in >> n >> m;
	for( int x=0, u, v, w; x<m; ++x ){
        in >> u >> v >> w;
        adj[u].push_back( { v,w } );
        adj[v].push_back( { u,w } );
	}

	out << solve( ) << "\n";

	return 0;
}
