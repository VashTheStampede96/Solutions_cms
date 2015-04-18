#include <fstream>
#include <algorithm>
using namespace std;

int N, V[100000], MAX = -1;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	in >> N;
	for(int i=0; i<N; i++) in >> V[i];
	sort(V,V+N);
	for(int i=N-1; i>=0; i--)
			for(int j=i-1; j>=0; j--){
				int k = V[i]+V[j];
				if(k%2 == 0 && k > MAX) MAX = k;
				if(k < MAX) break;
			}
	out << MAX << endl;
	
	return 0;
}
