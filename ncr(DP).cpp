#include<bits/stdc++.h>
using namespace std;

long long int dp[10000][10000];
long long int ncr(long long int n, long long int r)
{
    if(r==1)
        return n;
    if(r==0)
        return 1;
    if(r==n)
        return 1;
    if(dp[n][r]!=-1)
        return dp[n][r];

    dp[n][r]= (ncr(n-1,r-1)+ncr(n-1,r));

    return dp[n][r];
}

int main()
{
    long long int n,r,i,j;
    for(i=0;i<10000;i++)
    {
        for(j=0;j<10000;j++)
            dp[i][j]=-1;

    }
    cin>>n>>r;
    cout<<ncr(n,r)<<endl;
}
