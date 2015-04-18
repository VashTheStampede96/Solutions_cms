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

ifstream in("input.txt");
ofstream out("output.txt");

int n, r;
vector<ii> ar;

int main()
{
	ios_base::sync_with_stdio(false);

	in >> n >> r;
	ar.reserve(n);
	for( int x=0, i, j; x<n; ++x ){
        in >> i >> j;
        ar.push_back( { j,abs(r-i) } );
	}
	sort( ar.begin(), ar.end() );
	int sol=0, j=1;
	for( auto x : ar )
        sol += x.second+abs( x.first-j++ );
    out << sol << "\n";

	return 0;
}
