#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

    scanf("%d",&n);
    v.resize(n);
    for(int x=0; x<n; ++x)
        scanf("%d",&v[x]);
    sort(v.begin(),v.end());

    int k=2;
    long long ans=0;
    for(int x=0; x<n-2; ++x, k=x+2)
        for(int y=x+1; y<n-1; ++y){
            while(k<n && v[x]+v[y]>=v[k]) ++k;
            ans+=n-k;
        }

    printf("%lld\n",ans);

	return 0;
}
