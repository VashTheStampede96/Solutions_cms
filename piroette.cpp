#include<fstream>
#include<algorithm>
using namespace std;

int N, v[100005];

int main()
{
     ifstream in("input.txt");
     ofstream out("output.txt");

     in >> N;
     for(int i=0; i<N; i++)
         in >> v[i];

     sort( v, v+N, greater<int>() );

     int i=N-2, j=i-1;
     if( v[i]%2!=0 ){
           while( v[j]%2!=0 ) j--;
           swap( v[i],v[j] );
           sort( v+j, v+i, greater<int>() );
      }

     for(i=0; i<N; i++)
          out << v[i] << " ";
     out << "\n";

     return 0;
}
