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
typedef pair<int,ii> iii;

const int intoo = 1e9;
const ll longoo = 1e18;

ifstream in("input.txt");
ofstream out("output.txt");

int n, m, c, k, dist[2][35];
bool sacca[35];
vector< pair<int,int> > adj[35];

int solve()
{
    priority_queue<iii> pq;
    pq.push( { 0, { 20, 1 } } );
    iii head;

    for( int x=0; x<35; ++x )
        dist[0][x] = intoo;

    while( !pq.empty() ){
        head = pq.top();
        pq.pop();
        head.first *= -1;

        if( dist[0][ head.second.second ]>head.first || ( dist[1][ head.second.second ]<head.second.first && head.second.second!=c ) ){
            dist[0][ head.second.second ]=head.first;
            dist[1][ head.second.second ]=head.second.first;

            if( sacca[ head.second.second ] )
                head.second.first = 20;

            for( auto x : adj[ head.second.second ] )
                if( head.second.first-x.second >= 0 )
                    pq.push( { -( head.first+x.second ), { head.second.first-x.second, x.first } } );
        }
    }

    return ( dist[0][c]<intoo )? dist[0][c] : -1;
}

int main()
{
	ios_base::sync_with_stdio(false);

	in >> n >> m >> c >> k;
	for( int x=0, a; x<k; ++x ){
        in >> a;
        sacca[a] = true;
	}
	for( int x=0, i, j, w; x<m; ++x ){
        in >> i >> j >> w;
        if( w>20 ) continue;
        adj[i].push_back( {j,w} );
        adj[j].push_back( {i,w} );
	}

	out << solve() << "\n";

	return 0;
}
