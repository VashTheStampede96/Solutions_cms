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
#include <cassert>
#define pb(x) push_back(x)
#define FOR(i,n) for(;i<n;++i)
#define mod(x) (x<0)? -x:x
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;

const int MAXN = static_cast<const int>(1e5+5);
const int INF = static_cast<const int>(1e9);

int N, M, weight[2*MAXN];
vector<ii> adj[MAXN];
ii sol[2*MAXN];

ii solve(int,int);
ii myMin(ii,ii,int);
ii myReplace(ii,int);

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	for( int i=0; i<2*MAXN; i++ )
        sol[i] = make_pair(-1,-1);

    adj[0].push_back( make_pair( 1,0 ) );
	in >> N >> M;
	for(int i=1, a, b, p; i<=M; i++){
        in >> a >> b >> p;
        adj[a].push_back( make_pair( b,i ) );
        weight[i] = p;
	}

	out << solve( 1,0 ).first << "\n";

	return 0;
}

ii solve( int node, int edge )
{
    if( node==N ) return sol[edge] = make_pair( 0,weight[edge] );
    if( sol[edge].first!=-1 ) return sol[edge];

    ii ans = make_pair( INF,INF );
    for(int i=0; i<adj[node].size(); i++)
        ans = myMin( ans, solve( adj[node][i].first, adj[node][i].second ), weight[edge] );

    return sol[edge] = myReplace( ans, weight[edge] );
}

ii myMin( ii f, ii s, int p )
{
    ii f1 = myReplace( f,p );
    ii s2 = myReplace( s,p );

    if( f1<s2 ) return f;
    else return s;
}

ii myReplace( ii f, int p)
{
    if( f.second<=p ){
        swap( f.first, f.second );
        f.second = p;
    }
    else
        if( f.first<p )
            f.first = p;
    return f;
}
