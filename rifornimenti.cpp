#include <fstream>
using namespace std;

int rifornimenti(int N, int M, int K, int D[])
{
        int n=0, last=0;

        for(int i=0, j; i<N; i++){
                if( last+M >= K ) break;
                for(j=i; j<N; j++)
                        if( D[j]-last>M )
                                break;
                last=D[j-1];
                i=j-1;
                n++;
        }

        return n;
}

int n, m, k, d[100005];

int main()
{
        ifstream in("input.txt");
        ofstream out("output.txt");

        in >> n >> m >> k;
        if( n == m && n == k && n == 0 ) out << "1\n";
        else{
                for(int i=0; i<n; i++)
                in >> d[i];

                out << rifornimenti(n,m,k,d) << "\n";
        }

        return 0;
}
