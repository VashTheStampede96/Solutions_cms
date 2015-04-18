#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
const int MAXN=100005, INF=100000005;

vector< pair<int, int> > adj[MAXN];
queue<int> coda;
pair<int, int> sol[MAXN];
int W, L;
bool vis[MAXN];

void propaga(const int& n)
{
        for(int i=0; i<adj[n].size(); i++){
                int v=adj[n][i].first, w=adj[n][i].second;
                pair<int, int> p;
                if( !vis[ v ] ){
                        if( sol[ v ].first>sol[ n ].first+1 ){
                                sol[ v ].first=sol[ n ].first+1;
                                sol[ v ].second=min( sol[n].second, w );
                                coda.push( v );
                        }
                        else
                                if( sol[ v ].first==sol[ n ].first+1 && sol[ v ].second>min( sol[ n ].second, w) ){
                                        sol[ v ].second=min( sol[ n ].second, w);
                                        coda.push( v );
                                }
                }
        }

        return;
}

int BFS()
{
        coda.push(W);

        while( !coda.empty() ){
                int head=coda.front();
                coda.pop();

                vis[head]=true;
                propaga(head);
        }

        return sol[L].second;
}

int Analizza(int N, int M, int W, int L, int arco_da[], int arco_a[], int capacita[], int R, int C)
{
        ::W=W;
        ::L=L;

        for(int i=0; i<M; i++){
                adj[ arco_da[i] ].push_back( make_pair( arco_a[i], capacita[i] ) );
                adj[ arco_a[i] ].push_back( make_pair( arco_da[i], capacita[i] ) );
        }

        for(int i=1; i<=N; i++) sol[i]=make_pair( INF+1, INF+1);
        sol[W].first=0;

        return BFS();
}
