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
typedef long long llint;
typedef pair<int,int> ii;
typedef pair<llint,int> llint_ii;

const int maxn = 1e5+5;
const llint inf = llint( 2e9 ) * llint( 1e6 );

priority_queue<llint_ii> pq;
vector<ii> adj[maxn];
int n, k, *esc;
llint d[2][maxn];

void dijkstra(  )
{
    for( int i=0; i<k; ++i )
            pq.push( { d[0][ esc[i] ] = 0, esc[i] } );

    while( !pq.empty() )
    {
        llint_ii head = pq.top();
        pq.pop();

        head.first *= -1;

        if( d[1][ head.second ] <= head.first )
            continue;

        d[1][ head.second ] = head.first;

        if( d[1][ head.second ] < d[0][ head.second ] )
            swap( d[1][ head.second ], d[0][ head.second ] );

        for( auto i : adj[ head.second ] )
            pq.push( { -( i.second + d[1][ head.second ] ), i.first } );

        if( d[1][0] != inf ) return;
    }
}

int travel_plan( int n, int m, int r[][2], int l[], int k, int p[] )
{
    ::n = n; ::k = k; esc = p;
	for( int i=0; i<n; ++i )
        d[0][i] = d[1][i] = inf;
	for( int i=0; i<m; ++i ){
        adj[ r[i][0] ].push_back( { r[i][1], l[i] } );
        adj[ r[i][1] ].push_back( { r[i][0], l[i] } );
	}

	dijkstra();

	return d[1][0];
}
