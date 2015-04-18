#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct CONTESTANT{
	int  ID,
		 Score,
		 howMany;
    bool Tasks[2005];
} people[2005];

int P, N, T, points[2005];
bool completed;

bool cmp(const CONTESTANT& c1, const CONTESTANT& c2)
{
	if(c1.Score > c2.Score) return true;
	if(c1.Score < c2.Score) return false;
	if(c1.howMany > c2.howMany) return true;
	if(c1.howMany < c2.howMany) return false;
	return c1.ID < c2.ID;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    in >> N >> T >> P;
    for(int i=1; i<=N; i++){
    	people[i].ID = i;
    	for(int j=0; j<T; j++){
    		in >> completed;
    		people[i].Tasks[j] = completed;
    		if(!completed) points[j]++;
    		else people[i].howMany++;
    	}
    }
    for(int i=1; i<=N; i++){
    	for(int j=0; j<T; j++){
    		if(people[i].Tasks[j]) people[i].Score += points[j];
    	}
    }
    
    sort(people+1, people+N+1, cmp);
    
    int i=1;
    while(people[i].ID != P) i++;
    
    out << people[i].Score << ' ' << i << endl;
    
    return 0;
}
