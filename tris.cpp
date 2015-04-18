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

int contaX, contaO, mem1[512][512], mem2[512][512],
        win[8] = { 7,56,73,84,146,273,292,448 };
char c;

int Gabriele( int,int );
int Giorgio( int,int );

int main()
{
	memset( mem1,-1,sizeof(mem1) );
	memset( mem2,-1,sizeof(mem2) );
	ifstream in("input.txt");
	ofstream out("output.txt");

	int esistenza = 0, tipo = 0;

	for(int i=0; i<9; i++){
                in >> c;
                if( c=='X' ){
                        contaX++;
                        esistenza += (1<<i);
                }
                if( c=='O' ){
                        contaO++;
                        esistenza += (1<<i);
                        tipo += (1<<i);
                }
	}

	if( contaX==contaO ) out << Gabriele( esistenza, tipo ) << "\n";
	else out << Giorgio( esistenza, tipo ) << "\n";

	return 0;
}

int Gabriele( int e, int t )
{
        if( mem1[ e ][ t ]!=-1 ) return mem1[ e ][ t ];
        for(int i=0; i<8; i++)
                if( ( t&win[ i ] ) == win[ i ] )
                        return mem1[ e ][ t ] = 0;
        if( e == 511 ) return mem1[ e ][ t ] = 0;
        int ans = 0;
        for(int i=0; i<9 && !ans; i++)
                if( ( (1<<i)&e ) == 0 )
                        ans = Giorgio( e+(1<<i), t );
        return mem1[ e ][ t ] = ans;
}

int Giorgio( int e, int t )
{
        if( mem2[ e ][ t ]!=-1 ) return mem2[ e ][ t ];
        for(int i=0; i<8; i++)
                if( ( (e^t)&win[ i ] ) == win[ i ] )
                        return mem2[ e ][ t ] = 1;
        if( e == 511 ) return mem2[ e ][ t ] = 0;
        int ans = 1;
        for(int i=0; i<9 && ans; i++)
                if( ( (1<<i)&e ) == 0 )
                        ans = Gabriele( e+(1<<i), t+(1<<i) );
        return mem2[ e ][ t ] = ans;
}
