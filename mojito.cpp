#include <fstream>
using namespace std;

int abs(int x)
{
	return (x<0)? -x : x;
}

struct RAGAZZO{
	int x, y;
	bool isOcc;
}ragazzi[100];
struct LANCIO{
	int x, y;
}lanci[100];

int X, Y, xMojito, yMojito, N, conta;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    in >> X >> Y >> xMojito >> yMojito >> N;
    for(int i=0; i<N; i++){
    	in >> ragazzi[i].x >> ragazzi[i].y;
    	in >> lanci[i].x >> lanci[i].y;
    }
    
    while(true){
    	int k, xRag, yRag, perc = N*N+5;
    	for(int i=0; i<N; i++){
    		int newPerc = abs((ragazzi[i].x - xMojito))+abs((ragazzi[i].y - yMojito));
    		int newX = ragazzi[i].x, newY = ragazzi[i].y;
    		if(perc < newPerc) { }
    		else{
    			if(perc > newPerc){
    				perc = newPerc;
    				xRag = newX;
    				yRag = newY;
    				k = i;
    			}
    			else{
    				if(xRag < newX) { }
    				else{
    					if(xRag > newX){
    						xRag = newX;
    						yRag = newY;
    						k = i;
    					}
    					else{
    						if(yRag < newY){ }
    						else{
    							if(yRag > newY){
    								yRag = newY;
    								k = i;
    							}
    						}
    					}
    				}
    			}
    		}
    	}
    	
    	if(ragazzi[k].isOcc) break;
    	ragazzi[k].isOcc = true;
    	conta++;
    	xMojito = lanci[k].x;
    	yMojito = lanci[k].y;
    }
    
    out << conta << endl;
    
    return 0;
}
