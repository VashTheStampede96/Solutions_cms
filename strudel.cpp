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
#include <cassert>
#define pb(x) push_back(x)
#define FOR(i,n) for(;i<n;++i)
#define mod(x) (x<0)? -x:x
#define f first
#define s second
#define INF 1e9

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

const int MAXN = 1e5+5;

int N, pot=1, v[MAXN], t[4*MAXN];
pair<int,int> s[MAXN];

int init(int);
int rmq(int,int,int,int,int);
int lw_b(int);
int check(int);

int main()
{
    in >> N;
    while(pot<N) pot *= 2;
    for(int i=1; i<=N; i++)
        in >> v[i];
    for(int i=1, x; i<=N; i++){
        in >> x;
        s[i].first = v[i] = v[i-1]+v[i]-x;
        s[i].second = i;
    }
    sort(s+1,s+1+N);
    init(1);

    int MAX = 0;
    for(int i=0; i<=N; i++)
        MAX = max( MAX, rmq(1,1,pot,1,lw_b(i))-i );
    out << MAX << "\n";

	return 0;
}

int init(int i)
{
    if( i>=pot ) return t[i] = s[i-pot].second;
    return t[i] = max( init(2*i), init(2*i+1) );
}

int rmq(int i, int sx, int dx, int x, int y)
{
    if( sx>=x && dx<=y ) return t[i];
    if( sx>y || dx<x ) return 0;

    int mid=(sx+dx)/2;
    return max( rmq(2*i,sx,mid,x,y), rmq(2*i+1,mid+1,dx,x,y) );
}

int lw_b(int i)
{
    int l=0, r=N, mid;

    while( l<r-1 ){
        mid = (l+r)/2;
        if( s[mid].first==v[i] ) return check(mid);
        if( s[mid].first>v[i] ) r=mid;
        else l=mid;
    }

    if( s[l].first==v[i] ) return check(l);
    return check(r);
}

int check(int i)
{
    while( s[i+1].first==s[i].first ) i++;
    return i;
}
