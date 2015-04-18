#include <vector>
using namespace std;
const int MAXN=100005;

int colorCubes[MAXN];
bool colorUsed[MAXN];
int Color=1, size_C;

void Vernicia(int indice, int colore);

int getColor()
{
        while( colorUsed[ Color ] ) Color++;
        colorUsed[ Color ]=true;

        return Color;
}

void Diversifica(int N, int colore[])
{
        for(int i=0; i<N; i++){
                if( colorUsed[ colore[i] ] ) colorCubes[ size_C++ ]=i;
                else colorUsed[ colore[i] ]=true;
        }

        for(int i=0; i<size_C; i++)
                Vernicia( colorCubes[i], getColor() );

        return;
}
