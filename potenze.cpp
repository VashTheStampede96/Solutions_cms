#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int N, MAX, sqrtN;

int main()
{

	//ios_base::sync_with_stdio(false);

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> N;
	if( N<=3 ) MAX = 1;
	else{
	        sqrtN = sqrt(N);
                for(int x=2; x<=sqrtN; x++){
                        int X=x;
                        while( X*x<=N ) X *= x;
                        MAX = max( MAX, X );
                }
	}

	out << MAX << "\n";

	return 0;
}
