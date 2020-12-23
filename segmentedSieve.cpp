#include<bits/stdc++.h>
using namespace std;

bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}
int Set(int N,int pos){	return N=N | (1<<pos);}

int N =100000000,prime[100000000],j;
int status[100000000/32];
void sieve()
{
     int i, sqrtN;
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

int arr[100001];
int segmentedSieve(int a, int b)
{
    if(a==1)
        a++;
    int sqrtn=sqrt(b);
    memset(arr,0,sizeof(arr));
    for(int i=0;i<j && prime[i]<=sqrtn;i++)
    {
        int p=prime[i];
        int k=p*p;
        if(k<a)
            k=((a+p-1)/p)*p;
        for(;k<=b;k=k+p)
            arr[k-a]=1;
    }
    int res=0;
    for(int i=a;i<=b;i++)
    {

        if(arr[i-a]==0)
            res++;
    }
    return res;
}
int main()
{
    sieve();

    int a,b,c;
    cin>>a>>b;
    c=segmentedSieve(a,b);
    cout<<c<<endl;
    return 0;
}
