#include <fstream>
#include <algorithm>
using namespace std;

int M, N, D, V[100000];
long long int profit = 0;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	in >> N;
	in >> D;
	for(int i=0; i<N; i++) in >> V[i];
	in >> M;
	sort(V,V+N);
	for(int i=0; i<M; i++){
		if(i == N) break;
		profit += V[i];
	}
	if(M > N) for(int i=0; i<M-N; i++) profit -= D;
	out << profit << endl;
	
	return 0;
}
