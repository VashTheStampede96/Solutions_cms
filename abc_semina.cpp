#include<bits/stdc++.h>
using namespace std;
const int off=100;

int n, ans, m[205][205];

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> n;
	for(int w=0, x1, x2, y1, y2; w<n; ++w){
		in >> x1 >> y1 >> x2 >> y2;
		swap(y1,y2);
		int sub=0;
		for(int x=x1; x<x2; ++x)
			for(int y=y1; y<y2; ++y){
				++m[x+off][y+off];
				sub=max(sub,m[x+off][y+off]);
			}
		ans=max(ans,sub);
	}
	out << ans << "\n";

	return 0;
}
