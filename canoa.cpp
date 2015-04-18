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

int n, k;
vector< pair<double,int> > atleti;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> n >> k;
	atleti.reserve( n );

	double f, p;
	for( int x=1; x<=n; ++x ){
        in >> f >> p;
        atleti.push_back( { f - (3.0*p) / 2.0, x } );
	}

	nth_element( atleti.begin(), atleti.begin()+k, atleti.end(), greater< pair<double,int> >() );

	for( int x=0; x<k; ++x )
        out << atleti[x].second << "\n";

	return 0;
}
