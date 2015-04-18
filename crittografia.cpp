#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

const int N_max = 11,
          L_max = 200001;
char stringa[L_max],
     mappa[N_max];

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int N, L;
    in >> N >> L >> stringa;
    
	for (int i = 0; i < (L/2); i++) {
		if (isdigit(stringa[i])) {
			if (isdigit(stringa[L-1-i])) {
                out << "impossibile" << endl;
                return 0;
			}
			if (mappa[(int)stringa[i]-48] != 0 &&
				mappa[(int)stringa[i]-48] != stringa[L-1-i]) {
				out << "impossibile" << endl;
				return 0;
			}
			else 
				mappa[(int)stringa[i]-48]=stringa[L-1-i];
		}
		else
			if(isdigit(stringa[L-1-i])){
				if(mappa[(int)stringa[L-1-i]-48] != 0 &&
			       mappa[(int)stringa[L-1-i]-48] != stringa[i]){
			       	out << "impossibile" << endl;
			       	return 0;
			       }
                else
                	mappa[(int)stringa[L-1-i]-48] = stringa[i];
			}
		}
    
    
	if(strlen(mappa) == N) out << mappa << endl;
	else out << "impossibile" << endl;
	
    return 0;
}
