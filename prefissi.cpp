#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 3e4+5;

char mat[MAXN][25];
int N;

int main()
{

	ios_base::sync_with_stdio(false);
	/*
	ifstream in("input.txt");
	ofstream out("output.txt");
	*/
	cin >> N;
	for(int i=0; i<N; i++)
                cin >> mat[i];
        int ans = 0, l = strlen( mat[0] );
        bool x = true;
        for(int i=0; i<l && x; i++){
                for(int j=1; j<N && x; j++)
                        if( mat[j][i] != mat[j-1][i] )
                                x = false;
                if( x ) ++ans;
        }
        cout << ans << "\n";

	return 0;
}
