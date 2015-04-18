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

ifstream in("input.txt");
ofstream out("output.txt");

int N, curr, prec, sign=1, max1, max2, h[10005];

int main()
{
    in >> N;
    for(int i=0; i<N; i++)
        in >> h[i];

    for(curr=1; true; curr++){
        while( curr<N && (h[curr]-h[curr-1])*sign>0 ) curr++;
        if( curr==N ) break;
        max1++;
        prec=curr;
        sign*=-1;
    }

    for(curr=1, prec=0, sign=-1; true; curr++){
        while( curr<N && (h[curr]-h[curr-1])*sign>0 ) curr++;
        if( curr==N ) break;
        max2++;
        prec=curr;
        sign*=-1;
    }
    out << max(max1,max2)+1 << "\n";

	return 0;
}
