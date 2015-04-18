#include <fstream>
#include <algorithm>
using namespace std;
const int MAXN = 1e4+5;

int N, K, ans=1e9, lista[MAXN];

int main()
{
        ifstream in("input.txt");
        ofstream out("output.txt");

        in >> N >> K;
        for(int i=0; i<N; i++)
                in >> lista[i];
        sort( lista, lista+N );

        for(int i=0; i<=N-K; i++)
                ans = min( ans, lista[i+K-1]-lista[i] );

        out << ans << "\n";

        return 0;
}
