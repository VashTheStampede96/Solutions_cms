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
#define pb(x) push_back(x)
#define FOR(i,n) for(;i<n;++i)
#define mod(x) (x<0)? -x:x
#define f first
#define s second
#define INF 1e9
#include <cassert>

using namespace std;

int n, m, k, dist[2][10005];
vector<int> adj[10005],
                   sup;

void bfs( int s, int d )
{
    for( int i=0; i<10005; ++i )
        dist[d][i] = INF;
    queue< pair<int,int> > coda;
    pair<int,int> head;
    coda.push( {s,0} );

    while( !coda.empty() )
    {
        head = coda.front();
        coda.pop();
        if( dist[d][head.first]>head.second ){
            dist[d][head.first] = head.second;
            for( auto i : adj[head.first] )
                coda.push( {i,head.second+1} );
        }
    }
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> n >> m >> k;
	sup.reserve(k);
	for( int i=0, q; i<k; ++i ){
        in >> q;
        sup.push_back(q);
	}
	for( int i=0, a, b; i<m; ++i ){
        in >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
	}

	bfs( 1,0 );
	bfs( n,1 );
	int MIN = m;
	for( auto i : sup )
        MIN = min( MIN, dist[0][i]+dist[1][i] );
    out << MIN << "\n";

	return 0;
}
