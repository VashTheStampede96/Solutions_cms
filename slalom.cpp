#include <vector>
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
const int MAXN=400005;

vector<int> tree[MAXN];
int N, P, costi[MAXN], mem[MAXN][2];
bool sol[MAXN][2], occ[MAXN];

//0 scelta libera
//1 scelta obbligata
int solve(int v, int p, int f)
{
	if(mem[v][p]!=-1) return mem[v][p];
	
	if(tree[v].size()==1 && tree[v][0]==f){
		mem[v][p]=(p)? costi[v]:0;
		sol[v][p]=mem[v][p];
		return mem[v][p];
	}
	
	int ans1=costi[v], ans2=0;
	
	for(int i=0; i<tree[v].size(); i++)
			if(tree[v][i]!=f) ans1+=solve(tree[v][i],0,v);
	
	if(p==1){
		sol[v][p]=1;
		return mem[v][p]=ans1;
	}
	
	for(int i=0; i<tree[v].size(); i++)
			if(tree[v][i]!=f) ans2+=solve(tree[v][i],1,v);
			
	if(ans1>ans2) sol[v][p]=0;
	else sol[v][p]=1;
	
	return mem[v][p]=min(ans1,ans2);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	for(int i=0; i<MAXN; i++)
			mem[i][0]=mem[i][1]=-1;
	
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", costi+i);
	for(int i=0, a, b; i<N-1; i++){
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	solve(1,0,-1);
	
	printf("                           \n");
	
	queue< pair<int,int> > coda; 
	coda.push( make_pair(1,0) );
	
	while(!coda.empty()){
		int p;
		pair<int,int> c=coda.front();
		occ[c.first]=true;
		coda.pop();
		if(sol[c.first][c.second]){
			printf("%d ", c.first);
			P++;
			p=0;
		}
		else p=1;
		for(int i=0; i<tree[c.first].size(); i++)
				if(!occ[ tree[c.first][i] ]) coda.push( make_pair(tree[c.first][i],p));
	}
	
	printf("\n");
	cout.seekp(ios_base::beg);
	printf("%d", P);
	
	return 0;
}
