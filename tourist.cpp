#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

//bool cmp(const int &a, const int &b){ return a<b; }

priority_queue<int,vector<int>,greater<int>> pq;

int GreatestHappiness(int,int,int*);
/*
int n, k, h[1000000];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d %d", &n, &k);
	
	for(int i=0; i<n; i++) scanf("%d", h+i);
	
	printf("%d\n", GreatestHappiness(n,k,h));
	
	return 0;
}*/

int GreatestHappiness(int N, int K, int *H)
{
	K++;
	
	int maxHappiness=0, happiness=0;
	
	for(int i=0; i<N; i++){
		K--;
		if(K<0){
			if(pq.empty()) return maxHappiness;
			K++;
			happiness-=pq.top();
			pq.pop();
		}
		
		K--;
		if(K<0){
			if(pq.empty()) return maxHappiness;
			K++;
			happiness-=pq.top();
			pq.pop();
		}
		
		happiness+=H[i];
		pq.push(H[i]);
		
		maxHappiness=max(maxHappiness,happiness);
	}
	
	return maxHappiness;
}
