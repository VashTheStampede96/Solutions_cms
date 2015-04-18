#include <fstream>
#include <algorithm>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
int n, j=1, m, h, v[100005];

int main()
{
    in>>n;
    for(int i=0; i<n; ++i){
       in>>h;
       if( h==m )
         v[j++]=i;
       if( h>m ){
         j=1;
         v[j++]=i;
         m=h;
        }
     }
     v[j]=n-1;
     int ans=0;
     for( int i=1; i<j; ++i )
         ans=max(ans,v[i+1]-v[i-1]+1);
     out<<ans<<"\n";
     return 0;
}
