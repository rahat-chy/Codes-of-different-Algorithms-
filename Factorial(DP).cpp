#include<bits/stdc++.h>
using namespace std;

int dp[1000000];


int fact(int n)
{
    if(n==0)
        return 1;
    if(n==1)
        return 1;

    if(dp[n]!=-1)
    return dp[n];

    dp[n]=n*fact(n-1);

    return dp[n];
}

int main()
{
    int n;
    memset(dp, -1, 1000000*sizeof(dp[0]));
    cin>>n;
    cout<<fact(n)<<endl;

    return 0;
}
