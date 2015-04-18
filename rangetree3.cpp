#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=4*50005,
	  	  INF=-20000;

struct NODO{
	int lSum,
		rSum,
		tSum,
		mSum;
	
} tree[ MAXN ];

void init(int);
void update(int);
NODO query(int,int,int);
NODO merge(NODO,NODO);

int N, Q, a, b, r[2][MAXN];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d", &N);
	int pot=1;
	while(pot<N) pot*=2;
	
	for(int i=pot; i<2*pot; i++) r[0][i]=r[1][i]=i-pot+1;
	
	for(int i=pot; i<pot+N; i++){
		scanf("%d", &a);
		tree[i].lSum=tree[i].rSum=
		tree[i].tSum=tree[i].mSum=a;
	}
	
	
	N=pot;
	init(1);
	
	scanf("%d", &Q);
	for(int i=0; i<Q; i++){
		scanf("%d", &a);
		if(a){
			scanf("%d %d", &a, &b);
			printf("%d\n", query(1,a,b).mSum);
		}
		else{
			scanf("%d %d", &a, &b);
			tree[N+a-1].lSum=tree[N+a-1].mSum=
			tree[N+a-1].rSum=tree[N+a-1].tSum=b;
			update((N+a-1)/2);
		}
	}
	
	return 0;
}

NODO merge(NODO n1, NODO n2)
{
	NODO m;
	
	m.lSum=max( n1.lSum, n1.tSum+n2.lSum );
	m.rSum=max( n1.rSum+n2.tSum, n2.rSum );
	m.tSum=n1.tSum+n2.tSum;
	m.mSum=max( max( n1.mSum, n2.mSum ), n1.rSum+n2.lSum );
	
	return m;
}

void init(int index)
{
	if(index >= N) return;
	
	init(2*index);
	init(2*index+1);
	
	r[0][index]=r[0][2*index];
	r[1][index]=r[1][2*index+1];
	
	tree[index]=merge(tree[2*index],tree[2*index+1]);
	
	return;
}

void update(int index)
{
	if(index==0) return;
	
	tree[index]=merge(tree[2*index],tree[2*index+1]);
	update(index/2);
    
    return;
}

NODO query(int index, int x, int y)
{
	if(x==r[0][index] && y==r[1][index]) return tree[index];
	int med=(r[0][index]+r[1][index])/2;
	if(y<=med) return query(2*index,x,y);
	if(x>med) return query(2*index+1,x,y);
	return merge( query(2*index,x,med), query(2*index+1,med+1,y) );
}
