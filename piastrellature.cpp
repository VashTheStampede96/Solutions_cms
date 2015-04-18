#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

int N, v[30];

void solve(int n, int mode, int k)
{
	v[k] = mode;
	if(n >= N) return;
	if(n == N-1){
		for(int i=0; i<=k; i++){
			if(v[i] == 0) out << "[O]";
			else out << "[OOOO]";
		}
		out << endl;
		return;
	}
	solve(n+1,0,k+1);
	solve(n+2,1,k+1);
	return;
}

int main()
{
	in >> N;
	solve(0,0,0);
	solve(1,1,0);
    
    return 0;
}
