#include <iostream>
#include <cstdio>
using namespace std;

char convert(char c)
{
        if( c >= 'A' && c <= 'Z' )
                return char( int(c)+int('a'-'A') );
        if( c >= 'a' && c <= 'z' )
                return char( int(c)-int('a'-'A') );
        return c;
}

int main()
{
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);

        int N;
        char c;

        cin >> N;
        getchar_unlocked();

        for(int i=0; i<N; i++){
                c=getchar_unlocked();
                cout << convert(c);
        }

        cout << "\n";

        return 0;
}
