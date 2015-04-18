#include <cstdio>
#include <deque>
using namespace std;

const int MAXN=2105;

int N, P;
deque<int> deck1, deck2;

void funcPROVA1();
void funcPROVA2();

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d %d", &N, &P);
	
	if(P==1) funcPROVA1();
	else funcPROVA2();
	
	return 0;
}

void funcPROVA1()
{
	for(int i=0; i<N; i++){
		for(int j=1; j<=N; j++)
				printf("%d %d ", j, (j+i)%N+1);
		printf("\n");
	}
	
	return;
}

void funcPROVA2()
{
	for(int i=1; i<=N/2; i++) deck1.push_back(i);
	for(int i=N/2+1; i<=N; i++) deck2.push_back(i);
	
	P=1;
	
	for(int j=0; j<N-1; j++){
		for(int i=0; i<N/2; i++)
				printf("%d %d ", deck1[i], deck2[i]);
		printf("\n");
		deck1.pop_front();
		deck1.push_front(deck2.front());
		deck1.push_front(P);
		deck2.pop_front();
		deck2.push_back(deck1.back());
		deck1.pop_back();
	}
	
	return;
}
