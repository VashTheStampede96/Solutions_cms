#include <fstream>
#include <vector>
#include <utility>
#include <cstdio>
#include <assert.h>
using namespace std;
typedef pair<int,char> ic;
typedef vector<ic> vic;
const int MAXN = 1e6+5;

int H, N;
long long ans;
char str[MAXN], h[6]="hello", w[6]="world";
vic pos;

inline bool hello(int p)
{
        for(int i=0; i<5; i++)
                if( p+i >= N || str[p+i]!=h[i] )
                        return false;
        return true;
}

inline bool world(int p)
{
        for(int i=0; i<5; i++)
                if( p+i >= N || str[p+i]!=w[i] )
                        return false;
        return true;
}

int main()
{
        FILE *in=fopen("input.txt","r");
        FILE *out=fopen("output.txt","w");

        int i=0;
        fscanf(in,"%c",str);
        while(!feof(in)){
                if(str[i]=='h')
                        pos.push_back( make_pair(i,'h') );
                if(str[i]=='w')
                        pos.push_back( make_pair(i,'w') );
                ++i;
                fscanf(in,"%c",str+i);
        }
        int l=pos.size();
        N = i;
        for(int i=0; i<l; i++){
                if( pos[i].second == 'h' ){
                        if( hello(pos[i].first) )
                                H++;
                }
                else{
                        if( world(pos[i].first) )
                                ans += H;
                }
        }

        fprintf(out,"%lld\n",ans);

        return 0;
}
