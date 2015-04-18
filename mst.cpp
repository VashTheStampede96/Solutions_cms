#include <fstream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

const int MAXN=10005;

typedef long long ll;
typedef pair<ll,int> lli;
typedef vector<lli> vlli;
typedef pair<lli,int> llii;
typedef vector<llii> vllii;

ifstream in("input.txt");
ofstream out("output.txt");

vlli adj[MAXN];
bool occ[MAXN];
ll W;
int N, M;

void MST();

int main()
{
        in >> N >> M;
        for(int i=0, a, b, w; i<M; i++){
                in >> a;
                in >> b;
                in >> w;
                adj[a].push_back( make_pair( w,b ) );
                adj[b].push_back( make_pair( w,a ) );
        }
        out << "                                                                     \n";
        MST();
        out.seekp( 0, ios::beg );
        out << W;

        return 0;
}

void MST()
{
        priority_queue< llii, vllii, greater<llii> > coda;
        occ[ 1 ]=true;
        for(int i=0; i<adj[ 1 ].size(); i++)
                coda.push( make_pair( adj[ 1 ][ i ], 1 ) );

        int c=1;
        while( c<N ){
                llii head=coda.top();
                coda.pop();

                int x=head.first.first,
                       y=head.first.second,
                       z=head.second;

                if( !occ[ y ] ){
                        occ[ y ]=true;
                        c++;
                        out << y << ' ' << z << "\n";
                        W+=x;

                        for(int i=0; i<adj[ y ].size(); i++)
                                coda.push( make_pair( adj[ y ][ i ], y ) );
                }
        }

        return;
}
