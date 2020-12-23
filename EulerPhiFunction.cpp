#include<bits/stdc++.h>
using namespace std;

bool Check(long long int N,long long int pos){
    return (bool)(N & (1<<pos));
}
long long int Set(int N,int pos){	return N=N | (1<<pos);}

long long int N =10000000,prime[10000000],po;
long long int status[10000000/32];
void sieve()
{
     int i, j, sqrtN;
     sqrtN = int( sqrt( N ) );
     for( i = 3; i <= sqrtN; i += 2 )
     {
		 if( Check(status[i/32],i%32)==0)
		 {
	 		 for( j = i*i; j <= N; j += 2*i )
			 {
				 status[j/32]=Set(status[j/32],j % 32)   ;
	 		 }
		 }
	 }
	 prime[0]=2;
	 for(i=3,j=1;i<=N;i+=2)
		 if( Check(status[i/32],i%32)==0)
	 	 {
	 	     prime[j]=i;
	 	     j++;
	 	 }
	 	 po=j;
}



long long int EulerPHI(long long int n)
{
    long long int res=n;
    long long int sqrtn=sqrt(n);
    long long int np=po;
    for(int i=0;i<np && prime[i]<=sqrtn;i++)
    {

        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                n=n/prime[i];
            }

            res=res/prime[i];
            res=res*(prime[i]-1);
        }
         sqrtn=sqrt(n);
    }
    if(n!=1)
    {
       res=res/n;
            res=res*(n-1);
    }
    return res;
}


int main()
{
    long long int n;
    scanf("%lld",&n);
    sieve();
    printf("%lld\n",EulerPHI(n));
    return 0;
}
