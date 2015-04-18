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
#define INF 1e9
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

ifstream in("input.txt");
ofstream out("output.txt");

vii adj[10005];
int N, M, v[100005], mem[100005];

int solve( int n, int e )
{
    if( mem[e]!=-1 ) return mem[e];
    int MAX = 0;
    vii::iterator i;
    for(i=adj[n].begin(); i!=adj[n].end(); i++)
        if( v[ i->second ]>v[ e ] )
            MAX = max( MAX,solve( i->first, i->second ) );

    return mem[ e ] = MAX+1;
}

int main()
{
    memset( mem,-1,sizeof(mem) );

    in >> N >> M;
    for(int i=0, a, b, w; i<M; i++){
        in >> a >> b >> w;
        adj[a].push_back( make_pair(b,i) );
        v[i] = w;
    }

    for(int i=0; i<N; i++, mem[M]=-1)
        solve( i,M );

    int MAX=0;
    for(int i=0; i<M; i++)
        MAX = max( MAX, mem[i] );
    out << MAX << "\n";

	return 0;
}
