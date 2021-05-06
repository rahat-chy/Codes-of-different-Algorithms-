#include <bits/stdc++.h>
using namespace std;

long long int egcd(long long int a, long long int b , long long int &x , long long int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    long long int x1,y1;
    long long int d= egcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}

/*long long int crt(long long int a1, long long int m1 , long long int a2, long long int m2 , long long int mod)
{
    long long int x,y;
    long long int b=egcd(m1,m2,x,y);
    //cout<<b<<"\n";


    return ((a1*m2*y)%mod+(a2*m1*x)%mod)%mod;
}*/

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   long long int i,j,k,a,b,c,n,t,tc=1;
   cin>>t;
   while(t--){
   cin>>n;
   long long int remainder[n],modulos[n];
   for(i=0;i<n;i++)
   {
       cin>>modulos[i]>>remainder[i];
   }
   k=1;
   c=0;
   for(i=0;i<n;i++)
   {
       k*=modulos[i];
   }


   for(i=0;i<n;i++)
   {
       a=k/modulos[i];
       long long int x,y;
       egcd(a,modulos[i],x,y);
       c=((c%k)+(remainder[i]*x*a)%k)%k;
       if(c<0)
        c+=k;
   }


   cout<<"Case "<<tc<<": "<<c<<"\n";
   tc++;
   }

   return 0;
}
