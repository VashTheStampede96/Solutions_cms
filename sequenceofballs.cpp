#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <list>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int intoo = 1e9;
const ll longoo = 1e18;
const int maxn = 4005;

int ti, td, tr, te, n1, n2,
    dp[maxn][maxn], posA[maxn][26], posB[maxn][26];
char A[maxn], B[maxn];

int main()
{
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
    ios_base::sync_with_stdio( false );

    cin >> ti >> td >> tr >> te;
    cin >> A;
    cin >> B;
    n1 = strlen(A); n2 = strlen(B);

    for( int x = 0; x<26; ++x )
        posA[n1][x] = posB[n2][x] = -1;

    for( int x = n1-1; x>=0; --x ){
        for( int y = 0; y<26; ++y )
            posA[x][y] = posA[x+1][y];
        posA[x][ A[x]-'a' ] = x;
    }

    for( int x = n2-1; x>=0; --x ){
        for( int y = 0; y<26; ++y )
            posB[x][y] = posB[x+1][y];
        posB[x][ B[x]-'a' ] = x;
    }

    for( int x = 0; x<n1; ++x )
        dp[x][n2] = td * ( n1-x );
    for( int y = 0; y<n2; ++y )
        dp[n1][y] = ti * ( n2-y );

    for( int X, Y, m, y, x = n1-1; x >= 0; --x ){
        for( y = n2-1; y >= 0; --y ){
            m = intoo;
            m = min( m, tr * ( A[x] != B[y] ) + dp[x+1][y+1] );
            m = min( m, ti + dp[x][y+1] );
            m = min( m, td + dp[x+1][y] );
            X = posA[x][ B[y]-'a' ]; Y = posB[y][ A[x]-'a' ];
            if( X != -1 && Y != -1 && A[x] != B[y] )
                m = min( m, td * ( X-x-1 ) + te + ti * ( Y-y-1 ) + dp[X+1][Y+1] );
            dp[x][y] = m;
        }
    }

    cout << dp[0][0] << "\n";

	return 0;
}
