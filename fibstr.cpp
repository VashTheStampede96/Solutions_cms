#include <fstream>
#include <string>
#include <utility>
using namespace std;

int N, fibSequence[32]={1,1};
string S;
pair<int,int> resTemp=make_pair(0,0), resAbs=make_pair(0,0);

int main()
{
 	ifstream in("input.txt");
 	ofstream out("output.txt");
    
    for(int i=2; i<32; i++)
			fibSequence[i]=fibSequence[i-1]+fibSequence[i-2];
    
    in >> N >> S;
    
    for(int i=1; i<N; i++){
    	if(S[i-1]==S[i]) continue;
    	int n=2, l=2;
    	string next, comp, prec;
    	prec=S[i-1];
    	next=prec;
		next+=S[i];
    	do{
    		resTemp=make_pair(i,l-1);
    		string x=next;
    		next+=prec;
    		prec=x;
    		l=fibSequence[++n];
    		comp=S.substr(i-1,l);
    	}while(next.compare(comp)==0);
    	
    	if(resTemp.second>resAbs.second) resAbs=resTemp;
    }
    
    out << resAbs.first << ' ' << resAbs.first+resAbs.second << endl;
    
    return 0;
}
