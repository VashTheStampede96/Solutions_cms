#include <fstream>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int lastpos, conta, p = 1, g, N, disp[60]; //lettera - 65
char W[5005], S[5000005];

int main()
{
	in >> g >> N;
	for(int i=0; i<g; i++){
		char c;
		in >> c;
		if(disp[(int)c - 65] == 0)
						 W[p++] = c;
	    disp[(int)c - 65]++;
	}
	
	int bad = 0;
	for(int i=0; i<g; i++){
		in >> S[i];
		disp[(int)S[i] - 65]--;
		if(disp[(int)S[i] - 65] < 0) bad++;
	}
	if(bad == 0) conta++;
	for(int i=g; i<N; i++){
		if(disp[(int)S[i-g] - 65] < 0) bad--;
		disp[(int)S[i-g] - 65]++;
		in >> S[i];
		disp[(int)S[i] - 65]--;
		if(disp[(int)S[i] - 65] < 0) bad++;
		if(bad == 0) conta++;
	}
	
	out << conta << endl;
	
	return 0;
}
