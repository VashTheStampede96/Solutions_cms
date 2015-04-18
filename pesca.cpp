#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXP=1000005;

struct MAT{
	int i, j, pos;
}Pi[MAXP], Pj[MAXP], att, start, end;

int P, c, h;
bool occ[MAXP];

bool cmp1(const MAT&, const MAT&);
bool cmp2(const MAT&, const MAT&);
void sit1();
void sit2();

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d %d %d", &P, &start.i, &start.j);
	att=start;
	for(int i=0; i<P; i++){
		scanf("%d %d", &(Pj[i].i), &(Pj[i].j));
		Pj[i].pos=i;
		Pi[i]=Pj[i];
	}
	
	sort(Pi,Pi+P,cmp1);
	sort(Pj,Pj+P,cmp2);
	
	scanf("%d", &c);
	
	if(c>0) sit1();
	else sit2();
	
	for(h=0; h<P; h++)
			 if(!occ[h])
 			     c++;
	
	printf("%d\n", c);
	
	return 0;
}

bool cmp1(const MAT &m1, const MAT &m2)
{
	if(m1.i!=m2.i) return m1.i<m2.i;
	return m1.j>m2.j;
}

bool cmp2(const MAT &m1, const MAT &m2)
{
	if(m1.j!=m2.j) return m1.j<m2.j;
	return m1.i>m2.i;
}

void sit1()
{
	for(h=0; h<P && Pi[h].i<att.i; h++)
			 occ[ Pi[h].pos ]=true;
    
    while(c!=0){
    	if(c>0) att.j+=c;
		else{
			att.i-=c;
			while(h<P && Pi[h].i<att.i){
				if(Pi[h].j>att.j)
			 	         occ[ Pi[h].pos ]=true;
				h++;
			}
		}
		scanf("%d", &c);
    }
    
    for(h; h<P; h++)
		if(Pi[h].i>att.i || (Pi[h].i==att.i && Pi[h].j>att.j))
			occ[ Pi[h].pos ]=true;
	
	att=start;
	
	for(h=0; h<P && Pj[h].j<att.j; h++)
			 occ[ Pj[h].pos ]=true;
 
    do{
		scanf("%d", &c);
		if(c>0){
			att.j+=c;
			while(h<P && Pj[h].j<att.j){
				if(Pj[h].i>att.i)
			 	         occ[ Pj[h].pos ]=true;
				h++;
			}
		}
		else att.i-=c;
	}while(c!=0);
	
	return;
}

void sit2()
{
	for(h=0; h<P && Pj[h].j<att.j; h++)
			 occ[ Pj[h].pos ]=true;
    
    while(c!=0){
    	if(c>0){
			att.j+=c;
			while(h<P && Pj[h].j<att.j){
				if(Pj[h].i>att.i)
			 	         occ[ Pj[h].pos ]=true;
				h++;
			}
		}
		else att.i-=c;
		scanf("%d", &c);
    }
    
    att=start;
    
    for(h=0; h<P && Pi[h].i<att.i; h++)
			 occ[ Pi[h].pos ]=true;
			 
    do{
    	scanf("%d", &c);
    	if(c>0) att.j+=c;
		else{
			att.i-=c;
			while(h<P && Pi[h].i<att.i){
				if(Pi[h].j>att.j)
			 	         occ[ Pi[h].pos ]=true;
				h++;
			}
		}
    }while(c!=0);
    
    for(h; h<P; h++)
		if(Pi[h].i>att.i || (Pi[h].i==att.i && Pi[h].j>att.j))
			occ[ Pi[h].pos ]=true;
	
	return;
}
