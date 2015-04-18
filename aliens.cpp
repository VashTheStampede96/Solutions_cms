#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
#include <assert.h>
using namespace std;
typedef long long ll;

bool examine( int,int );
bool can( ll,ll );
void solution( int,int );
void select( ll,ll,ll,ll,ll,ll );
int bsu( ll,ll,ll );
int bsl( ll,ll,ll );
int bsr( ll,ll,ll );

ll N;

void find_centre( int N, int X, int Y )
{
        ::N = N;
        ll Xi = X, Yi = Y;
        //Distance from top
        ll u = 1;
        while( can( Xi, Yi+u ) ) u <<= 1;
        u = bsu( Xi, Yi+(u>>1), min( Yi+u, ::N ) );

        //Distance from left
        ll l = 1;
        while( can( Xi-l, Yi ) ) l <<= 1;
        l = bsl( max( Xi-l, 1LL ), Yi, Xi-(l>>1) );

        //Distance from right
        ll r = 1;
        while( can( Xi+r, Yi ) ) r <<= 1;
        r = bsr( Xi+(r>>1), Yi, min( Xi+r, ::N ) );

        ll M = r-l+1; //Side
        ll x0 = (l+r)>>1, y0 = (2*u-M+1)>>1; //Center COOs

        //UP
        u = 2;
        ll U = 0;
        while( u<5 && can( x0, y0+u*M ) ){ ++U; u += 2; }

        //LEFT
        l = 2;
        ll L = 0;
        while( l<5 && can( x0-l*M, y0 ) ){ ++L; l += 2; }

        //RIGHT
        r = 2;
        ll R = 0;
        while( r<5 && can( x0+r*M, y0 ) ){ ++R; r += 2; }

        select( M, U, R, L, x0, y0 );
}

inline bool can( ll x, ll y )
{
        if( x<1 || y<1 || x>N || y>N ) return false;
        else return examine( x, y );
}

int bsu( ll x, ll y, ll u )
{
        ll mid;

        while( y<u-1 ){
            mid = (y+u)>>1;
            if( can( x, mid ) ) y = mid;
            else u = mid;
        }

        return ( can( x, u ) )? u : y;
}

int bsl( ll x, ll y, ll l )
{
        ll mid;
        while( x<l-1 ){
            mid = (x+l)>>1;
            if( can( mid, y ) ) l = mid;
            else x = mid;
        }

        return ( can( x, y ) )? x : l;
}

int bsr( ll x, ll y, ll r )
{
        ll mid;

        while( x<r-1 ){
            mid = (x+r)>>1;
            if( can( mid, y ) ) x = mid;
            else r = mid;
        }

        return ( can( r, y ) )? r : x;
}

void select( ll m, ll u, ll r, ll l, ll x, ll y )
{
        switch( u )
        {
                case 0:
                        switch( l )
                        {
                                case 2:
                                        solution( x-2*m, y-2*m );
                                        break;
                                case 1:
                                        if( r==1 ) solution( x, y-2*m );
                                        else solution( x-m, y-m );
                                        break;
                                case 0:
                                        if( r==2 ) solution( x+2*m, y-2*m );
                                        else solution( x+m,y-m );
                                        break;
                        }
                        break;
                case 1:
                        switch( l )
                        {
                                case 2:
                                        solution( x-2*m, y );
                                        break;
                                case 1:
                                        if( r==1 ) solution( x, y );
                                        else solution( x-m, y+m );
                                        break;
                                case 0:
                                        if( r==2 ) solution( x+2*m, y );
                                        else solution( x+m, y+m );
                                        break;
                        }
                        break;
                case 2:
                        if( l==0 ) solution( x+2*m, y+2*m );
                        if( l==1 ) solution( x, y+2*m );
                        else solution( x-2*m, y+2*m );
                        break;
        }
}
