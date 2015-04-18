#include <iostream>
#include <algorithm>
using namespace std;

long long mozzarelle[10000000];

long long solve(int N, int* M, int* P)
{
    long long res = 0;
	for( int i=0; i<N; ++i ){
        mozzarelle[i] = M[i] - P[i];
        res += M[i];
	}

	nth_element( mozzarelle, mozzarelle + N/2, mozzarelle + N );

	for( int i=0; i<N/2; ++i )
        res -= mozzarelle[i];

	return res;
}
