#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int sx, dx, N;
char c;

int main()
{

	//ios_base::sync_with_stdio(false);

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> N;
	N >>= 2;
	for(int i=0; i<N; i++){
                in >> c >> c;
                if( c=='+' ) sx++;
                else dx++;
                in >> c >> c;
	}
	out << min( sx,dx ) << "\n";

	return 0;
}
