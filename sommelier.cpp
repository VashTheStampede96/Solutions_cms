#include <fstream>
using namespace std;

int N, wines[1000], mem[1000][1000];

int solve(int n, int grad)
{
	if(n >= N) return 0;
	if(mem[n][grad] != 0) return mem[n][grad];
	int k;
	if(wines[n] >= grad) k = max( 1+solve(n+2,wines[n]), solve(n+1,grad) );
	else k = solve(n+1, grad);
	
	return mem[n][grad] = k;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    in >> N;
    for(int i=0; i<N; i++) in >> wines[i];
    
    out << max( 1+solve(2,wines[0]), solve(1,0) ) << endl;
    
    return 0;
}
