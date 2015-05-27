#include<bits/stdc++.h>
using namespace std;
const int mn = 1e5+5;
typedef pair<int,int> pii;

struct info{
    int mlat, mper;

    info(){}
    info(int a, int b)
    : mlat(a), mper(b) {}
};

int n;
vector<pii> adj[mn];

info solve(int no, int pr)
{
    info temp;
    int maxd1=0, maxd2=0, maxsol=0;

    for(auto x : adj[no]){
        if(x.first==pr) continue;
        temp = solve(x.first,no);
        maxsol=max(maxsol,temp.mlat);
        if(maxd1<=temp.mper+x.second){
            maxd2=maxd1;
            maxd1=temp.mper+x.second;
        }
        else{
            if(maxd2<temp.mper+x.second)
                maxd2=temp.mper+x.second;
        }
    }

    return info(max(maxsol,maxd1+maxd2),maxd1);
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> n;
	for(int x=0, a, b, w; x<n-1; ++x){
        in >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
	}

	out << solve(1,0).mlat << "\n";

	return 0;
}
