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
#define pb(x) push_back(x)
#define FOR(i,n) for(;i<n;++i)
#define mod(x) (x<0)? -x:x
#define f first
#define s second

using namespace std;
typedef long long ll;
const ll INF = 10e9;

int n, k, p[5005];
ll mem[5005][5005], pre[5005];

ll solve( int n, ll w )
{
    if( w>=k ) return 0;
    if( n>=::n || w+pre[::n]-pre[n]<k ) return INF;
    if( mem[n][w]>0 ) return mem[n][w];
    return mem[n][w] = min( p[n]+solve( n+1, w+p[n] ), solve( n+1, w ) );
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> n >> k;
    for( int i=0; i<n; ++i ){
        in >> p[i];
        pre[i+1] = pre[i]+p[i];
    }

    out << solve( 0,0 ) << "\n";

	return 0;
}
