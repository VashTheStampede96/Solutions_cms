#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, spec[9];

int riflesso(int k)
{
        int i=0, ans = 0, esp = 1;
        while( k>0 ){
                spec[i++] = k%10;
                k /= 10;
        }

        for(int j=1; j<i; j++) esp *= 10;
        for(int j=0; j<i; j++){
                ans += spec[j]*esp;
                esp /= 10;
        }

        return ans;
}

int main()
{

	//ios_base::sync_with_stdio(false);

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> N;
	M = riflesso(N);

	out << M+N << "\n";

	return 0;
}
