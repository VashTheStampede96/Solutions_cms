#include <fstream>
using namespace std;

int N, conta1, conta2, MAX, v[100000];
bool maj;

int solve(int last, int n)
{
	if(n == N-1){
		if(maj && v[n]>v[last]) return 1;
		if(!maj && v[n]<v[last]) return 1;
		return 0;
	}
	if(maj && v[n]>v[last] && v[n+1]<v[n]){
		maj = false;
		return 1+solve(n, n+1);
	}
	if(!maj && v[n]<v[last] && v[n+1]>v[n]){
		maj = true;
		return 1+solve(n, n+1);
	}
	return solve(last, n+1);
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	in >> N;
	for(int i=0; i<N; i++) in >> v[i];
	for(int i=0; i<N; i++){
		maj = true;
		conta1 = 1+solve(i, i+1);
		maj = false;
		conta2 = 1+solve(i, i+1);
		int pseudoMAX = max(conta1, conta2);
		MAX = (MAX<pseudoMAX)? pseudoMAX : MAX;
		if(MAX == N-i) break;
	}
	
	out << MAX << endl;
	
	return 0;
}
