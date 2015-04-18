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

pair<int,int> M = { 0,0 }, squadre[25];
int n;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	for( int i=0; i<25; ++i )
        squadre[i] = { 0,-i };

	in >> n;
	for( int i=0, s1, s2, g1, g2; i<n * (n-1) / 2; ++i ){

        in >> s1 >> s2 >> g1 >> g2;

        if( g1>g2 )
            squadre[s1].first += 3;
        if( g1==g2 ){
            squadre[s1].first += 1;
            squadre[s2].first += 1;
        }
        if( g1<g2 )
            squadre[s2].first += 3;

        M = max( M, max( squadre[s1], squadre[s2] ) );
	}

	out << ( -M.second ) << " " << M.first << "\n";

	return 0;
}
