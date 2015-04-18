#include <fstream>
using namespace std;
const int MAXN = 1000001;

int N, n, V[2][MAXN] = {1}, I = 1;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    in >> N; n = N;
    for(int i=1; i<=N; i++) in >> V[0][i];
    while(V[1][I] != 1){
                  V[1][I] = 1; n--;
                  I = ((I + V[0][I]) % N) + 1;
                  }
    out << n << endl;
    for(int i=1; i<=N; i++) if(V[1][i] == 0) out << i << ' ';
    out << endl;
    
    return 0;
}
