#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

int N;
char c;
stack<char> pila;

inline bool open( char x )
{
        if( x=='<' || x=='(' || x=='[' || x=='{' ) return true;
        return false;
}

inline bool close( char x, char y )
{
        if( (x=='<' && y=='>') ||
              (x=='(' && y==')') ||
              (x=='[' && y==']') ||
              (x=='{' && y=='}')
            ) return true;
        return false;
}

int main()
{

	//ios_base::sync_with_stdio(false);

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> N;
	for(int i=0; i<N; i++){
                in >> c;
                if( open( c ) ) pila.push( c );
                else{
                        if( !pila.empty() && close( pila.top(),c ) ) pila.pop();
                        else{
                                out << "malformata\n";
                                return 0;
                        }
                }
	}

	if( pila.empty() ) out << "corretta\n";
	else out << "malformata\n";

	return 0;
}
