#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;

struct bug{
	int n, v;

	bug(){}
	bug(int a, int b)
	: n(a), v(b) {}

	bool operator< (const bug& b) const { return v>b.v; };
};

struct stu{
	int n, p, a;

	stu(){}
	stu(int a, int b, int c)
	: n(a), p(b), a(c) {}

	bool operator< (const stu& s) const { return a>s.a; }
};

vector<bug> bugs;
vector<stu> stus;
int n, m, p, sol[maxn];

bool solve(int t)
{
	priority_queue< pair<int,int> > pq;
	int w=p;
	for(int x=0, l=0; x<m; x+=t){
		while(l<n && stus[l].a>=bugs[x].v){
			pq.push({-stus[l].p,stus[l].n});
			++l;
		}
		if(pq.empty()) return false;
		w += pq.top().first;
		if(w<0) return false;
		for(int y=x; y<min(m,x+t); ++y)
			sol[bugs[y].n] = pq.top().second+1;
		pq.pop();
	}

	return true;
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> n >> m >> p;

	int M=0, B=0;

	for(int c, x=0; x<m; ++x){
		in >> c;
		bugs.push_back({x,c});
		B = max(B,c);
	}
	for(int c, x=0; x<n; ++x){
		in >> c;
		stus.push_back({x,0,c});
	}
	for(int c, x=0; x<n; ++x){
		in >> c;
		stus[x].p = c;
	}
	for(auto x : stus)
		if(x.p<=p)
			M = max(M,x.a);

	if(M<B){
		out << "NO\n";
		return 0;
	}
	out << "SI\n";
	sort(bugs.begin(), bugs.end());
	sort(stus.begin(), stus.end());
	
	int le=0, ri=m, mi;
	while(ri-le>1){
		mi = (ri+le)/2;
		if(solve(mi)) ri=mi;
		else le=mi;
	}
	solve(ri);
	for(int x=0; x<m; ++x)
		out << sol[x] << " ";
	out << "\n";
	return 0;
}
