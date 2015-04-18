#include <cstdio>
#include <algorithm>
using namespace std;

typedef long int ll;

ll sum, tree[100005];
int N, x, maxIndex;
struct ele{
	int num, index;
} A[100005],
  B[100005];

bool cmp(ele e1, ele e2)
{
	if(e1.num!=e2.num) return e1.num<e2.num;
	return e1.index<e2.index;
}

ll query(int idx)
{
	int sum=0;
	while(idx>0){
		sum=(sum+tree[idx])%1000000007;
		idx-=idx & (-idx);
	}
	
	return sum;
}

void update(int idx, ll value)
{
	while(idx<=maxIndex){
		tree[idx]+=value%1000000007;
		idx+=idx & (-idx);
	}
	
	return;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d",&N);
	
	for(int i=1; i<=N; i++){
		scanf("%d", &x);
		A[i].num=B[i].num=x;
		B[i].index=i;
	}
	sort(B+1,B+1+N,cmp);
	
	B[0].num=B[1].num-1;
	for(int i=1; i<=N; i++){
		if(B[i].num!=B[i-1].num) maxIndex++;
		A[B[i].index].index=maxIndex;
	}
	
	for(int i=1; i<=N; i++){
		ll z=(1+query(A[i].index-1))%1000000007;
		update(A[i].index,z);
	}
	
	printf("%ld\n", query(maxIndex));
	
	return 0;
}
