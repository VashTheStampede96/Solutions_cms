#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

int n, dice[6] = { 1,2,3,4,5,6 };
char m;

void x()
{
    int t = dice[0];
    dice[0] = dice[4];
    dice[4] = dice[5];
    dice[5] = dice[1];
    dice[1] = t;
}

void y()
{
    int t = dice[0];
    dice[0] = dice[2];
    dice[2] = dice[5];
    dice[5] = dice[3];
    dice[3] = t;
}

void z()
{
    int t = dice[1];
    dice[1] = dice[3];
    dice[3] = dice[4];
    dice[4] = dice[2];
    dice[2] = t;
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> n;
	for( int i=0; i<n; ++i ){
        in >> m;
        switch( m )
        {
            case 'X': x(); break;
            case 'Y': y(); break;
            case 'Z': z(); break;
            case 'T': out << dice[0] << " "; break;
            case 'F': out << dice[1] << " "; break;
            case 'R': out << dice[2] << " "; break;
            default: break;
        }
	}
	out << "\n";

	return 0;
}
