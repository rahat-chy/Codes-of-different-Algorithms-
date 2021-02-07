#include<bits/stdc++.h>
using namespace std;

long long int tree[100005];

void update(long long int indx, long long int val, long long int n)
{
    while(indx<=n)
    {
        tree[indx]+=val;
        indx+=(indx & -indx);
    }
}

long long int query(long long int indx)
{
    long long int s=0;
    while(indx>0)
    {
        s+=tree[indx];
        indx-=(indx & -indx);
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //READ("in");
    // cin.tie(NULL);


    long long int n,m;
    cin>>n>>m;
    long long int i,a,b;

    while(m--)
    {
        cin>>a>>b;

        update(a,1,n);

        update(b+1,1,n);

        /*for(i=1;i<=n;i++)
            cout<<tree[i]<<" ";
        cout<<"\n";*/

    }

    cout<<query(1)%2;


    for(i=2; i<=n; i++)
    {

        cout<<" "<<query(i)%2;

    }
    cout<<"\n";


    return 0;
}

