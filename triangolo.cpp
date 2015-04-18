#include <fstream>
using namespace std;

int N, mat[100][100];

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    in >> N;
    for(int i=0; i<N; i++)
    		for(int j=0; j<i+1; j++)
    				in >> mat[i][j];
    for(int i=N-2; i>=0; i--)
    		for(int j=0; j<i+1; j++)
    				mat[i][j] += max(mat[i+1][j], mat[i+1][j+1]);
    out << mat[0][0] << endl;
    
    return 0;
}
