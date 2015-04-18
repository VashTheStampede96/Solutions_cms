#include <fstream>
using namespace std;

int N, conta;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    in >> N;
    while(N != 0){
    	conta += N%2;
    	N /= 2;
    }
    out << conta << endl;
    
    return 0;
}
