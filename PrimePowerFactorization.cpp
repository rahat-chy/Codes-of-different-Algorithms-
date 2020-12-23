#include<stdio.h>
#include<math.h>
bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}
long long int Set(int N,int pos){	return N=N | (1<<pos);}

long long int N =1000000,prime[1000000],po;
long long int status[1000000/32];
void sieve()
{
     long long int i, j, sqrtN;
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


long long int p[100];
long long int e[100];
long long int nk=0;
void decomp(long long int n)
{
    nk=0;
    long long int sqrtn=sqrt(n),cnt,i;
    long long int np=po;
    for(i=0;i<np && prime[i]<=sqrtn;i++)
    {

        cnt=0;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                cnt++;
                n=n/prime[i];
            }
        }
        if(cnt>0)
        {
            p[nk]=prime[i];
            e[nk]=cnt;
            nk++;
        }
        sqrtn=sqrt(n);
    }
    if(n!=1)
    {
        p[nk]=n;
        e[nk]=1;
        nk++;
    }
}


int main()
{
    long long int i,n;
    sieve();
    scanf("%lld",&n);
    decomp(n);
    for(i=0;i<nk; i++)
        printf("%lld ^ %lld \n",p[i],e[i]);
    return 0;
}
