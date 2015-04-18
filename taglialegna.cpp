#include <algorithm>
#include <string.h>
#include <iostream>
#include <utility>
using namespace std;
const int MAXN=2000005;

typedef pair<int,int> ii;

void Abbatti(int, int);
void initAbb();
void initDx();
void trees();
int solve(int);
int solve2(int,int);

int *H, N, abb[MAXN], sx[MAXN], dx[MAXN], mem[MAXN], mem2[MAXN];
ii scelta[MAXN];

void Pianifica(int N, int altezza[])
{
        ::H=altezza;
        ::N=N;
        memset( mem, -1, sizeof(mem) );
        memset( mem2, -1, sizeof(mem2) );

        initDx();
        initAbb();

        solve(0);
        trees();

        return;
}

void initDx()
{
        for(int i=N-1; i>=0; --i){
                dx[i]=i;
                while( dx[i]+1<N && i+H[i]>dx[i]+1 )
                        dx[i]=dx[ dx[i]+1 ];
        }

        return;
}

void initAbb()
{
        for(int i=0; i<N; i++){
		sx[i]=i; abb[i]=i;
		while (sx[i] - 1 >= 0 && sx[i] - 1 > i - H[i]) {
			abb[sx[i] - 1] = i;
			sx[i] = sx[sx[i] - 1];
		}
	}

        return;
}

int solve(int n)
{
        if( n>=N ) return 0;
        if( mem[n]!=-1 ) return mem[n];

        int ans1=1+solve(dx[n]+1);
        int a=solve2(abb[n],n);
        int ans2=1+solve(a+1);

        if( ans1<ans2 )
                scelta[n]=make_pair( 1,n );
        else
                scelta[n]=make_pair( 0,a );

        return mem[n]=min( ans1,ans2 );
}

int solve2(int n, int m)
{
        if( mem2[n]!=-1 ) return mem2[n];
        int ans=n;
        scelta[m]=make_pair( 0,n );
        if( abb[n]!=n ){
                int k=solve2(abb[n],m);
                if( solve(n+1)>solve(k+1) ){
                        scelta[m].second=k;
                        ans=k;
                }
        }
        return mem2[n]=ans;
}

void trees()
{
        for(int i=0; i<N; i++){
                switch( scelta[i].first )
                {
                        case 0: Abbatti( scelta[i].second,0 ); i=scelta[i].second; break;
                        case 1: Abbatti(i,1); i=dx[i]; break;
                        default: break;
                }
        }

        return;
}
