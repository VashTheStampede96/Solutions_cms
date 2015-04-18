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

vector< pair<int,int> > dom;
vector<bool> occ;
int n, M=1;

int solve( int s )
{
    int ans=0;
    for( int x=0; x<dom.size(); ++x )
        if( !occ[x] ){
            occ[x] = true;
            if( dom[x].first == s ) ans = max( ans, 1+solve( dom[x].second ) );
            if( dom[x].second == s ) ans = max( ans, 1+solve( dom[x].first ) );
            occ[x] = false;
        }
    return ans;
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> n;
	dom.reserve( n );
	occ.reserve( n );
	for( int x=0, y, z; x<n; ++x ){
        in >> y >> z;
        dom.push_back( {y,z} );
        occ.push_back( false );
	}

	for( int x=0; x<dom.size(); ++x ){
        occ[x] = true;
        M = max( M, 1+ max( solve( dom[x].first ), solve( dom[x].second ) ) );
        occ[x] = false;
	}

	out << M << "\n";

	return 0;
}
