#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1000005;

int N, index, index2=1, best;
char maxChar, S[MAXN];
bool control;

int main()
{
    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);

    scanf("%d",&N);
    scanf("%c",&maxChar);
    S[0]=maxChar;

    for(int i=1; i<N; i++){
    	scanf("%c", S+i);
    	S[++index]=S[i];
    	if(S[i]>maxChar){
    		best=i;
    		index=0;
    		index2=1;
    		S[index]=maxChar=S[i];
    		control=false;
    	}
    	if(control){
    		if(S[i]<S[index2]){
    			index2=1;
    			control=false;
    		}
    		else{
    			if(S[i]==S[index2]) index2++;
    			else{
    				S[index2]=S[i];
    				best=i-index2;
    				index=index2;
    				index2=1;
    				control=false;
    			}
    		}

    	}
    	if(S[i]==maxChar && best != i) control=true;
    }

    printf("%d\n",best);

    return 0;
}
