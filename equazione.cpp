#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

long long sqrtN, N;
inline int s(int x)
{
        int ans = 0;
        while( x>0 ){
                ans += x%10;
                x /= 10;
        }
        return ans;
}

inline int root(int sX)
{
        long double ans;
        ans = ( sqrt( double( sX*sX + 4*N ) ) - double( sX ) )/2.0;
        if( floor(ans)<ans ) return 0;
        return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	/*
	ifstream in("input.txt");
	ofstream out("output.txt");
	*/
	cin >> N;
	sqrtN = sqrt(N);
	for(int sX=1, x; sX<=81; sX++){
	        x = root( sX );
	        if( s(x)==sX ){
                        cout << x << "\n";
                        return 0;
	        }
	}

	cout << "-1\n";

	return 0;
}
