#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef pair<ii,ii> iiii;

const int maxn = 805;
const int oo = 1e9;

queue<iii> h;
ii d, ho;
int n, s, l = -1, r, mid, t[maxn][maxn];
char m[maxn][maxn];
bool occ[maxn][maxn];

void api( );
bool mecho(int);

ifstream in("input.txt");
ofstream out("output.txt");

int main()
{
    for( int i=0; i<maxn; ++i )
        for( int j=0; j<maxn; ++j )
            t[i][j] = oo;

    in >> n >> s;
    for( int i=1; i<=n; ++i )
        for( int j=1; j<=n; ++j ){
            in >> m[i][j];
            if( m[i][j] == 'H' )
                h.push( { { i,j }, 0 } );
            if( m[i][j] == 'M' )
                ho = { i,j };
            if( m[i][j] == 'D' )
                d = { i,j };
        }
    api( );
    t[ d.first ][ d.second ] = oo;
    r = n*n +5;
    while( r - l > 1 ){
        mid = ( l + r ) / 2;
        if( mecho( mid ) )
            l = mid;
        else r = mid;
    }

    out << l << "\n";

    return 0;
}

void api( )
{
    iii head;
    while( !h.empty() ){
        head = h.front();
        h.pop();
        if( m[ head.first.first ][ head.first.second ] == 0 ||
            m[ head.first.first ][ head.first.second ] == 'T' ||
            m[ head.first.first ][ head.first.second ] == 'D' )
            continue;
        if( t[ head.first.first ][ head.first.second ]>head.second ){
            t[ head.first.first ][ head.first.second ]=head.second;
            h.push( { { head.first.first+1, head.first.second }, head.second+s } );
            h.push( { { head.first.first-1, head.first.second }, head.second+s } );
            h.push( { { head.first.first, head.first.second+1 }, head.second+s } );
            h.push( { { head.first.first, head.first.second-1 }, head.second+s } );
        }
    }
}

bool mecho( int time )
{
    memset( occ, 0, sizeof(occ) );
    queue<iii> q;
    q.push( { ho,time*s } );

    iii head;

    while( !q.empty() ){
        head = q.front();
        q.pop();

        if( m[ head.first.first ][ head.first.second ] == 0 ||
            m[ head.first.first ][ head.first.second ] == 'T' ||
            t[ head.first.first ][ head.first.second ] <= head.second ||
            occ[ head.first.first ][ head.first.second ] )
            continue;
        if( head.first == d )
            return true;
        occ[ head.first.first ][ head.first.second ] = true;
        q.push( { { head.first.first+1, head.first.second }, head.second+1 } );
        q.push( { { head.first.first-1, head.first.second }, head.second+1 } );
        q.push( { { head.first.first, head.first.second+1 }, head.second+1 } );
        q.push( { { head.first.first, head.first.second-1 }, head.second+1 } );
    }

    return false;
}
