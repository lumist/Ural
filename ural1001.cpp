#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <limits.h>
#define MIN(x,y) (x)>(y)?(y):(x)
#define MAX(x,y) (x)<(y)?(y):(x)
#define EPS 1e-9
typedef long long int ll;
using namespace std;


double SQRT(ll num){
  double l=0.0;
  double r=num;
  double m;
  while(r-l>1e-6){
    m=(r+l)/2;
    if(m*m-num<=EPS)
      l=m;
    else
      r=m;
  }
  return l;
}

int main(){
  int i,j,k;
  long long int num;
  stack<double> sta;
  while(cin>>num)
    sta.push(SQRT(num));
  while(!sta.empty()){
    printf("%.4lf\n",sta.top());
    sta.pop();
  }
}