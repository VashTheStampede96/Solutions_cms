#include <cstdio>
#include <algorithm>
#include <limits>
#include <stack>
using namespace std;

struct POINT{
	int pos;
	long int x, y;
}pts[1000005];

int N;
FILE *in, *out;
bool cmp(const POINT& p1, const POINT& p2)
{
    if(p1.x!=p2.x) return p1.x<p2.x;
    return p1.y>p2.y;
}

bool F(POINT A, POINT B, POINT C)
{
    return ((C.y-A.y)*(B.x-A.x)-(C.x-A.x)*(B.y-A.y))>0;
}

int solve()
{
    stack<POINT> pilaL, pilaU;
    
    for(int i=0; i<N; i++){
            POINT r=pts[i];
            if(pilaL.size()<2) pilaL.push(r);
            else{
            	POINT a, b;
            	b=pilaL.top(); pilaL.pop();
            	a=pilaL.top();
            	while(pilaL.size()>1 && !F(a,b,r)){
            		b=a; pilaL.pop(); a=pilaL.top();
            	}
            	if(F(a,b,r)) pilaL.push(b);
            	pilaL.push(r);
     		 }
        }
    
    for(int i=N-1; i>=0; i--){
            POINT r=pts[i];
            if(pilaU.size()<2) pilaU.push(r);
            else{
            	POINT a, b;
            	b=pilaU.top(); pilaU.pop();
            	a=pilaU.top();
            	while(pilaU.size()>1 && !F(a,b,r)){
            		b=a; pilaU.pop(); a=pilaU.top();
            	}
            	if(F(a,b,r)) pilaU.push(b);
            	pilaU.push(r);
            }
          }
    
    return pilaL.size()+pilaU.size()-2;
}

int main()
{
    in=fopen("input.txt","r");
    out=fopen("output.txt","w");
    
    fscanf(in,"%d",&N);
    for(int i=0; i<N; i++)
    	fscanf(in,"%ld %ld",&pts[i].x,&pts[i].y);
    sort(pts,pts+N,cmp);
    
    fprintf(out,"%d\n",solve());
    
    return 0;
}
