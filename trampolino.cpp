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
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int n, e[100005], p[100005];

int main()
{
    ifstream fr("input.txt");

	fr >> n;
	for( int i=0; i<n; e[i]+=i++ )
        fr >> e[i];
	e[n] = n;

	for( int i=0, l=1; i<n+1; ++i )
        while( l<=e[i] ) p[l++] = i;

    int ans = 0, t = n;
    while( t>0 ){
        ++ans;
        t = p[t];
    }

    ofstream out("output.txt");

    out << ans << "\n";

	return 0;
}
