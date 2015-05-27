#include<bits/stdc++.h>
using namespace std;
const int mn = 2e5+5;
typedef pair<int,int> pii;
typedef long long ll;

ll n, segtree[4*mn], seq[mn], seq2[mn];

unordered_map<int,int> umap;

inline ll query(int idx, int l, int r, int x, int y)
{
    if( r<x || l>y ) return 0;
    if( l>=x && r<=y ) return segtree[idx];
    int mid=(l+r)/2;

    return query(2*idx,l,mid,x,y)+query(2*idx+1,mid+1,r,x,y);
}

inline ll update(int idx, int l, int r, int k)
{
    if(l==r && l==k) return segtree[idx]+=1;
    if(l>k || r<k) return segtree[idx];
    int mid=(l+r)/2;

    return segtree[idx]=update(2*idx,l,mid,k)+update(2*idx+1,mid+1,r,k);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d",&n);
	int p=1;
	while(p<n) p *= 2;
	for(int x=0; x<n; ++x){
        scanf("%d", seq+x);
        seq2[x] = seq[x];
	}
	sort(seq2,seq2+n);
	for(int x=0; x<n; ++x)
        umap[seq2[x]]=x;

    ll ans=0;
    for(int x=0; x<n; ++x){
        ans += query(1,0,p,umap[seq[x]]+1,n-1);
        update(1,0,p,umap[seq[x]]);
    }

    printf("%lld\n",ans);

	return 0;
}
