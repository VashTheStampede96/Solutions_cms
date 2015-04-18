#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	long long a, b;
	cin >> a >> b;
	cout << int( floor( sqrt(b) ) ) - int( ceil( sqrt(a) ) ) + 1 << "\n";

	return 0;
}
