#include <fstream>
using namespace std;
const int MAXN = 25, MAXM = 200005, mod = 1e9 +7;
typedef long long ll;

ifstream in("input.txt");
ofstream out("output.txt");

ll mem[MAXN][MAXM], memSum[MAXN][MAXM];
int N, M;

ll solve(int,int);
ll sum(int,int);

int main()
{
        in >> N >> M;

        ll ans = 0;
        for(int i=1; i<=M; i++){
                ans += solve(1,i);
                ans %= mod;
        }

        out << ans << "\n";

        return 0;
}

ll solve(int n, int l)
{
        if(n == N) return 1;
        if(mem[n][l] != 0) return mem[n][l];
        return mem[n][l] = sum(n+1,2*l)%mod;
}

ll sum(int n, int l)
{
        if(l > M) return 0;
        if(memSum[n][l] != 0) return memSum[n][l];
        return memSum[n][l] = (solve(n, l) + sum(n, l+1)%mod)%mod;
}
