#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct NODO{
	bool isWord, ordina;
	int len;
	char C;
	vector<NODO> sons;
};

bool cmp(const NODO &n1, const NODO &n2){ return n1.len<n2.len; }

void addWord(NODO&,int);
bool solve(NODO&);

int N, L, stampe, Oper;
string s;
NODO Root;

int main()
{
	in >> N;
	
	for(int i=0; i<N; i++){
		in >> s;
		addWord(Root,0);
	}
	
	Root.ordina=true;
	
	out << "                 \n";
	solve(Root);
	out.seekp(0,ios::beg);
	out << Oper;
	
	return 0;
}

void addWord(NODO &p, int n)
{
	if(n==s.length()){
		p.isWord=true;
		return;
	}
	
	char c=s[n];
	int last=0;
	for(int i=0; i<p.sons.size(); i++){
		if(p.sons[i].C==c) break;
		else last++;
	}
	if(last==p.sons.size()){
		NODO node;
		node.ordina=node.isWord=false;
		node.len=0;
		node.C=s[n];
		p.sons.push_back(node);
	}
	p.sons[last].len=max(p.sons[last].len, (int)s.length()-n);
    addWord(p.sons[last],n+1);
	
	return;
}

bool solve(NODO &r)
{
	if(r.C!=0){
		Oper++;
		out << r.C << endl;
	}
	if(r.isWord){
		out << "P\n";
		stampe++;
		Oper++;
		if(stampe==N) return true;
	}
	
	if(r.ordina){
		nth_element( r.sons.begin(), r.sons.end()-1, r.sons.end(), cmp );
		if(!r.sons.empty()) r.sons.back().ordina=true;
	}
	
	bool res=false;
	
	for(int i=0; i<r.sons.size(); i++)
			res=solve(r.sons[i]);
	
	if(!res){
		Oper++;
		out << "-\n";
	}
	
	return res;
}
