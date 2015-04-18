#include <fstream>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;

int N, M, a, b, sqrtN;
char c;
vector< deque<int> > vasi;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    in >> N >> M;
    sqrtN=sqrt(N)+1;
    vasi.resize(sqrtN);
    
    for(int i=0; i<N; i++) vasi[i/sqrtN].push_back(i);
    
    for(int i=0; i<M; i++){
    	in >> c;
    	if(c == 'c'){
    		in >> a;
    		int deck=a/sqrtN,
    			pos=a%sqrtN;
   			out << vasi[deck][pos];
		    out << ' ';
    	}
    	else{
    		in >> a; in >> b;
    		if(a==b) continue;
    		
    		int deck1=a/sqrtN,
    			deck2=b/sqrtN,
    			pos1=a%sqrtN,
    			pos2=b%sqrtN,
				val=vasi[deck1][pos1];
				
            vasi[deck1].erase(vasi[deck1].begin()+pos1);
           	
            if(a<b){
            	while(deck1<deck2){
            		vasi[deck1].push_back(vasi[deck1+1].front());
            		vasi[++deck1].pop_front();
            	}
            }
            else{
            	while(deck1>deck2){
            		vasi[deck1].push_front(vasi[deck1-1].back());
            		vasi[--deck1].pop_back();
            	}
            }
            
           	vasi[deck2].insert(vasi[deck2].begin()+pos2,val);
    	}
    }
    
    out << endl;
    return 0;
}
