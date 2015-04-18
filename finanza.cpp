#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
const int MAXN = 1e6+5;

int N, K, i, j, t, k, size_res, n[MAXN], res[MAXN];
queue<int> pos[10];

int main()
{

	//ios_base::sync_with_stdio(false);

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> N >> K; k=K;
	for(i=0; i<N; i++){
                in >> n[i];
                pos[ n[i] ].push( i );
	}

	for( i=0; i<N-K; i++ ){
                for( j=0; j<10; j++ ){
                        while( !pos[ j ].empty() && pos[ j ].front()<t )
                                pos[ j ].pop();
                        if( pos[ j ].empty() ) continue;
                        if( pos[ j ].front()<=t+k ){
                                k -= pos[ j ].front()-t;
                                t = pos[ j ].front()+1;
                                pos[ j ].pop();
                                res[ size_res++ ] = j;
                                break;
                        }
                }
	}
	for( i=0; i<size_res; i++ )
                out << res[i] << " ";
        out << "\n";

	return 0;
}
