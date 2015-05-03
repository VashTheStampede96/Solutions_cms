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
typedef long long ll;
typedef pair<int,int> ii;

const int intoo = 1e9;
const ll longoo = 1e18;
const int maxn = 1005;

struct EDGE{
    int x, y, w;
    EDGE( int a, int b, int c )
        :   x(a), y(b), w(c) {  }
};

int n, m, sol = intoo;
vector<ii> adj[maxn];
vector<EDGE> edges;

int dijkstra( const EDGE& edge )
{
    int s = edge.x, t = edge.y;
    vector<int> dist( n+1, intoo );
    priority_queue<ii> pq;
    pq.push( { 0,s } );

    while( !pq.empty() ){
        int x = pq.top().second,
             w = -pq.top().first;
        pq.pop();
        if( dist[x]==intoo ){
            dist[x] = w;
            for( auto z : adj[x] )
                if( !(x == s && z.first == t) && w+z.second<sol && dist[z.first]==intoo )
                    pq.push( { -(w+z.second), z.first } );
        }
    }

    return dist[t]+edge.w;
}

int main()
{
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
    ios_base::sync_with_stdio( false );
    cin >> n >> m;

    edges.reserve(m);
    for( int i=0, u, v, w; i<m; ++i ){
        cin >> u >> v >> w;
        adj[u].push_back( {v,w} );
        adj[v].push_back( {u,w} );
        edges.push_back( EDGE(u,v,w) );
    }

    random_shuffle( edges.begin(), edges.end() );

    for( auto x : edges )
        sol = min( sol, dijkstra(x) );

    cout << sol << "\n";

	return 0;
}
