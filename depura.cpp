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
const int maxn = 2005;

ifstream in("input.txt");
ofstream out("output.txt");

int k, r;
vector<int> adj[maxn];
bool into[maxn];

int solve( int n )
{
    if( into[n] )
        return 0;
    if( adj[n].empty() )
        return -1;
    int ans=0, y=0;
    for( auto x : adj[n] ){
        y = solve(x);
        if( y==-1 )
            return -1;
        else ans += y;
    }
    into[n] = true;
    return 1+ans;
}

int main()
{
    in >> k >> r;
    for( int x=0, a; x<k; ++x ){
        in >> a;
        into[a] = true;
    }
    for( int x=0, a, n, b; x<r; ++x ){
        in >> a >> n;
        for( int y=0; y<n; ++y ){
            in >> b;
            adj[a].push_back(b);
        }
    }

    out << solve(1) << "\n";

	return 0;
}
