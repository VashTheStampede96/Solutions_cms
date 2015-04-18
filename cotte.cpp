#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXC=5000005, MAXM=1000005;

int M, F, C, size_c, size_LIS=1, c[MAXC], LIS[MAXC];
bool occ[MAXM];
vector<int> adj[MAXM];

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> M >> F >> C;
	for(int i=0, a, b; i<C; i++){
		in >> a; in >> b;
		adj[a].push_back(b);
	}

	for(int i=1; i<=M; i++){
		sort(adj[i].begin(), adj[i].end(), greater<int>());
		for(int j=0; j<adj[i].size(); j++)
			if(!occ[ adj[i][j] ]){
				occ[ adj[i][j] ]=true;
				c[size_c++]=adj[i][j];
			}
	}

	for(int i=0; i<size_c; i++){
		int pos=lower_bound(LIS,LIS+size_LIS,c[i])-LIS;
		LIS[pos]=c[i];
		if(pos==size_LIS) size_LIS++;
	}

	out << 2*(size_LIS-1) << "\n";

	return 0;
}
