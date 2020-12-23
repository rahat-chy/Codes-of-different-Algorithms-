#include<stdio.h>
#include<math.h>
bool Check(long long int N,long long int pos){
    return (bool)(N & (1<<pos));
}
long long int Set(long long int N,long long int pos){	return N=N | (1<<pos);}

long long int N =1000000,prime[1000000];
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
}

int main()
{
    sieve();
    for(int i=0;i<=50;i++)
        printf("%lld\n",prime[i]);
}
