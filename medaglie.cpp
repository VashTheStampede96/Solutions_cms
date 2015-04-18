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
const int maxn = 100005;

int n, v[maxn], sol[maxn], suffix[maxn], m[3] = { 100,300,500 };

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> n;
	for( int i=0, x; i<n; ++i ){
        in >> x;
        v[n-1-i] = m[x];
	}
    for( int i=n-1; i>=0; --i )
        suffix[i] = v[i] + suffix[i+1];
    for( int i=n-1; i>=n-3; --i )
        sol[i] = suffix[i];
    for( int i=n-4; i>=0; --i )
        sol[i] = max( suffix[i]-sol[i+1], max( suffix[i]-sol[i+2], suffix[i]-sol[i+3] ) );
    out << sol[0] << "\n";

	return 0;
}
