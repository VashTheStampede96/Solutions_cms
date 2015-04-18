#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=100005;

bool occ[MAXN];

int Trova(int N, int K, int insieme[])
{
        if(K==1) return 0;

        int conta=0;
        sort(insieme,insieme+N);

        for(int i=N-1; i>=0; i--)
                if( insieme[i]*K >= MAXN || !occ[ insieme[i]*K ] ){
                        conta++;
                        occ[ insieme[i] ]=true;
                }

        return conta;
}
