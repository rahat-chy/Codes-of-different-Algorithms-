#include<bits/stdc++.h>
using namespace std;

long long int bigMODRSM(long long int b, long long p, long long int m)
{
    long long int res=1%m,x=b%m;
    while(p)
    {
        if(p&1)
          res=(res*x)%m;

        x=(x*x)%m;
        p>>=1;

    }
    return res;
}

int main()
{
    long long int i,f=1,b,p,m;
    cin>>b>>p>>m;

    cout<<bigMODRSM(b,p,m)<<"\n";

    return 0;
}

