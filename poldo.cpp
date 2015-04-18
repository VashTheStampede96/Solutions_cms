#include <fstream>
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
int m, size_w, size_mem=1, W[10005], mem[10005];
bool occ[10005];
int main()
{
  ifstream in("input.txt");
  ofstream out("output.txt");

  in >> m;
  for(int i=0, a; i<m; i++)
    in >> W[i];

  for(int i=0, pos=0; i<m; i++){
    pos=lower_bound(mem,mem+size_mem,W[i], greater<int>() )-mem;
      mem[pos]=W[i];
      if(pos==size_mem) size_mem++;
  }

  out << size_mem << endl;

  return 0;
}
