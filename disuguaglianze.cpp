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

int n, m, M;
char c;

int main()
{
    in >> n;
    m=1; M=n;
    for( int i=0; i<n; ++i ){
        in >> c;
        if( c=='<' ){
            out << m << " ";
            ++m;
        }
        else{
            out << M << " ";
            --M;
        }
    }

    out << "\n";

	return 0;
}
