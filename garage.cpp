#include <fstream>
#include <queue>
using namespace std;

struct PARCHEGGIO{
	int Rate;
	bool Occ;
} parcheggi[105];

int N, M, res, pesi[2005], cars[2005];

queue<int> coda;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    in >> N >> M;
    for(int i=1; i<=N; i++) in >> parcheggi[i].Rate;
    for(int i=1; i<=M; i++) in >> pesi[i];
    int car, j;
    for(int i=1; i<=2*M; i++){
    	in >> car;
    	j = 1;
    	if(car < 0){
    		parcheggi[ cars[-car] ].Occ = false;
    		if(!coda.empty()){
    			int c = coda.front();
    			coda.pop();
    			parcheggi[ cars[-car] ].Occ = true;
    			cars[c] = cars[-car];
    			res += pesi[c]*parcheggi[ cars[c] ].Rate;
    		}
    	}
    	else{
    		coda.push(car);
    		int c = coda.front();
    		while(parcheggi[j].Occ && j <= N) j++;
    		if(j <= N){
    			coda.pop();
    			parcheggi[j].Occ = true;
    			cars[c] = j;
    			res += pesi[c]*parcheggi[j].Rate;
    		}
    	}
    }
    
    out << res << endl;
    
    return 0;
}
