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

int n, k, c[100005], pre[100005];

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> n >> k;
	for( int i=1; i<=n; ++i ){
        in >> c[i];
        pre[i] = c[i]+pre[i-1];
	}

	int ans = 1e9;
	for( int i=1; i<=n-k+1; ++i )
        ans = min( ans, pre[i+k-1]-pre[i-1] );
    out << ans << "\n";

	return 0;
}
