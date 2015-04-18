#include <cstdio>
const int MAXM=1005;

int N, M, S[MAXM], mem[MAXM][MAXM], nS[2][MAXM];

int solve(int,int);

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	for(int i=0; i<MAXM; i++)
			for(int j=0; j<MAXM; j++)
					mem[i][j]=-1;
	for(int i=0; i<2; i++)
			for(int j=0; j<MAXM; j++)
					nS[i][j]=-1;
	
	scanf("%d %d\n", &M, &N);
	
	char c;
	for(int i=1; i<=M; i++){
		scanf("%c", &c);
		S[i]=(c=='0')? 0:1;
	}
	
	printf("%d\n", solve(0,0));
	
	return 0;
}

int solve(int n, int s)
{
	if(mem[n][s]!=-1) return mem[n][s];
	if(s==M) return mem[n][s]=0;
	if(n==N) return mem[n][s]=1;
	
	//Estendo il matching
	int a=solve(n+1,s+1);
	
	//Annullo il matching corrente calcolando quello nuovo
	int nuovaLettera=(S[s+1]==1)? 0:1, i, nuovaS;
	bool found=false;
	
	if(nS[nuovaLettera][s]<0){
		for(nuovaS=s; nuovaS>0 && !found; nuovaS--)
			if(S[nuovaS]==nuovaLettera){
				found=true;
				for(int i=1; i<nuovaS && found; i++)
					if(S[s+1-i]!=S[nuovaS-i]) found=false;
			}
		
		if(found) nuovaS++;
		nS[nuovaLettera][s]=nuovaS;
	}
	
	int b=solve(n+1,nS[nuovaLettera][s]);
	
	return mem[n][s]=(a+b)%2011;
}
