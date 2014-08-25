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
#include <math.h>
#define MIN(x,y) (x)>(y)?(y):(x)
#define MAX(x,y) (x)<(y)?(y):(x)
#define EPS 1e-9
//typedef long long int ll;
using namespace std;
const int MAXN=50000;
const int MAXNL=101;

int hash[26];
string number;
int N;
int dp[MAXNL];
int index[MAXNL];
string words[MAXN],trans[MAXN];

bool isequal(int start,int no){
  int i;
  if(words[no].length()-1+start>=number.length())
    return false;
  for(i=start;i<start+words[no].length();i++){
    if(trans[no][i-start]!=number[i])
      return false;
  }
  return true;
}

void solve(){
  int i,j;
  vector<int> vec[MAXN];
  for(i=0;i<N;i++){
    trans[i]="";
    for(j=0;j<words[i].length();j++)
      trans[i]+='0'+hash[words[i][j]-'a'];
  }
  
  //建图
  for(i=0;i<number.length();i++){
    for(j=0;j<N;j++){
      if(isequal(i,j))
        vec[i].push_back(j);
    }
  }
  
  //倒推DP
  //number串后加1个空格
  int relength=number.length();
  number+=' ';
  memset(dp,0,sizeof(dp));
  for( i=relength-1; i>=0 ; i--){
    if( dp[i]>50000 || vec[i].empty() )
      dp[i]=50001;
    else{
      vector<int>::iterator it=vec[i].begin();
      for(;it!=vec[i].end();it++){
        if(dp[i]){
          if( dp[ i + words[ *it ].length() ] + 1 < dp[i] ){
            dp[i] = dp[ i + words[ *it ].length() ] + 1;
            index[i]=*it;
          }
        }
        else{
          dp[i] = dp[ i + words[ *it ].length() ] + 1;
          index[i]=*it;
        }
      }
    }
  }
  
  if(dp[0] && dp[0]<=50000){
    int s=0;
    while(dp[0]--){
      cout<<words[index[s]];
      if(dp[0])
        cout<<' ';
      s+=words[index[s]].length();
    }
    cout<<endl;
  }
  else
    cout<<"No solution."<<endl;
}

int main(){
  int i;
  for(i=0;i<=26;i++){
    if(i<=13&&i>=0)
      hash[i]=2+i/3;
    else if(i>=17&&i<=24)
      hash[i]=7+(i-16)/3;
  }
  hash['i'-'a']=hash['j'-'a']=1;
  hash['o'-'a']=hash['q'-'a']=hash['z'-'a']=0;
  hash['p'-'a']=7;
   
  while(cin>>number&&number!="-1"){
    cin>>N;
    for(i=0;i<N;i++)
      cin>>words[i];
    solve();
  }
  
}

