#include<iostream> 
using namespace std;
 
int ary[10][10], completed[10], n, cost=0;
 
void takeInput()
{
  cin >> n;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++){
      cin >> ary[i][j];
      if(ary[i][j] == 0) ary[i][j] = 10000001;
    }
    completed[i]=0;
  }
}
 
int least(int c)
{
  int nc=10000001;
  int min=10000001, kmin;
  for(int i=0; i<n; i++)
  {
    if(ary[c][i] != 0 && completed[i] == 0)
      if(ary[c][i] + ary[i][c] < min)
      {
        min = ary[i][0] + ary[c][i];
        kmin = ary[c][i];
        nc = i;
      }
  }
 
  if(min != 10000001)
    cost += kmin;
  return nc;
}
 
void mincost(int city)
{
  int ncity;
  completed[city]=1;
  ncity = least(city);
  if(ncity == 10000001)
  {
    ncity = 0;
    cost += ary[city][ncity];
    return;
  }
  mincost(ncity);
}
 
int main()
{
  takeInput();
  mincost(0); //passing 0 because starting vertex
  cout << cost << endl;
  return 0;
}
