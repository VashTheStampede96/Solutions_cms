#include <fstream>
using namespace std;

int N, MAX = -1;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	in >> N;
	for(int i=0; i<N; i++){
		int a, b;
		in >> a >> b;
		a += b;
		if(a%2 == 0 && a > MAX) MAX = a;
	}
	
	out << MAX << endl;
	
	return 0;
}
