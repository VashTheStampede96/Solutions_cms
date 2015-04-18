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
#define INF 1e9
#include <cassert>

using namespace std;
typedef pair<int,int> ii;
const int maxn = 2005;

int n, match[maxn];
ii w[maxn];
vector<int> win[maxn];
bool occ[maxn];

ifstream in("input.txt");
ofstream out("output.txt");

void print( int cur )
{
    out << n-1 << "\n";
    --n;
    for( int i=0; i<n; ++i, cur = match[cur] )
        out << cur+1 << " " << match[cur]+1 << "\n";
}

bool solve( int i, int m )
{
    if( m==n-1 ) return true;
    occ[i] = true;
    for( auto x : win[i] )
        if( !occ[x] ){
            match[i] = x;
            if( solve( x,m+1 ) )
                return true;
        }
    occ[i] = false;
    return false;
}

bool cmp( const int& a, const int& b ){ return w[a].first>w[b].first; }

int main()
{
	in >> n;
	for( int i=0, x, y; i< n * (n-1) / 2; ++i ){
        in >> x >> y;
        win[--x].push_back(--y);
	}
	for( int i=0; i<n; ++i )
        w[i] = { win[i].size(), i };

    for( int i=0; i<n; ++i )
        sort( win[i].begin(), win[i].end(), cmp );

	sort( w, w+n, greater<ii>() );

	for( int i=0; i<n; ++i )
        if( solve( w[i].second,0 ) ){
            print( w[i].second );
            return 0;
        }

	return 0;
}
