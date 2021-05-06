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

long long int crt(long long int a1, long long int m1 , long long int a2, long long int m2 , long long int mod)
{
    long long int x,y;
    long long int b=egcd(m1,m2,x,y);

    return ((a1*m2*y)+(a2*m1*x))%(m1*m2);
}

int main()
{
   long long int i,j,k,a,b,c,n;
   cin>>n;
   long long int remainder[n],modulos[n];
   for(i=0;i<n;i++)
   {
       cin>>remainder[i]>>modulos[i];
   }
   k=modulos[0];
   k*=modulos[1];
   c=crt(remainder[0],modulos[0],remainder[1],modulos[1],k);
  // cout<<c<<"\n";
   for(i=2;i<n;i++)
   {
       c=crt(c,k,remainder[i],modulos[i],k*modulos[i]);
       k*=modulos[i];
   }
   cout<<c<<"\n";

   return 0;
}
