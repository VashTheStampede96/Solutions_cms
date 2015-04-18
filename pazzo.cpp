#include <fstream>
using namespace std;

int N, M, server = 0;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	in >> N >> M;
	for(int i=0; i<M; i++){
		int a, b;
		in >> a;
		in >> b;
		if(a == server) server = b;
		else if(b == server) server = a;
	}
	
	out << server << endl;
	
	return 0;
}
