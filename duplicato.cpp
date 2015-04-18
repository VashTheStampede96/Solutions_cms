#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+5;

int N, pag[ 2*MAXN-1 ];

int main()
{

	//ios_base::sync_with_stdio(false);

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> N;
	N = 2*N-1;
	for(int i=0; i<N; i++)
                in >> pag[i];
        sort( pag, pag+N );

        for(int i=0; i<N-1; i+=2){
                if( pag[i]!=pag[i+1] ){
                        out << pag[i] << "\n";
                        return 0;
                }
        }

        out << pag[N-1] << "\n";

	return 0;
}
