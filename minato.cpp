#include <fstream>
using namespace std;

int N, M, map[102][102];

int solve(int r, int c)
{
	if(r == N+1 || c == M+1) return 0;
	if(r == N && c == M) return 1;
	if(map[r][c] == -1) return 0;
	if(map[r][c] != 0) return map[r][c];
	return map[r][c] = solve(r,c+1) + solve(r+1,c);
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	in >> N >> M;
	for(int i=1; i<=N; i++)
			for(int j=1; j<=M; j++){
				char c; in >> c;
				if(c == '+') map[i][j] = -1;
			}
	out << solve(1,1) << endl;
	
	return 0;
}
