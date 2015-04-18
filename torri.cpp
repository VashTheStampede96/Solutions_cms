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

using namespace std;
typedef pair<int,int> ii;
const int p = 1<<10;

int rmq(int,int,int,int);
void update(int);

int n, tot, sol[2*p];
ii seq[p];

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> n;
	for( int i=0; i<n; ++i ){
        in >> seq[i].first >> seq[i].second;
        tot += seq[i].second;
	}

	for( int i=0; i<n; ++i ){
        int h = seq[i].first,
             s = seq[i].second + rmq( 1, 0, p-1, h+1 );
        if( sol[ p+h ]<s ){
            sol[ p+h ] = s;
            update( (p+h)>>1 );
        }
	}

	out << tot - sol[1] << "\n";

	return 0;
}

int rmq( int i, int a, int b, int x )
{
    if( a>p-1 || b<x ) return 0;
    if( a>=x && b<=p-1 ) return sol[i];

    int mid = (a+b)>>1;
    return max( rmq( 2*i, a, mid, x ), rmq( 2*i+1, mid+1, b, x ) );
}

void update( int x )
{
    while( x )
    {
        sol[ x ] = max( sol[ 2*x ], sol[ 2*x+1 ] );
        x >>= 1;
    }
}
