#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e4+5;

int N, M;
vector<int> adj[ MAXN ];
bool occ[ MAXN ];

int contaAdj( int n )
{
        int c=0;
        for(int i=0; i<adj[ n ].size(); i++)
                c += occ[ adj[ n ][ i ] ];
        return adj[ n ].size()-c;
}

void cut( int n )
{
        if( occ[ n ] ) return;
        occ[ n ] = true;
        for(int i=0; i<adj[ n ].size(); i++)
                if( contaAdj( adj[ n ][ i ] )<2 )
                        cut( adj[ n ][ i ] );
        return;
}

int main()
{

	//ios_base::sync_with_stdio(false);

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> N >> M;
	for(int i=0, a , b; i<M; i++){
                in >> a >> b;
                adj[ a ].push_back( b );
                adj[ b ].push_back( a );
	}

	for(int i=0; i<N; i++)
                if( adj[ i ].size()<2 )
                        cut( i );
        int c=0;
        for(int i=0; i<N; i++)
                c += occ[ i ];
        out << N-c << "\n";

	return 0;
}
