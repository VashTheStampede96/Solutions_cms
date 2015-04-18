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
#include <cassert>

using namespace std;
typedef pair<double,double> dd;
typedef pair<dd,int> ddi;
typedef long long ll;
const int maxn = 5e5+5;

ll b;
int n;
vector<ddi> work;
priority_queue<int> pq;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> n >> b;
	work.reserve( n );
	for( double i=1, s, q; i<=n; ++i ){
        in >> s >> q;
        work.push_back( { { s/q,q },i } );
	}

	sort( work.begin(), work.end() );

	double idx = 0, cost = 0, s = 0, sumq = 0, rat;
	for( int i=0; i<n; ++i ){
        auto x = work[i];
        rat = x.first.first;
        sumq += x.first.second;
        pq.push( x.first.second );

        while( rat * sumq > b ){
            sumq -= pq.top();
            pq.pop();
        }

        if( s < pq.size() || ( s == pq.size() && cost > sumq * rat ) ){
            cost = sumq * rat;
            s = pq.size();
            idx = i;
        }
	}

	sumq = 0;
	rat = work[idx].first.first;
	priority_queue<dd> pq;
	for( int i=0; i<=idx; ++i ){
        sumq += work[i].first.second;
        pq.push( { work[i].first.second, work[i].second } );
	}

	while( rat * sumq > b ){
        sumq -= pq.top().first;
        pq.pop();
	}

    assert( s == pq.size() );
    out << pq.size() << "\n";
	while( !pq.empty() ){
        out << pq.top().second << "\n";
        pq.pop();
	}

	return 0;
}
