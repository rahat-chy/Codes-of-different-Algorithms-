#include<bits/stdc++.h>
using namespace std;

int phi[200];

void PhiSieve()
{
    for(int i=1;i<=144;i++)
        phi[i]=i;

    for(int i=2;i<=144;i++)
    {
        if(phi[i]==i)
        {
            phi[i]=i-1;
            for(int j=i*2;j<=144;j+=i)
                phi[j]=(phi[j]/i)*(i-1);
        }
    }
}

int main()
{
   PhiSieve();
   for(int i=1;i<=144;i++)
     cout<<i<<" "<<phi[i]<<endl;

     return 0;
}
