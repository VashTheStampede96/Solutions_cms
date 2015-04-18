#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e4+5;

int N, C, last = 1e6, ans;

int main()
{

	//ios_base::sync_with_stdio(false);

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> N;
	for(int i=0; i<N; i++){
                in >> C;
                last = min( last+1, C );
                ans += last;
	}

	out << ans << "\n";

	return 0;
}
