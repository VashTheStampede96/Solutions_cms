#include <fstream>
using namespace std;

int N, P, conta, MAX, v[250005];
bool maj;

int solve(int last, int n)
{
	if(n == N){
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
	
	in >> N >> P;
	v[0] = 0;
	for(int i=1; i<=N; i++) in >> v[i];
	for(int i=1; i<=N; i++){
		maj = true;
		conta = solve(i-1, i);
		MAX = (MAX<conta)? conta : MAX;
		if(MAX >= N-i) break;
	}
	
	out << MAX << endl;
	
	return 0;
}
