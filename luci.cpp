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
#include <cmath>
#define pb(x) push_back(x)
#define FOR(i,n) for(;i<n;++i)
#define mod(x) (x<0)? -x:x
#define f first
#define s second
#define INF 1e9

using namespace std;

int n;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> n;
	out << n-floor( sqrt(n) ) << "\n";

	return 0;
}
