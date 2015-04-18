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

int n, k, d[1005], sol[1005];

int main()
{
	ios_base::sync_with_stdio(false);

    in >> k >> n;
    for( int x=0; x<n; ++x )
        in >> d[x];
    for( int x=0; x<n; ++x )
        for( int j=x; j<n && j<=x+k; ++j )
            sol[x] = max( sol[x], d[j]-d[x] );
    int s=0;
    for( int x=0; x<n; ++x )
        s = max( s, sol[x] );
    out << s << "\n";

	return 0;
}
