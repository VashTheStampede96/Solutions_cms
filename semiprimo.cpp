#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <list>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int intoo = 1e9;
const ll longoo = 1e18;

ifstream in("input.txt");
ofstream out("output.txt");

int n, sqrtN;
vector<int> primi;

int main()
{
    in >> n;
    sqrtN = sqrt(n);

    for( int i=2; i<=sqrtN; ++i )
        if( n%i == 0 ){
            primi.push_back( i );
            primi.push_back( n/i );
        }

    if( primi.size() == 2 )
        out << primi[0] << " " << primi[1] << "\n";
    else out << "-1\n";

	return 0;
}
