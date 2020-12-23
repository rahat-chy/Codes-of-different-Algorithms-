#include<bits/stdc++.h>
using namespace std;

int dp[1000000];


int fibo(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;

    if(dp[n]!=-1)
        return dp[n];


    dp[n]= fibo(n-1)+fibo(n-2);

    return dp[n];
}

int main()
{
    int n;
    memset(dp, -1, 1000000*sizeof(dp[0]));
    cin>>n;
    cout<<fibo(n)<<endl;
    return 0;
}
