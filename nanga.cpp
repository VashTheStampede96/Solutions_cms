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

int n, k=1000*100 +5000, alt[ 2*1000*100 +5 ];

int main()
{
	ios_base::sync_with_stdio(false);

	in >> n;
	++alt[k];
	for( int x=0, a; x<n; ++x ){
        in >> a;
        k += a;
        ++alt[k];
	}

	int m=0;
	for( int x=0; x<2*1000*100+5; ++x )
        if( alt[x]>alt[m] )
            m=x;
    out << m-1000*100 << "\n";

	return 0;
}
