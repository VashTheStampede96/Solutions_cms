#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;

vector<string> dic;
unordered_map<string,vector<string>> s1, s2;
int n, m;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> n >> m;
    string mi, de;

    for( int x=0; x<n; ++x ){
        in >> mi >> de;
        s1[mi].push_back(de);
        s2[de].push_back(mi);
    }

    for( int x=0; x<m; ++x ){
        in >> mi >> de;
        if( de.compare("INVIATI")==0 ){
            out << s1[mi].size() << " ";
            for( auto y : s1[mi] )
                out << y << " ";
            out << "\n";
        }
        else{
            out << s2[mi].size() << " ";
            for( auto y : s2[mi] )
                out << y << " ";
            out << "\n";
        }
    }

    return 0;
}
