#include<fstream>
using namespace std;

int solve(int N, int K, int* S)
{
	int a = -1, b = N, straw = 0;
	
	//Mangio da SX finche' riesco
	while(K-S[a+1] >= 0 && a+1 != N){
		a++;
		if(S[a] == 0) straw++;
		K-=S[a];
	}
	
	//Mangio da DX finche' riesco
	while(K-S[b-1] >= 0 && b-1 != -1 && b-1 > a){
		b--;
		if(S[b] == 0) straw++;
		K-=S[b];
	}
	
	//Prendo come risultato migliore le fragole mangiate fino ad ora
	int maxStraw = straw;
	
	while(a != -1){
		//Sputo le fragole fino al primo frutto cattivo
		while(S[a] == 0 && a != -1){
			a--;
			straw--;
		}
		//Sputo il frutto cattivo
		if(a == -1) {}
		else{ K+=S[a]; a--; }
		
		//Mangio da DX finche' riesco
		while(K-S[b-1] >= 0 && b-1 != -1 && b-1 > a){
			b--;
			K-=S[b];
			if(S[b] == 0) straw++;
		}
		
		//Aggiorno il massimo e ripeto
		if(maxStraw < straw) maxStraw = straw;
	}
	
	//Ritorno il massimo
	return maxStraw;
}
