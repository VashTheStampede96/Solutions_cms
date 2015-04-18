#include<fstream>
using namespace std;

int N, MAX = -1000;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	in >> N;
	for(int i=0; i<N; i++){
		int a; in >> a;
		MAX = (a < MAX)? MAX : a;
	}
	
	out << MAX << endl;
	
	return 0;
}
