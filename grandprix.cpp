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

int n, m, first, var, var2;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> n >> m >> first;
	for( int x=0; x<n-1; ++x )
        in >> var;
    for( int x=0; x<m; ++x ){
        in >> var >> var2;
        if( var2 == first )
            first = var;
    }
    out << first << "\n";

	return 0;
}
