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

int solve(int,int,int);
int value(int);
bool isOk(int,int,int);

int r, c, k=44, mem[64][64][10],
     m[44]={
                    0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13, 16, 17, 18, 19, 20, 21, 22, 24, 25, 26, 27,
                    32, 33, 34, 35, 36, 37, 38, 40, 41, 42, 43, 44, 45, 48, 49, 50, 51, 52, 53, 54
                };

int main()
{
    memset( mem, -1, sizeof(mem) );
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> r >> c;
	if(r<c) swap(r,c);
    out << solve(0,0,0) << "\n";

	return 0;
}

int solve(int f, int s, int r)
{
    if( ::r==r ) return 0;
    if( mem[f][s][r]!=-1 ) return mem[f][s][r];
    int ans=0;
    for(int i=0; i<k && m[i]<(1<<c); i++)
        ans = max( ans, (isOk(m[i],f,s))? value(m[i])+solve(s,m[i],r+1) : 0 );

    return mem[f][s][r] = ans;
}

inline int value(int m)
{
    int ans=0;
    while(m){
        ans += m&1;
        m >>= 1;
    }
    return ans;
}

bool isOk(int m, int f, int s)
{
    if(m>=(1<<c)) return false;
    for(int i=0, x; i<c; i++){
        x = 1<<i;
        if(m&x)
            if(
               ( ( f&x )==x && ( s&x )==x ) ||
               ( i>1 && ( f&(x>>2) )==(x>>2) && ( s&(x>>1) )==(x>>1) ) ||
               ( i<c-2 && ( f&(x<<2) )==(x<<2) && ( s&(x<<1) )==(x<<1) )
              ) return false;
    }

     return true;
}
