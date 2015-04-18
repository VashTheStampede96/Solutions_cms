#include <fstream>
using namespace std;
/*
ve l'ho gia' spiegata oggi a scuola,
non sto a rispiegarvela =P
*/
const int N_MAX = 100000;

struct SERVER{
       int I, J;
       bool isArt, isCen;
       }v[N_MAX];
int N, S;

void solve(SERVER&, int);

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    in >> N >> S;
    
    for(int a=0; a<N; a++){
            int i, j;
            in >> i >> j;
            v[i].isArt = true;
            v[a].I = i; v[a].J = j;
            if(a == S) v[a].isCen = true;
            }
    for(int b=0; b<N; b++)
            if(!(v[b].isArt)) solve(v[v[b].I], v[b].J);
    int z=0;
    for(int c=0; c<N; c++)
            z+= (v[c].J <= 0)? 1 : 0;
    out << z << endl;
    
    return 0;
}

void solve(SERVER& X, int C)
{
     X.J-=C;
     if(X.isCen) return;
     solve(v[X.I],C);
}
