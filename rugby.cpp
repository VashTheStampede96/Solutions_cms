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

int n, br[10005];
vector<int> adj[10005];

int solve( int v )
{
    int ans = 0;
    for( auto i : adj[v] )
        ans += solve( i );
    return max( ans, br[v] );
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> n >> br[0] >> br[1];
	for( int i=1, c, b; i<n; ++i ){
        in >> b >> c;
        adj[c].push_back(i);
        br[i] = b;
	}

	out << solve( 0 ) << "\n";

	return 0;
}
