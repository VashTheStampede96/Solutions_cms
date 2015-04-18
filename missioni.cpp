#include <fstream>
using namespace std;
const int MAXN = 100, G = 365;
int solve(int, int);
struct MISS{
       int d, s;
       }tab[MAXN];
int N, mem[MAXN][G];

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> N;
    for(int i=0; i<N; i++){ in >> tab[i].d >> tab[i].s; tab[i].s--; }

    out << solve(N,0) << endl;

    return 0;
}

int solve(int n, int g)
{
    if(n==0) return 0;
    if(mem[n][g] != 0) return mem[n][g];
    int k=0;
    if(g+tab[N-n].d-1 > tab[N-n].s) k = solve(n-1,g);
    else k = max(1+solve(n-1,g+tab[N-n].d), solve(n-1,g));
    return mem[n][g] = k;
}
