#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 5e4 +5;

vector< pair<int,int> > adj[ MAXN ];
int N, M, H, S;
bool occ[ MAXN ];

int solve( int n, int d )
{
        if( occ[ n ] ) return -1;
        if( n == S ) return d;
        occ[ n ] = true;
        sort( adj[n].begin(), adj[ n ].end() );
        return solve( adj[ n ][ 0 ].second, d+1 );
}

int main()
{

	//ios_base::sync_with_stdio(false);

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> N >> M >> H >> S;
	for(int i=0, a, b, l; i<M; i++){
                in >> a >> b >> l;
                adj[ a ].push_back( make_pair( l,b ) );
                adj[ b ].push_back( make_pair( l,a ) );
	}
	out << solve( H,0 ) << "\n";

	return 0;
}
