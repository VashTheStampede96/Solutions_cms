#include <bits/stdc++.h>
using namespace std;
typedef long long llint;
const llint inf = numeric_limits<llint>::max(),
                maxn = 1e6+5;

int n;
llint b, c;
llint pfx[maxn];

llint cost(int,int,int);
bool check(int);

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> n >> b;

	for( int i=1; i<=n; ++i ){
        in >> pfx[i];
        pfx[i] += pfx[i-1];
	}

	int l = 1, r = n, mid;
	while( r-l>1 ){
        mid = (r+l) / 2 ;
        if( check( mid ) )
            l = mid;
        else
            r = mid;
	}

    if( check(r) ) out << r << "\n";
	else out << l << "\n";

	return 0;
}

inline llint cost( int l, int r, int m ){ return (2*m-l-r)*(pfx[m]-pfx[m-1]) + (pfx[r]-pfx[m]) - (pfx[m-1]-pfx[l-1]); }

bool check( int length )
{
    c = inf;
    for( int i=1; i<=n-length+1 && c>b; ++i )
        c = cost( i, i+length-1, (2*i+length-1) / 2 );
    if( c>b )
        return false;
    return true;
}
