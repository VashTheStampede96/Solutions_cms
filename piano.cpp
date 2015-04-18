#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+5;

int N, mem[ MAXN ], Next[ MAXN ];
struct ESAME{
        int s, e, c;
} esami[ MAXN ];

inline bool cmp( const ESAME &ex1, const ESAME &ex2 ){ return ex1.s<ex2.s; }

int solve( int n )
{
        if( n>=N ) return 0;
        if( mem[ n ]!=-1 ) return mem[ n ];
        return mem[ n ] = max( esami[ n ].c + solve( Next[ n ] ), solve( n+1 ) );
}

int makeNext( int n )
{
        int left = n+1, right = N, mid;

        while( left<right ){
                mid = ( left+right )/2;
                if( esami[ mid ].s<=esami[ n ].e )
                        left = mid+1;
                else{
                        if( esami[ mid-1 ].s<=esami[ n ].e ) return mid;
                        else right = mid;
                }
        }

        if( esami[ left ].s>esami[ n ].e ) return left;
        return right;
}

int main()
{
        memset( mem,-1,sizeof(mem) );
	//ios_base::sync_with_stdio(false);

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> N;
	for(int i=0; i<N; i++)
                in >> esami[ i ].s >> esami[ i ].e >> esami[ i ].c;
        sort( esami, esami+N, cmp );
        esami[ N ].s = 1e9;
        for(int i=0; i<N; i++)
                Next[ i ] = makeNext( i );

        out << solve( 0 ) << "\n";

	return 0;
}
