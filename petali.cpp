#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int j=1, di[300];
vector<int>  m[300];
vector<bool> pos[300];

int solve(int N, int *S)
{
	int dim=(int)sqrt(N);

	di[0]=j;
	for(int i=2; i<=dim; i++)
			if(N%i==0){
				di[j++]=i;
				di[j++]=N/i;
			}
	sort(di,di+j);
	for(int i=0; i<j; i++) pos[i].resize( di[i]+1 );

	for(int i=0; i<j; i++)
                for(int z=i+1; z<j; z++)
                        if(di[z]%di[i]==0)
                                m[i].push_back(z);

        int ans=0, n, i, k, z, w;

        for(i=0; i<j; i++){
                if( !( di[i]==dim && di[i+1]==dim) ){
                        for(k=0; k<di[i]; k++){
                                        if(pos[i][k]) ans++;
                                        else{
                                                n=0;
                                                while( S[ (k+di[i]*n)%N ]==S[ (k+di[i]*(n+1) )%N ] && k+di[i]*n<N) n++;
                                                if( k+di[i]*n>=N ){
                                                        ans++;
                                                        for(z=0; z<m[i].size(); z++)
                                                                for(w=0; w+k< pos[ m[i][z] ].size(); w+=di[i])
                                                                        pos[ m[i][z] ][w+k]=true;
                                                }
                                        }
                        }
                }
        }

	return ans;
}
