#include <cstdio>
#include <queue>
using namespace std;

int ingr[8], disp, K;
queue<int> pizze[256];

void Bake(int);

void Init()
{
	return;
}

void Order(int N, int *A)
{
	int p=0;
	for(int i=0; i<N; i++) p+=(1<<A[i]);
	
	pizze[p].push(K); K++;
	if(p==(disp&p)){
		Bake(pizze[p].front());
		pizze[p].pop();
		for(int i=0; i<N; i++){
			if(--ingr[ A[i] ]==0)
   					disp-=(1<<A[i]);
		}
	}
	
	return;
}

void Delivery(int I)
{
	int a=(1<<I);
	if(++ingr[I]==1) disp+=a;
	
	pair<int,int> p=make_pair(K+100,-1);
	for(int i=a; i<256; i++){
		if((a==(i&a)) && (i==(disp&i)) && !pizze[i].empty()){
				if(pizze[i].front()<p.first){
					p.first=pizze[i].front();
					p.second=i;
				}
		}
	}
	
	if(p.second!=-1){
		Bake(p.first);
		pizze[p.second].pop();
		for(int i=0; i<8; i++){
			if((p.second&(1<<i)) == (1<<i))
		 	    if(--ingr[i]==0)
					   disp-=(1<<i);
		}
	}
	
	return;
}

