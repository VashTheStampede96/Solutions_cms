#include <fstream>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int N, conta = 1;
    in >> N;
    
    while(N != 1){
    	if(N%2 == 0) N /= 2;
    	else N = 3*N + 1;
    	conta++;
    }
    
    out << conta << endl;
    
    return 0;
}
