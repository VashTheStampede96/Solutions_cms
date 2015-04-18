#include <fstream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int,int> ii;
const int MAXN = 1e5 +5;

vector<int> adj[MAXN];
queue< ii > coda;
int N, ans, k, w[MAXN];

int main()
{
        ifstream in("input.txt");
        ofstream out("output.txt");

        in >> N >> w[0] >> w[N+2];
        for(int i=1, c, b; i<N; i++){
                in >> b;
                in >> c;
                adj[c].push_back(i);
                w[i]=b;
        }

        coda.push( make_pair( 0,w[0]+1 ) );

        while( !coda.empty() ){
                ii head=coda.front();
                coda.pop();

                if( head.second<w[ head.first ] ) ans++;
                k=min( head.second, w[ head.first ] );
                for(int i=0; i<adj[ head.first ].size(); i++)
                        coda.push( make_pair( adj[ head.first ][i],k ) );
        }

        out << ans << "\n";

        return 0;
}
