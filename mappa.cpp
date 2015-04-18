#include <fstream>
using namespace std;

int N, map[105][105];

void solve(int, int);

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	in >> N;
	for(int i=1; i<=N; i++)
			for(int j=1; j<=N; j++){
				char c;
				in >> c;
				if(c == '+'){
					 map[i][j] = -1;
				}
			}
	map[1][1] = 1;
	solve(1,1);
	out << map[N][N] << endl;
	
	return 0;
}

void solve(int r, int c)
{
	int k=1+map[r][c];
	for(int i=-1; i<=1; i++)
			for(int j=-1; j<=1; j++){
				if(r+i == 0 || r+i == N+1 || c+j == 0 || c+j == N+1 || map[r+i][c+j] == -1 || (i == j && i == 0)) { }
				else{
					if(map[r+i][c+j] > k || map[r+i][c+j] == 0){
						map[r+i][c+j] = k;
						solve(r+i,c+j);
					}
				}
			}
	return;
}
