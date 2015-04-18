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

char S[100005];
bool occ[100005];
int N;

void check_PaH(int x)
{
    if( x>=0 ){
        if( strcmp( S+x,"PaH" )==0 )
            occ[x]=occ[x+1]=occ[x+2]=true;
    }
}

void check_TuNZ(int x)
{
    if( x>=0 ){
        if( strcmp( S+x,"TuNZ" )==0 )
            occ[x]=occ[x+1]=occ[x+2]=occ[x+3]=true;
    }
}

int main()
{
	in >> N;

	for( int i=0; i<N; i++ ){
        in >> S[i];
        if( S[i]=='H' ) check_PaH(i-2);
        else if( S[i]=='Z' ) check_TuNZ(i-3);
	}

	for(int i=0; i<N; i++){
        while( !occ[i] && i<N ) out << S[i++];
        out << " ";
	}
    out << "\n";

	return 0;
}
