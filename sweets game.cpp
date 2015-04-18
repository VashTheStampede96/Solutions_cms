#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int n, conta, memA[ 1 << 19 ], memB[ 1 << 19 ],
        can[105] = {
                                1, 2, 3, 4, 6, 7, 8, 9, 16, 17, 18, 24, 32, 34, 36, 48, 56, 64, 68, 96, 112, 120, 128, 136, 137, 256, 264,
                                272, 274, 384, 512, 528, 529, 544, 548, 768, 896, 1024, 1056, 1058, 1088, 1536, 1792, 1920, 2048,
                                2112, 2116, 3072, 3584, 3840, 3968, 4096, 4224, 4352, 4368, 4370, 8192, 8448, 8456, 8704, 8736, 8740,
                                12288, 16384, 16896, 16912, 16913, 17408, 17472, 24576, 28672, 32768, 33792, 33824, 33826, 34816,
                                49152, 57344, 61440, 65536, 69632, 69760, 73728, 74240, 74272, 74276, 131072, 139264, 139520,
                                139528, 147456, 148480, 148544, 196608, 262144, 278528, 279040, 279056, 279057, 294912, 296960,
                                393216, 458752
                                },
        ex[5][9] = {
                                {-1,-1,0,-1,1,-1,2,-1,-1},
                                {-1,3,-1,4,-1,5,-1,6,-1},
                                {7,-1,8,-1,9,-1,10,-1,11},
                                {-1,12,-1,13,-1,14,-1,15,-1},
                                {-1,-1,16,-1,17,-1,18,-1,-1}
                             };
char c;

int A(int);
int B(int);
bool po2(int);

int main()
{

	//ios_base::sync_with_stdio(false);
	ifstream in("input.txt");
	ofstream out("output.txt");

	memset( memA,-1,sizeof(memA) );
	memset( memB,-1,sizeof(memB) );

	for(int i=0; i<19; i++){
                in >> c;
                if( c=='O' ) n += 1 << i;
	}
	if( A(n)==0 ) out << "Karlsson\n";
	else out << "Lillebror\n";

	return 0;
}

int A(int k)
{
        if( k == 0 ) return 1;
        if( po2(k) ) return 0;
        if( memA[k] != -1 ) return memA[k];

        int ans = 1;
        for(int m=0; ans == 1 && m < 103; m++){
                if( (k&can[m]) == can[m] )
                        ans = B(k^can[m]);
        }
        return memA[k] = ans;
}

int B(int k)
{
        if( k == 0 ) return 0;
        if( po2(k) ) return 1;
        if( memB[k] != -1 ) return memB[k];

        int ans = 0;
        for(int m=0; ans == 0 && m < 103; m++){
                if( (k&can[m]) == can[m] ){
                        ans = A(k^can[m]);
                }
        }
        return memB[k] = ans;
}

bool po2(int p)
{
        for(int i=0; i<19; i++)
                if( p == 1<<i )
                        return true;
        return false;
}
