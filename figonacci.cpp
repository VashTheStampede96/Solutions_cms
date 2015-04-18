#include <stdio.h>
int g0, g1=1, N, M, n=2;
FILE *in, *out;
int main()
{
    in = fopen( "input.txt","r" );
    out = fopen( "output.txt","w" );

    fscanf( in, "%d%d", &N, &M );

    while( ++n<=N ){
        g0 = n*g1 - (n-1)*g0;
        g1 = g1^g0;
        g0 = g0^g1;
        g1 = g1^g0;
        if( g1<0 )
            g1 = g1%M+M;
        g1 = g1%M;
    }
    fprintf( out, "%d\n", g1 );

    return 0;
}
