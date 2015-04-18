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
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int intoo = 1e9;
const ll longoo = 1e18;

int n, lastb, sizeb[105], buck[105], num[10], num2[10];
string dic[105];

ifstream in("input.txt");
ofstream out("output.txt");

void solve( int s )
{
    bool found = false;

    for( int x=0; x<10; ++x )
        num[x] = num2[x] = 0;
    for( auto x : dic[s] )
        ++num[ x - '0' ];

    for( int x = 0; x<s && !found; ++x ){
        for( auto y : dic[x] )
            ++num2[ y - '0' ];
        int y;
        found = true;
        for( y=0; y<10 && found; ++y )
            if( num[y] != num2[y] )
                found = false;
        if( found ){
            buck[s] = buck[x];
            ++sizeb[ buck[s] ];
        }

        for( int w=0; w<10; ++w )
            num2[w] = 0;
    }

    if( !found ){
        buck[s] = lastb++;
        ++sizeb[ buck[s] ];
    }
}

void print()
{
    for( int x=0; x<n; ++x )
        out << dic[x][ sizeb[ buck[x] ] - 1 ];
    out << "\n";
}

int main()
{
	in >> n;
	for( int x=0; x<n; ++x ){
        in >> dic[x];
        solve(x);
	}
	print();

	return 0;
}
