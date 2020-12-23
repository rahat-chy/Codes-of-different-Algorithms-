#include<bits/stdc++.h>
using namespace std;

long long int dp[1000][1000];

long long int n;

long long int capacity;
long long int cost[1000],weight[1000];

long long int knapsack(long long int i,long long int w){

  long long int p=0,q=0;

  if(i==n+1)
    return 0;

  if(dp[i][w]!=-1)
    return dp[i][w];


  else{
    if(w+weight[i]<=capacity){
            p=cost[i]+knapsack(i+1,w+weight[i]);

    }

    q=knapsack(i+1,w);

    dp[i][w]=max(p,q);

    return dp[i][w];



  }
}

int main(){
memset(dp,-1,sizeof(dp));

cin>>n>>capacity;

for(int i=1;i<=n;i++){
    cin>>weight[i]>>cost[i];
}

cout<<knapsack(1,0)<<endl;
return 0;
}
