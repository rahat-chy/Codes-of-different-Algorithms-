#include<bits/stdc++.h>
using namespace std;

long long int bigMOD(long long int b, long long p, long long int m)
{
    if(p==0ll)
        return 1ll%m;
    if(p%2==0)
    {
        long long int y=bigMOD(b,p/2,m);
        return (y*y)%m;
    }
    else
    {
        return (b*bigMOD(b,p-1,m))%m;
    }
}

int main()
{
    long long int i,f=1,b,p,m;
    cin>>b>>p>>m;

    cout<<bigMOD(b,p,m)<<"\n";

    return 0;
}

