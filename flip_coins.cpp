#include<fstream>
using namespace std;

int query(int,int,int,int);
int update(int,int,int,int);

const int MAXN=500000;

struct SegmentNode{
        bool flag;
        int heads, flips;
} tree[MAXN];

int N, Q, a, b, t;

int main()
{
        ifstream in("input.txt");
        ofstream out("output.txt");

        in >> N >> Q;
        for(int i=0; i<Q; i++){
                        in >> t;
                        in >> a;
                        in >> b;
                        if(t) out << query(1,0,N-1,0) << "\n";
                        else update(1,0,N-1,0);
        }

        return 0;
}

int query(int n, int x, int y, int f)
{
        if( x>b || y<a ) return 0;

        if( x>=a && y<=b ) return ( (tree[n].flips+f)%2 )? (y-x+1)-tree[n].heads : tree[n].heads;

        int mid = (x+y)/2, v=f+tree[n].flips;
        return query(2*n, x, mid, v)+query(2*n+1, mid+1, y, v);
}

int update(int n, int x, int y, int f)
{
        if( x>b || y<a ){
                tree[n].flips += f;
                return tree[n].heads;
        }

        if( x>=a && y<=b ){
                f++;
                tree[n].flips += f;
                return tree[n].heads = ( (tree[n].flips+f)%2 )? (y-x+1)-tree[n].heads : tree[n].heads;
        }

        int mid = (x+y)/2, v=f+tree[n].flips;
        tree[n].flips = 0;
        tree[n].heads = update(2*n, x, mid, v)+update(2*n+1, mid+1, y, v);
}
