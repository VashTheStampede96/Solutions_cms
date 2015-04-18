#include <fstream>
#include <set>
using namespace std;
const int MAXN = 1e5+5;

set<int> aux;
int N, M, a[MAXN], b[MAXN];
bool occ[MAXN];

int main()
{
        ifstream cin("input.txt");
        ofstream cout("output.txt");
        cin >> N >> M;
        for(int i=1; i<=N; i++)
                cin >> a[i];

        for(int i=N; i>0; i--){
                aux.insert( a[i] );
                b[i] = aux.size();
        }

        for(int i=0, k; i<M; i++){
                cin >> k;
                cout << b[k] << "\n";
        }

        return 0;
}
