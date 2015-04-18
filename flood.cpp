#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#define f(x) x.first
# define s(x) x.second
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
const int MAXN = 1e5+5;

int N, W, K;
stack<int> pila;
iii points[MAXN];
int adj[2*MAXN][4][2],
     seq[5][4] = {
                            { 3,0,1,2 },
                            { 0,1,2,3 },
                            { 1,2,3,0 },
                            { 2,3,0,1 },
                            { 0,1,2,3 }
                        };
bool unsave[2*MAXN], occ[2*MAXN];

void dfs(int);

int main()
{
	freopen( "input.txt","r", stdin );
	freopen( "output.txt", "w", stdout );

	scanf( "%d", &N );
	int i=0;
	while( i<N ){
        scanf( "%d%d", &( points[i].first.first ), &( points[i].first.second ) );
        points[i].second = i+1;
        ++i;
	}

	scanf( "%d", &W );
	K = W;
	for( int i=1, a, b, dx, dy; i<=W; ++i ){
        scanf( "%d%d", &a, &b );
        dx = points[a-1].first.first - points[b-1].first.first;
        dy = points[a-1].first.second - points[b-1].first.second;

        if( dx>0 ){
            adj[a][3][0] = b;
            adj[b][1][0] = a;
            adj[a][3][1] = adj[b][1][1] = i;
        }
        else{
            if( dx<0 ){
                adj[a][1][0] = b;
                adj[b][3][0] = a;
                adj[a][1][1] = adj[b][3][1] = i;
            }
            else{
                if( dy>0 ){
                    adj[a][2][0] = b;
                    adj[b][0][0] = a;
                    adj[a][2][1] = adj[b][0][1] = i;
                }
                else{
                    adj[a][0][0] = b;
                    adj[b][2][0] = a;
                    adj[a][0][1] = adj[b][2][1] = i;
                }
            }
        }
	}

	sort( points, points+N );

    i = N++;
	while( N-- )
        dfs( points[i-N].second );

    printf( "%d\n", K );
    ++W;
    unsave[0] = true;
    while( W-- )
        if( !unsave[W] )
            printf( "%d\n", W );

	return 0;
}

void dfs( int p )
{
    ii next = { p,-1 };
    bool b;
    do{
        for( auto i : seq[ next.second ] )
            if( adj[ next.first ][i][0] != 0 && !occ[ adj[ next.first ][i][1] ] ){
                b = unsave[ adj[ next.first ][i][1] ] ^= 1;
                if( b ) --K;
                else ++K;
                pila.push( adj[ next.first ][i][1] );
                next = { adj[ next.first ][i][0], i };
                break;
            }
    }while( next.first != p );

    int t, x = pila.size()+1;
    while( --x ){
        t = pila.top();
        pila.pop();
        occ[t] = true;
    }
}
