#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e9+5;

int n;
vector<int> len(1,3);

char solve( int n )
{
    if( n==1 ) return 'P';
    if( n==2 || n==3 ) return 'S';
    
    len.pop_back();
    if( n <= len.back() ) return solve(n);
    if( n <= len.back()+len.size()+3 ){
      if( n== len.back()+1 ) return 'P';
      else return 'S';
    }
    else return solve( n-( len.back()+len.size()+3 ) );
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> n;
    for( int k=1, s=3; s<=n; ++k )
      len.push_back( s = 2*len.back()+k+3 );

    out << solve(n) << "\n";

    return 0;
}
