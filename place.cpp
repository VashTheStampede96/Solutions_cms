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

using namespace std;
const int MAXN = 5e5+5;

int M, N, w[MAXN], from[MAXN], to[MAXN],
    tree[4*MAXN];
vector<int> adj[MAXN];
vector<int> topoSort( 1 );

int toposort(int);
void update(int,int,int,int,int,int);
int query(int,int,int,int,int);

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> N >> M >> w[1];
	int pot=1;
	while( pot<N ) pot*=2;
	topoSort.reserve( pot );

	for( int i=2, a; i<=N; ++i ){
        in >> w[i] >> a;
        adj[a].push_back( i );
	}
	toposort( 1 );

	for( int i=N; i<pot; ++i )
        topoSort.push_back( 0 );

    char c;
    int a, b;
    for( int i=0; i<M; ++i ){
        in >> c;
        if( c=='p' ){
            in >> a >> b;
            update( 1, 1, pot, from[a]+1, to[a], b );
        }
        else{
            in >> a;
            out << query( 1, 1, pot, from[a], 0 )+w[a] << "\n";
        }
    }

	return 0;
}

int toposort(int n)
{
    from[n] = to[n] = topoSort.size();
    topoSort.push_back( n );
    for(int i=0; i<adj[n].size(); ++i)
        to[n] = max( to[n], toposort( adj[n][i] ) );
    return to[n];
}

int query(int idx, int a, int b, int x, int val)
{
    if( a>x || b<x ) return 0;
    if( b-a == 0 ) return tree[ idx ] + val;

    int mid = (a+b)>>1;
    return query( 2*idx, a, mid, x, val+tree[ idx ] ) + query( 2*idx+1, mid+1, b, x, val+tree[ idx ] );
}

void update( int idx, int a, int b, int x, int y, int val )
{
    if( a>y || b<x || x>y ) return;
    if( a>=x && b<=y ){
        tree[ idx ] += val;
        return;
    }

    int mid = (a+b)>>1;
    update( 2*idx, a, mid, x, y, val );
    update( 2*idx+1, mid+1, b, x, y, val );
}
