#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXD = 505, MAXV = 1e5+5;

int M, N, ans_t, ans=MAXV*MAXD, mat[MAXD][MAXD], mem[MAXV];
bool isMult[MAXV]={true, true};

int calc(int value)
{
        int ans = 0;
        if( mem[value] != 0 ) return mem[value];
        while( isMult[value+ans] ) ans++;
        return mem[value] = ans;
}

void sieve()
{
        for(int i=2; i<=MAXV; i++)
                if( !isMult[i] )
                        for(int j=2; i*j<=MAXV; j++)
                                isMult[i*j]=true;

        return;
}

int main()
{
        ifstream in("input.txt");
        ofstream out("output.txt");

        sieve();

        in >> N >> M;
        for(int i=0; i<N; i++)
                for(int j=0; j<M; j++)
                        in >> mat[i][j];

        for(int i=0; i<N; i++){
                ans_t=0;
                for(int j=0; j<M; j++)
                        if( isMult[ mat[i][j] ] )
                                ans_t += calc( mat[i][j] );
                ans = min(ans, ans_t);
        }

        for(int i=0; i<M; i++){
                ans_t=0;
                for(int j=0; j<N; j++)
                        if( isMult[ mat[j][i] ] )
                                ans_t += calc( mat[j][i] );

                ans = min(ans, ans_t);
        }

        out << ans << "\n";

        return 0;
}
