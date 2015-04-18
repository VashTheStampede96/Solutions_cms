#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
typedef list< ii >::iterator iter;

int N, ans;
list< ii > fish;

void eat( iter &myFish )
{
        iter x = myFish;
        advance( x,-1 );
        for( ; myFish != fish.begin(); --x ){
                if( x->second < myFish->second ) x = fish.erase( x );
                else break;
        }
        if( myFish == fish.begin() ) ans++;
        myFish = fish.erase( myFish );

        return;
}

int main()
{

	//ios_base::sync_with_stdio(false);

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> N;
	for(int i=0, d, w; i<N; i++){
                in >> d >> w;
                fish.push_back( make_pair(d,w) );
	}

	for( iter i = fish.begin(); i != fish.end(); ){
                if( i->first == 1 ) eat( i );
                else ++i;
	}

	out << ans+fish.size() << "\n";

	return 0;
}
