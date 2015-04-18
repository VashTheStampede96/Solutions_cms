#include <fstream>
#include <algorithm>
using namespace std;

int N, M, A, B, cost;

int main()
{
        ifstream in("input.txt");
        ofstream out("output.txt");

        in >> N >> M >> A >> B;
        B=min(M*A, B);

        cost=int(N/M) * B;
        N%=M;
        cost+=min(N*A, B);

        out << cost << "\n";

        return 0;
}
