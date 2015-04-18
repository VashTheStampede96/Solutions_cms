#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXV = 5e7;

int N;
bool occ[ MAXV ];

int main()
{

	//ios_base::sync_with_stdio(false);

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> N;
	while( (N%10) != 0 ){
                occ[ N ] = true;
                N = ( N*( (N%10)-1 ) )/2;
                if( occ[ N ] ){
                        out << "-1\n";
                        return 0;
                }
	}

	out << N << "\n";

	return 0;
}
