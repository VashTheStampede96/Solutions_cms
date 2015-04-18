#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+5;

int N;
priority_queue< pair<int,int> > pq;
vector< pair<int,int> > adj[MAXN];

int DFS(int,int);
void solve(int,int,int,int);

int main()
{

	ios_base::sync_with_stdio(false);
	/*
	ifstream in("input.txt");
	ofstream out("output.txt");
	*/

	cin >> N;
	for(int i=0, x, y; i<N-1; i++){
                cin >> x; cin >> y;
                adj[x].push_back( make_pair(y,0) );
                adj[y].push_back( make_pair(x,1) );
	}
	pair<int,int> A = make_pair( -DFS(1,0), -1 );
	pq.push(A);

	for(int i=0; i<adj[1].size(); i++)
                solve( adj[1][i].first, adj[1][i].second, 1, -A.first );

        int m=-pq.top().first;
        cout << m << "\n";
        while( true ){
                pair<int,int> h = pq.top();
                pq.pop();
                if( -h.first>m ) break;
                cout << -h.second << ' ';
        }
        cout << "\n";

	return 0;
}

int DFS(int n, int p)
{
        int ans=0;
        for(int i=0; i<adj[n].size(); i++)
                if( adj[n][i].first!=p )
                        ans += DFS( adj[n][i].first,n ) + adj[n][i].second;
        return ans;
}

void solve(int n, int c, int p, int s)
{
        int k = (c==1)? 0:1;
        pair<int,int> x = make_pair( -( s+k-c ), -n );
        pq.push(x);
        for(int i=0; i<adj[n].size(); i++)
                if( adj[n][i].first!=p )
                        solve( adj[n][i].first, adj[n][i].second, n, -x.first );
        return;
}
