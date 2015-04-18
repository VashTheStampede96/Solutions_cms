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
const ll oo = 1e15;

ll n, m, num[15];
vector<ll> sol;

ifstream in("input.txt");
ofstream out("output.txt");

void solve( ll pos, ll sum )
{
    if( ( pos > n && sum != m ) || sum > m )
        return;
    if( sum == m && pos == n+1 ){
        for( int x=0; x<sol.size()-1; ++x )
            out << sol[x] << " ";
        out << "\n";
        return;
    }
    for( ll x=pos, k=0; x<=n; ++x ){
        k = 10*k + num[x];
        sol.push_back( x );
        solve( x+1,sum+k );
        sol.pop_back();
    }
}

int main()
{
	in >> n;
	sol.reserve( n );
	for( ll x=1; x<=n; ++x )
        in >> num[x];
    in >> m;

    num[n+1] = oo;
    solve( 1,0 );

	return 0;
}
