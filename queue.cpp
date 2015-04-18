#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct PLACE{
	int i, j;
	float d;
}p;
vector<PLACE> v;
int N, K, vi, vj;
char a, field[5005][5005];

bool cmp(PLACE, PLACE);

int main()
{
	ifstream in("input_009.txt");
	ofstream out("output_009.txt");
	
	in >> N >> K;
	for(int i=0; i<N; i++)
			for(int j=0; j<N; j++){
				in >> a;
				field[i][j]=a;
				if(a == 'O'){
					vi=i; vj=j;
				}
				if(a == '-'){
					p.i=i;
					p.j=j;
					v.push_back(p);
				}
			}
	for(int i=0; i<v.size(); i++){
		v[i].d=(float)sqrt(pow(vi-v[i].i,2)+pow(vj-v[i].j,2));
	}
	
	sort(v.begin(),v.end(),cmp);
	
	for(int i=0; i<K; i++)
			field[ v[i].i ][ v[i].j ] = 'X';
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
				out << field[i][j];
		out << endl;
	}
	
	return 0;
}

bool cmp(PLACE a, PLACE b)
{
	return a.d<b.d;
}
