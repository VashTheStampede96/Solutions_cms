#include <fstream>
#include <vector>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int N, n;
vector<int> v;

void solve(int k)
{
	if(k < 0) return;
	if(k == 0){
		for(int i=0; i<v.size(); i++) out << v[i] << ' ';
		out << endl;
		return;
	}
	for(int i=1; i<=v[v.size()-1]; i++){
		v.push_back(i);
		solve(k-i);
		v.pop_back();
	}
	
	return;
}

int main()
{
    in >> N;
    for(int i=1; i<=N; i++){
    	v.push_back(i);
    	solve(N-i);
    	v.pop_back();
    }
    
    return 0;
}
