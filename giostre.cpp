#include <fstream>
using namespace std;

int conta, contaPrimo;
bool V[32005];

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int A, B, i = 0, j = 0;
    in >> A >> B;
    
    while(!V[i]){
    	V[i] = true;
    	conta++; j++;
    	i = (B*j)%A;
    }
    
    int bPrimo = 20;
    while(contaPrimo != A){
    	contaPrimo = 0;
    	bPrimo++;
    	i = j = 0;
    	for(int k=0; k<A; k++) V[k] = false;
    	while(!V[i]){
    		V[i] = true;
    		contaPrimo++; j++;
    		i = (bPrimo*j)%A;
    	}
    }
    
    out << conta << ' ' << bPrimo << endl;
    
    return 0;
}
