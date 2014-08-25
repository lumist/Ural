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
const int MAXN=20017;
const int MAXS=2*MAXN;

//并查集
struct union_find{
  int N,Q;
  int flag;
  int ht[MAXN];
  int par[MAXS+1];
  int rank[MAXS+1];
  
  int Hash(int x){
    int key=x%MAXN;
    //冲突
    while(ht[key]+1){
      //hash查询 否则 hash分配
      if(ht[key]==x)
        return key;
      key=(key+1)%MAXN;
    }
    ht[key]=x;
    return key;
  }
  
  //父结点
  int Find(int x){
    if(x==par[x])
      return x;
    //降高度优化
    return par[x]=Find(par[x]);
  }
  
  //合并x与y所在集合
  void Union(int x,int y){
    x=Find(x);
    y=Find(y);
    if(x==y)
      return;
    
    if(rank[x]<rank[y]){
      par[x]=y;
    }else{
      par[y]=x;
      if(rank[x]==rank[y])
        rank[x]++;
    }
  }
  
  //判断是否同集
  bool Same(int x,int y){
    return Find(x)==Find(y);
  }
  
  void Solve(){
    int m;
    while(cin>>N&&N!=-1){
      flag=1;
      memset(ht,-1,sizeof(ht));
      for(m=0;m<MAXN;m++){
        par[m]=m; //自身
        par[MAXN+m]=m+MAXN; //空集
        rank[m]=rank[MAXN+m]=1;
      }
      cin>>Q;
      for(m=0;m<Q;m++){
        int i,j;
        char result[5];
        scanf("%d%d%s",&i,&j,result);
        if(!flag)
          continue;
        if(result[0]=='e'){
          Union( Hash(i-1) , Hash(j) );
          Union( Hash(i-1) + MAXN , Hash(j) + MAXN );
          if( Find( Hash(i-1) ) == Find( Hash(i-1) + MAXN )  ){
            cout<<m<<endl;
            flag=0;
          }
        }else{
          Union( Hash(i-1) , Hash(j) + MAXN );
          Union( Hash(i-1) + MAXN , Hash(j) );
          if( Find( Hash(i-1) ) == Find( Hash(i-1) + MAXN )  ){
            cout<<m<<endl;
            flag=0;
          }
        }
      }
      if(flag)
        cout<<Q<<endl;
    }
    
  }

}SET;


int main(){
  int i;
  SET.Solve();
}

